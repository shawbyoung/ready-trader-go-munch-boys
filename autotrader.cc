#include <array>
#include <cmath>

#include <boost/asio/io_context.hpp>

#include <ready_trader_go/logging.h>

#include "autotrader.h"

using namespace ReadyTraderGo;

RTG_INLINE_GLOBAL_LOGGER_WITH_CHANNEL(LG_AT, "AUTO")

constexpr int LOT_SIZE = 10;
constexpr int POSITION_LIMIT = 100;
constexpr int TICK_SIZE_IN_CENTS = 100;
constexpr int MIN_BID_NEARST_TICK = (MINIMUM_BID + TICK_SIZE_IN_CENTS) / TICK_SIZE_IN_CENTS * TICK_SIZE_IN_CENTS;
constexpr int MAX_ASK_NEAREST_TICK = MAXIMUM_ASK / TICK_SIZE_IN_CENTS * TICK_SIZE_IN_CENTS;

// Pairs trading - uses standard deviation to make orders

AutoTrader::AutoTrader(boost::asio::io_context& context) : BaseAutoTrader(context)
{
}

void AutoTrader::DisconnectHandler()
{
    BaseAutoTrader::DisconnectHandler();
    RLOG(LG_AT, LogLevel::LL_INFO) << "execution connection lost";
}

void AutoTrader::ErrorMessageHandler(unsigned long clientOrderId,
                                     const std::string& errorMessage)
{
    RLOG(LG_AT, LogLevel::LL_INFO) << "error with order " << clientOrderId << ": " << errorMessage;
    if (clientOrderId != 0 && ((mAsks.count(clientOrderId) == 1) || (mBids.count(clientOrderId) == 1)))
    {
        OrderStatusMessageHandler(clientOrderId, 0, 0, 0);
    }
}

void AutoTrader::HedgeFilledMessageHandler(unsigned long clientOrderId,
                                           unsigned long price,
                                           unsigned long volume)
{
    RLOG(LG_AT, LogLevel::LL_INFO) << "hedge order " << clientOrderId << " filled for " << volume
                                   << " lots at $" << price << " average price in cents";
}

double AutoTrader::UpdateSpreadInfo(Instrument instrument, unsigned long bid_price, unsigned long ask_price ) { 

    if ( instrument == Instrument::FUTURE ) { 
        last_future_bid_price = bid_price;
        last_future_ask_price = ask_price;

        if ( last_future_ask_price == 0 && last_future_bid_price != 0 ) { 
            last_future_mid_price = last_future_bid_price;           
        }

        if ( last_future_ask_price != 0 && last_future_bid_price == 0 ) { 
            last_future_mid_price = last_future_ask_price;           
        }

        else { 
            last_future_mid_price = (last_future_ask_price + last_future_bid_price) / 2;
        }
    }

    if ( instrument == Instrument::ETF ) { 
        last_etf_bid_price = bid_price;
        last_etf_ask_price = ask_price;

        if ( last_etf_ask_price == 0 && last_etf_bid_price != 0 ) { 
            last_etf_mid_price = last_etf_bid_price;           
        }

        if ( last_etf_ask_price != 0 && last_etf_bid_price == 0 ) { 
            last_etf_mid_price = last_etf_ask_price;           
        }

        else { 
            last_etf_mid_price = (last_etf_ask_price + last_etf_bid_price) / 2;
        }
        RLOG(LG_AT, LogLevel::LL_INFO) << "Spread Info Updated - last future mid price: " << last_future_mid_price << "; last etf mid price:" << last_etf_mid_price;
    }

    double standard_dev = 0;

    if (last_future_mid_price != 0 && last_etf_bid_price != 0) { 

        double spread = last_future_mid_price > last_etf_mid_price ? 
        static_cast<double>( (last_future_mid_price - last_etf_mid_price)) : static_cast<double>((last_etf_mid_price - last_future_mid_price));

        double std_gang = spread_stats.std_hard_moded();
        if ( std_gang != 0  ) { 
            standard_dev = spread_stats.mean() > spread ? 
            (spread_stats.mean() - spread)/ std_gang : (spread - spread_stats.mean())/std_gang; 
        }

        spread_stats.push(spread);
    }

    return standard_dev; 
}

