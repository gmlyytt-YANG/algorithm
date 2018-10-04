/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_7. Longest Palindrome Substring.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/13 20:35:00
 * @brief 最长回文子串
 * */

#ifndef INC_1STPROGRAM_COMMON_7_LONGEST_PALINDROME_SUBSTRING_H
#define INC_1STPROGRAM_COMMON_7_LONGEST_PALINDROME_SUBSTRING_H

#include <iostream>

int palindrome_str_length(const std::string& str, int left, int right, std::string& result) {
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
        --left;
        ++right;
    }
    result = str.substr(left + 1, right - left - 1);
    return right - left - 1;
}

std::string longest_palindrome_substring(const std::string& str) {
    if (str.empty()) {
        return "";
    }
    int max_length = 0;
    std::string longest_substr = "";
    int temp_length = 0;
    std::string temp_substr = "";
    for (int i = 0; i < str.size(); ++i) {
        temp_length = palindrome_str_length(str, i, i, temp_substr);
        if (temp_length > max_length) {
            longest_substr = temp_substr;
            max_length = temp_length;
        }
        temp_length = palindrome_str_length(str, i, i + 1, temp_substr);
        if (temp_length > max_length) {
            longest_substr = temp_substr;
            max_length = temp_length;
        }
    }
    return longest_substr;
}

void test_longest_palindrome_substring() {
    std::string str = "abbacbcabdad";
    std::string result = longest_palindrome_substring(str);

}
#endif //INC_1STPROGRAM_COMMON_7_LONGEST_PALINDROME_SUBSTRING_H
