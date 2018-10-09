/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_14. Cut Rope.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/29 10:29:00
 * @brief 剑指offer第14题 剪绳子
 * */

#ifndef INC_1STPROGRAM_OFFER_14_CUT_ROPE_H
#define INC_1STPROGRAM_OFFER_14_CUT_ROPE_H

#include "../util/header_util.h"

int cut_rope(int n) {
    if (n <= 0) {
        return 0;
    }
    std::vector<int> dp(n + 1, 0);
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
