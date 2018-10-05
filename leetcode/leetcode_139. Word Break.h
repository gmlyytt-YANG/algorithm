//
// Created by Li,Yang(Duer04) on 2018/8/1.
//

/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_139. Word Break.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/01 10:01:00
 * @brief https://leetcode.com/problems/word-break/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_139_WORD_BREAK_H
#define INC_1STPROGRAM_LEETCODE_139_WORD_BREAK_H

#include "../util/header_util.h"

bool wordBreak(string s, vector<string> &wordDict) {
    int length = s.size();
    if (wordDict.empty() || s.empty()) {
        return false;
    }
    vector<bool> dp(length + 1, false);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    dp[length] = true;
    for (int i = length - 1; i >= 0; --i) {
        for (int j = i; j < length; ++j) {
            string str = s.substr(i, j - i + 1);
            if (dict.find(str) != dict.end() && dp[j + 1] == true) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}


void test_word_break() {
    string s = "dogs";
    vector<string> wordDict = {"dog", "s", "gs"};
    bool result = wordBreak(s, wordDict);
}

#endif //INC_1STPROGRAM_LEETCODE_139_WORD_BREAK_H
