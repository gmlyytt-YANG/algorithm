/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_69. Sqrt(x).h
 * @author gmlyytt@outlook.com
 * @date 2018/10/18 12:55:00
 * @brief  https://leetcode.com/problems/sqrtx/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_69_SQRT_X_H
#define INC_1STPROGRAM_LEETCODE_69_SQRT_X_H

#include "../util/header_util.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int low = 1;
        int high = x;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid <= x / mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (x / low == low) {
            return low;
        }
        return low - 1;
    }
};

void test_sqrt() {
    int x = 8;
    int result = Solution().mySqrt(x);
    cout << result << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_69_SQRT_X_H
