/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_67. Add Binary.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/18 11:42:00
 * @brief https://leetcode.com/problems/add-binary/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_67_ADD_BINARY_H
#define INC_1STPROGRAM_LEETCODE_67_ADD_BINARY_H

#include "../util/header_util.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int length_a = a.size();
        int length_b = b.size();
        int pos = 0;
        stringstream s;
        while (pos < length_a || pos < length_b) {
            int num_a = 0;
            int num_b = 0;
            if (pos < length_a) {
                num_a = a[length_a - pos - 1] - '0';
            }
            if (pos < length_b) {
                num_b = b[length_b - pos - 1] - '0';
            }
            int sum = num_a + num_b + carry;
            if (sum > 1) {
                carry = 1;
            } else {
                carry = 0;
            }
            int r = sum % 2;
            s << r;
            ++pos;
        }
        if (carry) {
            s << 1;
        }
        string result;
        s >> result;
        reverse(result.begin(), result.end());
        return result;
    }
};

void test_add_binary() {
    string a = "0101";
    string b = "10101";
    string result = Solution().addBinary(a, b);
}

#endif //INC_1STPROGRAM_LEETCODE_67_ADD_BINARY_H
