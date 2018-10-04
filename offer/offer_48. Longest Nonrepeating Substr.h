// Created by Li,Yang(Duer04) on 2018/8/20.
// Author: liyang
//
// 找出最长不重复的字符串

#ifndef INC_1STPROGRAM_OFFER_48_LONGEST_NONREPEATING_SUBSTR_H
#define INC_1STPROGRAM_OFFER_48_LONGEST_NONREPEATING_SUBSTR_H

#include <iostream>
#include <map>
#include <vector>

//int longest_non_repeating_substr(std::string& str) {
//    if (str.empty()) {
//        return 0;
//    }
//    std::map<char, int> cnter;
//    int length = str.size();
//    std::vector<int> dp(length, 0);
//    dp[length - 1] = 1;
//    cnter[str[length - 1]] = length - 1;
//    int max_length = 1;
//    for (int i = str.size() - 2; i >= 0; --i) {
//        if (cnter.count(str[i]) > 0 && cnter[str[i]] <= dp[i + 1] + i) {
//            dp[i] = cnter[str[i]] - i;
//        } else {
//            dp[i] = dp[i + 1] + 1;
//        }
//        cnter[str[i]] = i;
//        if (dp[i] > max_length) {
//            max_length = dp[i];
//        }
//    }
//    return max_length;
//}

int longest_non_repeating_substr(std::string& str) {
    if (str.empty()) {
        return 0;
    }
    std::map<char, int> map;
    int length = str.size();
    std::vector<int> dp(length, 0);
    int max = 1;
    dp[length - 1] = 1;
    map[str[length - 1]] = length - 1;
    for (int i = length - 2; i >= 0; --i) {
        if (map.count(str[i]) > 0 && map[str[i]] - i <= dp[i +  1]) {
            dp[i] = map[str[i]] - i;
        } else {
            dp[i] = dp[i + 1] + 1;
        }
        map[str[i]] = i;
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

int longest_non_repeating_substr_2(std::string& str) {
    if (str.empty()) {
        return 0;
    }
    std::vector<int> cnter(26, -1);
    int max_length = -1;
    int length = str.size();
    int current_length = 0;
    for (int i = 0; i < length; ++i) {
        int pre_index = cnter[str[i] - '0'];
        if (pre_index < 0 || i - pre_index > current_length) {
            ++current_length;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
            }
            current_length = i - pre_index;
        }
        cnter[str[i] - '0'] = i;
    }
    if (current_length > max_length) {
        max_length = current_length;
    }
    return max_length;
}

void test_longest_non_repeating_substr() {
    std::string str = "abcacfrar";
    int count = 0;
    std::cout << longest_non_repeating_substr(str) << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_48_LONGEST_NONREPEATING_SUBSTR_H
