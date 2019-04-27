/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_14. Longest Common Prefix.h
 * @author gmlyytt@outlook.com
 * @date 2019/04/26 15:52:00
 * @brief https://leetcode.com/problems/longest-common-prefix/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_14_LONGEST_COMMON_PREFIX_H
#define INC_1STPROGRAM_LEETCODE_14_LONGEST_COMMON_PREFIX_H

#include "../util/header_util.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        string result = strs[0];
        if (strs.size() == 1) {
            return result;
        }

        int strs_size = strs.size();
        int common_bit = INT16_MAX;

        for (int index = 1; index < strs_size; ++index) {
            int common_bit_elem = 0;
            for (int bit = 0; bit < strs[0].size() && bit < strs[index].size(); ++bit) {
                if (strs[index][bit] != strs[0][bit]) {
                    break;
                }
                ++common_bit_elem;
            }

            if (common_bit_elem == 0) {
                return result;
            }
            if (common_bit_elem < common_bit) {
                common_bit = common_bit_elem;
            }
        }

        return strs[0].substr(0, common_bit);
    }
};

void test_longest_common_prefix() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << Solution().longestCommonPrefix(strs) << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_14_LONGEST_COMMON_PREFIX_H
