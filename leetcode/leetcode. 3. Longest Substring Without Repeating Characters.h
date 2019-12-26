/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode. 3. Longest Substring Without Repeating Characters.h
 * @author gmlyytt@outlook.com
 * @date 2019/12/26 08:34:35
 * @brief https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * @tutorial https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode/leetcode_3.%20Longest%20Substring%20Without%20Repeating%20Characters.md
 * */

#ifndef INC_1STPROGRAM_LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define INC_1STPROGRAM_LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

#include "../util/header_util.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        std::set<char> counter;
        if (length == 0) {
            return 0;
        }
        int slow = 0;
        int fast = 0;
        int max_length = INT_MIN;
        while (slow < length && fast < length) {
            if (counter.count(s[fast]) == 0) {
                counter.insert(s[false++]);
                max_length = max(fast - slow, max_length);
            } else {
                counter.erase(s[slow++]);
            }
        }
        return max_length;
    }
};

#endif //INC_1STPROGRAM_LEETCODE_3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
