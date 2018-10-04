// Created by Administrator on 2018/9/9.
// Author: liyang
//
// coin change

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
