/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_43. Multiply Strings.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/17 18:52:00
 * @brief https://leetcode.com/problems/multiply-strings/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_43_MULTIPLY_STRINGS_H
#define INC_1STPROGRAM_LEETCODE_43_MULTIPLY_STRINGS_H

#include "../util/header_util.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int length1 = num1.size();
        int length2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> result(length1 + length2, 0);
        string result_str;
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                result[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < length1 + length2 - 1; ++i) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        if (result[length1 + length2 - 1] != 0) {
            result_str += to_string(result[length1 + length2 - 1]);
        }
        for (int i = length1 + length2 - 2; i >= 0; --i) {
            result_str += to_string(result[i]);
        }
        return result_str;
    }
};

void test_multiply() {
    string num1 = "123";
    string num2 = "456";
    string result = Solution().multiply(num1, num2);
    cout << result << endl;
}
#endif //INC_1STPROGRAM_LEETCODE_43_MULTIPLY_STRINGS_H
