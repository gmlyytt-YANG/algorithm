// Created by Li,Yang(Duer04) on 2018/8/29.
// Author: liyang
//
// 给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘积是多少

#ifndef INC_1STPROGRAM_OFFER_14_CUT_ROPE_H
#define INC_1STPROGRAM_OFFER_14_CUT_ROPE_H

#include <iostream>
#include <vector>

int cut_rope(int n) {
    if (n <= 0) {
        return 0;
    }
    std::vector<int> dp(n+1, 0);
    int Max = INT_MIN;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; ++i) {
        int Max = 0;
        for (int j = 1; j <= i / 2; ++j) {
            int temp = dp[i - j] * dp[j];
            if (temp > Max) {
                Max = temp;
            }
        }
        dp[i] = Max;
    }
    return dp[n];
}

void test_cut_rope() {
    int num = 7;
    std::cout << cut_rope(num) << std::endl;

}
#endif //INC_1STPROGRAM_OFFER_14_CUT_ROPE_H
