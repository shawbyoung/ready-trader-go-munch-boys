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

void AutoTrader::OrderBookMessageHandler(Instrument instrument,
                                         unsigned long sequenceNumber,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& askPrices,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& askVolumes,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& bidPrices,
                                         const std::array<unsigned long, TOP_LEVEL_COUNT>& bidVolumes)
{
    RLOG(LG_AT, LogLevel::LL_INFO) << "order book received for " << instrument << " instrument"
                                   << ": ask prices: " << askPrices[0]
                                   << "; ask volumes: " << askVolumes[0]
                                   << "; bid prices: " << bidPrices[0]
                                   << "; bid volumes: " << bidVolumes[0];

    if (instrument == Instrument::FUTURE)
    {
        unsigned long priceAdjustment = - (mPosition / LOT_SIZE) * TICK_SIZE_IN_CENTS;
        unsigned long newAskPrice = (askPrices[0] != 0) ? askPrices[0] + priceAdjustment : 0;
        unsigned long newBidPrice = (bidPrices[0] != 0) ? bidPrices[0] + priceAdjustment : 0;


        // Updates the last futures bid and ask prices
        if ( bidPrices[0] != 0 ) { 
            last_future_bid_price = bidPrices[0];
        }

        if ( askPrices[0] != 0 ) { 
            last_future_ask_price = askPrices[0];
        }

        // Handles edge case, early game when bid xor ask 
        if ( last_future_ask_price == 0 ) { 
            last_future_mid_price = last_future_bid_price; 
        }

        if ( last_future_bid_price == 0 ) { 
            last_future_mid_price = last_future_ask_price;
        }

        // STD explosion 
        if (last_future_mid_price != 0 && last_etf_bid_price != 0 && spread_stats.std() != 0) {

            unsigned long spread = last_future_mid_price > last_etf_mid_price ? 
            last_future_mid_price - last_etf_mid_price :  last_etf_mid_price - last_future_mid_price;        
 
            unsigned long standard_dev = spread_stats.mean() > spread ?
            (spread_stats.mean() - spread)/2 : (spread - spread_stats.mean())/2; 

            if ( standard_dev > 1 ) { 
                if ( last_future_mid_price > last_etf_mid_price ) { 
                    mBidId = mNextMessageId++;
                    mBidPrice = newBidPrice;
                    SendInsertOrder(mBidId, Side::BUY, newBidPrice, LOT_SIZE, Lifespan::GOOD_FOR_DAY);
                    mBids.emplace(mBidId);
                }

                if ( last_future_mid_price < last_etf_mid_price ) { 

                    mAskId = mNextMessageId++;
                    mAskPrice = newAskPrice;
                    SendInsertOrder(mAskId, Side::SELL, newAskPrice, LOT_SIZE, Lifespan::GOOD_FOR_DAY);
                    mAsks.emplace(mAskId);
                }
            }

            spread_stats.push(spread);
        }

    




        // if (mAskId != 0 && newAskPrice != 0 && newAskPrice != mAskPrice)
        // {
        //     SendCancelOrder(mAskId);
        //     mAskId = 0;
        // }
        // if (mBidId != 0 && newBidPrice != 0 && newBidPrice != mBidPrice)
        // {
        //     SendCancelOrder(mBidId);
        //     mBidId = 0;
        // }


         // if (mAskId == 0 && newAskPrice != 0 && mPosition > -POSITION_LIMIT)
        // {
        //     mAskId = mNextMessageId++;
        //     mAskPrice = newAskPrice;
        //     SendInsertOrder(mAskId, Side::SELL, newAskPrice, LOT_SIZE, Lifespan::GOOD_FOR_DAY);
        //     mAsks.emplace(mAskId);
        // }
        // if (mBidId == 0 && newBidPrice != 0 && mPosition < POSITION_LIMIT)
        // {
        //     mBidId = mNextMessageId++;
        //     mBidPrice = newBidPrice;
        //     SendInsertOrder(mBidId, Side::BUY, newBidPrice, LOT_SIZE, Lifespan::GOOD_FOR_DAY);
        //     mBids.emplace(mBidId);
        // }
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
