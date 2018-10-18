/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_66. Plus One.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/18 10:59:00
 * @brief https://leetcode.com/problems/plus-one/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_66_PLUS_ONE_H
#define INC_1STPROGRAM_LEETCODE_66_PLUS_ONE_H

#include "../util/header_util.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int high = digits.size() - 1;
        int carry = 1;
        int sum = 0;
        while (high >= 0) {
            if (carry == 0) {
                break;
            }
            sum = carry + digits[high];
            carry = sum / 10;
            digits[high] = sum % 10;
            --high;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

void test_plus_one() {
    vector<int> arr = {4, 2, 1, 1};
    vector<int> result = Solution().plusOne(arr);
}
#endif //INC_1STPROGRAM_LEETCODE_66_PLUS_ONE_H
