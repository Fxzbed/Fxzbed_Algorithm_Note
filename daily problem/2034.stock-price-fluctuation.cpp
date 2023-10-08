#include "Fxzbed_algorithms.hpp"
using namespace std;
/*
 * @lc app=leetcode id=2034 lang=cpp
 * words: stock corresponding volatile previous 
 * [2034] Stock Price Fluctuation 
 */

// @lc code=start
class StockPrice {
public:
    StockPrice() {
        maxTimeStamp = 0;
        stockMap.clear();
        priceSet.clear();
    }
    
    void update(int timestamp, int price) {
        maxTimeStamp = timestamp >= maxTimeStamp ? timestamp : maxTimeStamp;
        bool isUpdate = stockMap.count(timestamp) > 0 ? true : false;
        if (isUpdate) {
            auto updatePrice = priceSet.find(stockMap[timestamp]);
            if (updatePrice != priceSet.end())
                priceSet.erase(updatePrice);
        }
        stockMap[timestamp] = price;
        priceSet.emplace(price);
    }
    
    int current() {
        return stockMap[maxTimeStamp];
    }
    
    int maximum() {
        return *priceSet.rbegin();

    }
    
    int minimum() {
        return *priceSet.begin();
    }

private:
    int maxTimeStamp;
    unordered_map<int, int> stockMap;
    multiset<int> priceSet;
};
/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end


