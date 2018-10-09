/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_13. Rod Cut.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/25 20:35:00
 * @brief 算法导论动态规划第一题，切钢条
 * */

#ifndef INC_1STPROGRAM_COMMON_13_ROD_CUT_H
#define INC_1STPROGRAM_COMMON_13_ROD_CUT_H

#include "../util/header_util.h"

int rod_cut(std::vector<int>& prices, int length) {
    if (prices.empty() || length <= 0) {
        return 0;
    }
    std::vector<int> dp(length + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= length; ++i) {
        int Max = INT_MIN;
        for (int j = 1; j <= i; ++j) {
            Max = std::max(Max, prices[j] + dp[i - j]);
        }
        dp[i] = Max;
    }
    return dp[length];
}

void test_rod_cut() {
    std::vector<int> prices = {0,1,5,8,9,10,17,17,20,24,30};
    int result = rod_cut(prices, 5);
}
#endif //INC_1STPROGRAM_COMMON_13_ROD_CUT_H
