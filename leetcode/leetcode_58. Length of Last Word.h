/*************************************************************************
 *
 * Copyright (c) 2019 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_58. Length of Last Word.h
 * @author gmlyytt@outlook.com
 * @date 2019/4/27
 * @brief https://leetcode.com/problems/length-of-last-word/
 * */
#ifndef INC_1STPROGRAM_LEETCODE_58_LENGTH_OF_LAST_WORD_H
#define INC_1STPROGRAM_LEETCODE_58_LENGTH_OF_LAST_WORD_H

#include "../util/header_util.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        int result = 0;
        int indent_flag = 0;
        for (int inverse_index = length - 1; inverse_index >= 0; --inverse_index) {
            if (s[inverse_index] != ' ') {
                ++result;
                indent_flag = 1;
            } else if (indent_flag == 0) {
                // indent in the end
                continue;
            } else {
                break;
            }
        }

        return result;
    }
};

void test_length_of_last_word() {
    string s = "Hello World";
    cout << Solution().lengthOfLastWord(s) << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_58_LENGTH_OF_LAST_WORD_H
