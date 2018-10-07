/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_241. Different Ways to Add Parentheses.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/06 20:47:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_241_DIFFERENT_WAYS_TO_ADD_PARENTHESES_H
#define INC_1STPROGRAM_LEETCODE_241_DIFFERENT_WAYS_TO_ADD_PARENTHESES_H

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diffWaysToCompute(std::string input) {
        std::vector<int> result;
        int length = input.size();
        for (int i = 0; i < length; ++i) {
            char elem = input[i];
            if (elem == '-' || elem == '+' || elem == '*') {
                std::string left = input.substr(0, i);
                std::string right = input.substr(i + 1);
                std::vector<int> left_result = diffWaysToCompute(left);
                std::vector<int> right_result = diffWaysToCompute(right);
                for (auto& elem1 : left) {
                    for (auto& elem2 : right) {
                        if (elem == '-') {
                            result.push_back(elem1 - elem2);
                        } else if (elem == '+') {
                            result.push_back(elem1 + elem2);
                        } else {
                            result.push_back(elem1 * elem2);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(input[0] - '0');
        }
        return result;
    }
};

void test_compute() {
    // some bugs of cxx11
    std::string input("2-1-1");
    std::vector<int> result = Solution().diffWaysToCompute(input);
}
#endif //INC_1STPROGRAM_LEETCODE_241_DIFFERENT_WAYS_TO_ADD_PARENTHESES_H
