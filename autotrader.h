// Copyright 2021 Optiver Asia Pacific Pty. Ltd.
//
// This file is part of Ready Trader Go.
//
//     Ready Trader Go is free software: you can redistribute it and/or
//     modify it under the terms of the GNU Affero General Public License
//     as published by the Free Software Foundation, either version 3 of
//     the License, or (at your option) any later version.
//
//     Ready Trader Go is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Affero General Public License for more details.
//
//     You should have received a copy of the GNU Affero General Public
//     License along with Ready Trader Go.  If not, see
//     <https://www.gnu.org/licenses/>.
#ifndef CPPREADY_TRADER_GO_AUTOTRADER_H
#define CPPREADY_TRADER_GO_AUTOTRADER_H

#include <array>
#include <memory>
#include <string>
#include <unordered_set>
#include <boost/asio/io_context.hpp>
#include <ready_trader_go/baseautotrader.h>
#include <ready_trader_go/types.h>
#include <cmath>
#include <deque>





class RunningStats { 
public:

    void push(unsigned long num) {

        if ( data.size() < n ) { 
            data.push_back(num);

            new_m = (num + old_m*(data.size()-1))/data.size();
            new_s = old_s + (num - old_m)*(num - new_m);
        }

        else {
            double front = data.front();
            data.pop_front();
            data.push_back(num);

            new_m = (num + old_m*n - front)/100;
            new_s = old_s + (num - old_m)*(num - new_m) - (front - old_m)*(front - new_m) ;
        }

        old_m = new_m;
        old_s = new_s;
    }

    double std_hard_moded() {
        double sum = 0; 
        for (double d : data) { 
            sum += pow((d - new_m),2);
        }

        return sqrt(sum/data.size());

    }


    double mean() { 
        return new_m;
    }

    double variance() { 
        return data.size() > 1 ? new_s / (data.size() - 1) : 0;
    }

    double std() { 
        return sqrt(variance());
    }

private:

    std::deque<double> data;

    size_t n = 100;

    double old_m = 0;
    double new_m = 0;
    double old_s = 0;
    double new_s = 0;


};


class AutoTrader : public ReadyTraderGo::BaseAutoTrader
{
public:
    explicit AutoTrader(boost::asio::io_context& context);

    // Called when the execution connection is lost.
    void DisconnectHandler() override;

    // Called when the matching engine detects an error.
    // If the error pertains to a particular order, then the client_order_id
    // will identify that order, otherwise the client_order_id will be zero.
    void ErrorMessageHandler(unsigned long clientOrderId,
                             const std::string& errorMessage) override;

    // Called when one of your hedge orders is filled, partially or fully.
    //
    // The price is the average price at which the order was (partially) filled,
    // which may be better than the order's limit price. The volume is
    // the number of lots filled at that price.
    //
    // If the order was unsuccessful, both the price and volume will be zero.
    void HedgeFilledMessageHandler(unsigned long clientOrderId,
                                   unsigned long price,
                                   unsigned long volume) override;

    // Called periodically to report the status of an order book.
    // The sequence number can be used to detect missed or out-of-order
    // messages. The five best available ask (i.e. sell) and bid (i.e. buy)
    // prices are reported along with the volume available at each of those
    // price levels.
    void OrderBookMessageHandler(ReadyTraderGo::Instrument instrument,
                                 unsigned long sequenceNumber,
                                 const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& askPrices,
                                 const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& askVolumes,
                                 const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& bidPrices,
                                 const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& bidVolumes) override;

    // Called when one of your orders is filled, partially or fully.
    void OrderFilledMessageHandler(unsigned long clientOrderId,
                                   unsigned long price,
                                   unsigned long volume) override;

    // Called when the status of one of your orders changes.
    // The fill volume is the number of lots already traded, remaining volume
    // is the number of lots yet to be traded and fees is the total fees paid
    // or received for this order.
    // Remaining volume will be set to zero if the order is cancelled.
    void OrderStatusMessageHandler(unsigned long clientOrderId,
                                   unsigned long fillVolume,
                                   unsigned long remainingVolume,
                                   signed long fees) override;

    // Called periodically when there is trading activity on the market.
    // The five best ask (i.e. sell) and bid (i.e. buy) prices at which there
    // has been trading activity are reported along with the aggregated volume
    // traded at each of those price levels.
    // If there are less than five prices on a side, then zeros will appear at
    // the end of both the prices and volumes arrays.
    void TradeTicksMessageHandler(ReadyTraderGo::Instrument instrument,
                                  unsigned long sequenceNumber,
                                  const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& askPrices,
                                  const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& askVolumes,
                                  const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& bidPrices,
                                  const std::array<unsigned long, ReadyTraderGo::TOP_LEVEL_COUNT>& bidVolumes) override;



    // Updates the spread info - e.g. last future bid price, last future ask price, mid price, etc, returns std of current spread 
    double UpdateSpreadInfo(ReadyTraderGo::Instrument instrument, unsigned long bid_price, unsigned long ask_price );


private:
    unsigned long mNextMessageId = 1;
    unsigned long mAskId = 0;
    unsigned long mAskPrice = 0;
    unsigned long mBidId = 0;
    unsigned long mBidPrice = 0;
    signed long mPosition = 0;



    std::unordered_set<unsigned long> mAsks;
    std::unordered_set<unsigned long> mBids;

    // Holds order ID as well as 
    // std::priority_queue<std::tuple<unsigned long, /*time data*/ > order_ids_x_time; 

    unsigned long last_etf_mid_price = 0;
    unsigned long last_etf_bid_price = 0;
    unsigned long last_etf_ask_price = 0;

    unsigned long last_future_mid_price = 0;
    unsigned long last_future_bid_price = 0; 
    unsigned long last_future_ask_price = 0;

    unsigned long last_spread = 0;
    RunningStats spread_stats;


    // Helper methods
    // bool CanPlaceOrders() { }
};
#endif //CPPREADY_TRADER_GO_AUTOTRADER_H
