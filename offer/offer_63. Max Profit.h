// Created by Li,Yang(Duer04) on 2018/9/4.
// Author: liyang
//
// 股票的最大收益

#ifndef INC_1STPROGRAM_OFFER_63_MAX_PROFIT_H
#define INC_1STPROGRAM_OFFER_63_MAX_PROFIT_H

#include <iostream>
#include <vector>

std::pair<int, int> max_profit(std::vector<int>& prices, bool print_debug=true) {
    if (prices.empty()) {
        return {-1, -1};
    }
    int Min = prices[0];
    int begin = 0;
    int left = -1;
    int right = -1;
    int profit = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < Min) {
            Min = prices[i];
            begin = i;
            if (print_debug) {
                std::cout << "getting min" << " " << begin << std::endl;
            }
        }
        if (prices[i] - Min > profit) {
            profit = prices[i] - Min;
            left = begin;
            right = i;
            if (print_debug) {
                std::cout << "getting bound" << " " << left << " " << right << std::endl;
            }
        }
    }
    return {left, right};
};

int max_profit_v2(std::vector<int>& prices, bool print_debug=true) {
    // 允许多次买卖
    if (prices.size() <= 1) {
        return 0;
    }
    int max_profit = 0;
    int temp = prices[0];
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (prices[i] > prices[i + 1]) {
            max_profit += prices[i] - temp;
            temp = prices[i + 1];
        }
    }
    return max_profit;
}

void test_max_profit() {
    std::vector<int> prices = {9, 11, 8, 5,7, 12, 16, 14};
    std::pair<int, int> result = max_profit(prices);
    int result_2 = max_profit_v2(prices);
}

#endif //INC_1STPROGRAM_OFFER_63_MAX_PROFIT_H
