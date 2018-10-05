// Created by Administrator on 2018/9/9.
// Author: liyang
//
// coin change

/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_200. Number of Islands.h
 * @author liyang921126@gmail.com
 * @date 2018/09/09 11:10:00
 * @brief leetcode 200
 * @link https://leetcode.com/problems/coin-change/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_322_COIN_CHANGE_H
#define INC_1STPROGRAM_LEETCODE_322_COIN_CHANGE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0) {
            return -1;
        }
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < coins.size(); ++j) {
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
#endif //INC_1STPROGRAM_LEETCODE_322_COIN_CHANGE_H
