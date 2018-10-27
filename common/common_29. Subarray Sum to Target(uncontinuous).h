/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_29. Subarray Sum to Target(uncontinuous).h
 * @author gmlyytt@outlook.com
 * @date 2018/10/26 14:45:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_COMMON_29_SUBARRAY_SUM_TO_TARGET_UNCONTINUOUS_H
#define INC_1STPROGRAM_COMMON_29_SUBARRAY_SUM_TO_TARGET_UNCONTINUOUS_H

#include "../util/header_util.h"

bool subarray_sum_to_target(vector<int> &array, int target) {
    vector<int> dp(target + 1, false);
    dp[0] = true;
    for (auto &elem : array) {
        for (int i = target; i >= elem; --i) {
            dp[i] = dp[i] || dp[i - elem];
            if (dp[target]) {
                return true;
            }
        }
    }
    return false;
}

void test_subarray_sum_to_target() {
    vector<int> array = {1, 2, 4, 3, 5, 7};
    int target = 14;
    bool result = subarray_sum_to_target(array, target);
    cout << result << endl;
}

#endif //INC_1STPROGRAM_COMMON_29_SUBARRAY_SUM_TO_TARGET_UNCONTINUOUS_H