void AutoTrader::OrderBookMessageHandler(Instrument instrument,
                                         unsigned long sequenceNumber,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& askPrices,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& askVolumes,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& bidPrices,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& bidVolumes)
{
    
    double standard_dev = UpdateSpreadInfo(instrument, bidPrices[0], askPrices[0]);

    RLOG(LG_AT, LogLevel::LL_INFO) << "order book received for " << instrument << " instrument"
                                   << ": ask prices: " << askPrices[0]
                                   << "; ask volumes: " << askVolumes[0]
                                   << "; bid prices: " << bidPrices[0]
                                   << "; bid volumes: " << bidVolumes[0]
                                   << "; standard_dev: " << std::to_string(standard_dev);

    if (mAskId != 0 && askPrices[0] != 0 && askPrices[0] != mAskPrice) {
        SendCancelOrder(mAskId);
        mAskId = 0;
    }

    if (mBidId != 0 && bidPrices[0] != 0 && bidPrices[0] != mBidPrice) {
        SendCancelOrder(mBidId);
        mBidId = 0;
    }


    if ( standard_dev > 1 ) { 
        if ( last_future_mid_price > last_etf_mid_price && mPosition < POSITION_LIMIT ) { 
            mBidId = mNextMessageId++;
            mBidPrice = bidPrices[0]+TICK_SIZE_IN_CENTS;
            SendInsertOrder(mBidId, Side::BUY, bidPrices[0]+TICK_SIZE_IN_CENTS, LOT_SIZE, Lifespan::GOOD_FOR_DAY);
            mBids.emplace(mBidId);
        }

        if ( last_future_mid_price < last_etf_mid_price && mPosition > -POSITION_LIMIT ) { 

            mAskId = mNextMessageId++;
            mAskPrice = askPrices[0]-TICK_SIZE_IN_CENTS;
            SendInsertOrder(mAskId, Side::SELL, askPrices[0]-TICK_SIZE_IN_CENTS, LOT_SIZE, Lifespan::GOOD_FOR_DAY);
            mAsks.emplace(mAskId);
        }  
    }
}


void AutoTrader::OrderFilledMessageHandler(unsigned long clientOrderId,
                                           unsigned long price,
                                           unsigned long volume)
{
    RLOG(LG_AT, LogLevel::LL_INFO) << "order " << clientOrderId << " filled for " << volume
                                   << " lots at $" << price << " cents";
    if (mAsks.count(clientOrderId) == 1)
    {
        mPosition -= (long)volume;
        SendHedgeOrder(mNextMessageId++, Side::BUY, MAX_ASK_NEAREST_TICK, volume);
    }
    else if (mBids.count(clientOrderId) == 1)
    {
        mPosition += (long)volume;
        SendHedgeOrder(mNextMessageId++, Side::SELL, MIN_BID_NEARST_TICK, volume);
    }
}

void AutoTrader::OrderStatusMessageHandler(unsigned long clientOrderId,
                                           unsigned long fillVolume,
                                           unsigned long remainingVolume,
                                           signed long fees)
{

    RLOG(LG_AT, LogLevel::LL_INFO) << "OrderStatusMessageHandler called";
    if (remainingVolume == 0)
    {
        if (clientOrderId == mAskId)
        {
            mAskId = 0;
        }
        else if (clientOrderId == mBidId)
        {
            mBidId = 0;
        }

        mAsks.erase(clientOrderId);
        mBids.erase(clientOrderId);
    }
}

void AutoTrader::TradeTicksMessageHandler(Instrument instrument,
                                          unsigned long sequenceNumber,
                                          const std::array<unsigned long, TOP_LEVEL_COUNT>& askPrices,
                                          const std::array<unsigned long, TOP_LEVEL_COUNT>& askVolumes,
                                          const std::array<unsigned long, TOP_LEVEL_COUNT>& bidPrices,
                                          const std::array<unsigned long, TOP_LEVEL_COUNT>& bidVolumes)
{
    RLOG(LG_AT, LogLevel::LL_INFO) << "trade ticks received for " << instrument << " instrument"
                                   << ": ask prices: " << askPrices[0]
                                   << "; ask volumes: " << askVolumes[0]
                                   << "; bid prices: " << bidPrices[0]
                                   << "; bid volumes: " << bidVolumes[0];
}
