/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_63. Max Profit.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/04 9:26:00
 * @brief 剑指offer第63题 股票的最大收益
 * */

#ifndef INC_1STPROGRAM_OFFER_63_MAX_PROFIT_H
#define INC_1STPROGRAM_OFFER_63_MAX_PROFIT_H

#include "../util/header_util.h"

std::pair<int, int> max_profit(std::vector<int> &prices, bool print_debug = true) {
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

int maxProfit(vector<int> &prices) {
    int max_profit = 0;
    if (prices.empty()) {
        return max_profit;
    }
    for (int i = 1; i < prices.size(); ++i) {
        int temp_result = prices[i] - prices[i - 1];
        if (temp_result > 0) {
            max_profit += temp_result;
        }
    }
    return max_profit;
}

void test_max_profit() {
    std::vector<int> prices = {9, 11, 8, 5, 7, 12, 16, 14};
    std::pair<int, int> result = max_profit(prices);
    int result_2 = max_profit_v2(prices);
}

#endif //INC_1STPROGRAM_OFFER_63_MAX_PROFIT_H
