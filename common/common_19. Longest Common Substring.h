/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_19. Longest Common Substring.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/10 20:35:00
 * @brief 两个子串的最长公共子串
 * */


#ifndef INC_1STPROGRAM_COMMON_19_LONGEST_COMMON_SUBSTRING_H
#define INC_1STPROGRAM_COMMON_19_LONGEST_COMMON_SUBSTRING_H

#include <iostream>
#include <vector>

int longest_common_substring(std::string& str1, std::string& str2) {
    if (str1.empty() || str2.empty()) {
        return 0;
    }
    int length1 = str1.size();
    int length2 = str2.size();
    std::vector<std::vector<int>> result(length1, std::vector<int>(length2, 0));
    int max = 0;
    for (int i = 0; i < length1; ++i) {
        for (int j = 0; j < length2; ++j) {
            if (i == 0 || j == 0) {
                if (str1[i] == str2[j]) {
                    result[i][j] = 1;
                }
            } else {
                if (str1[i] != str2[j]) {
                    result[i][j] = 0;
                } else {
                    result[i][j] = result[i - 1][j - 1] + 1;
                }
            }
            if (max < result[i][j]) {
                max = result[i][j];
            }
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return max;
}

int longest_common_subsequence(std::string& str1, std::string& str2) {
    if (str1.empty() || str2.empty()) {
        return 0;
    }
    int max = INT_MIN;
    std::vector<std::vector<int>> result(str1.size() + 1, std::vector<int>(str2.size() + 1, 0));
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                result[i][j] = result[i - 1][j - 1] + 1;
            } else {
                result[i][j] = std::max(result[i - 1][j], result[i][j - 1]);
            }
            if (max < result[i][j]) {
                max = result[i][j];
            }
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return result[str1.size()][str2.size()];
}

void test_lcs() {
    std::string a = "BDCABA";
    std::string b = "ABCBDAB";
    std::cout << longest_common_substring(a, b) << std::endl;
    std::cout << longest_common_subsequence(a, b) << std::endl;
}
#endif //INC_1STPROGRAM_COMMON_19_LONGEST_COMMON_SUBSTRING_H
