//
// Created by Li,Yang(Duer04) on 2018/8/1.
//

#ifndef INC_1STPROGRAM_LEETCODE_139_WORD_BREAK_H
#define INC_1STPROGRAM_LEETCODE_139_WORD_BREAK_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
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
