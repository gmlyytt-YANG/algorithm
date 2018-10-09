/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_38. Permutation.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/10 10:29:00
 * @brief 剑指offer第38题 字符串的全排列
 * */

#ifndef INC_1STPROGRAM_OFFER_38_PERMUTATION_H
#define INC_1STPROGRAM_OFFER_38_PERMUTATION_H

#include "../util/header_util.h"

void permutation_core(std::vector<std::string> &result, std::string &str, int begin) {
    if (begin == str.size()) {
        result.push_back(str);
    } else {
        for (int i = begin; i < str.size(); ++i) {
            std::swap(str[i], str[begin]);
            permutation_core(result, str, begin + 1);
            std::swap(str[i], str[begin]);
        }
    }
}

std::vector<std::string> permuation(std::string &str) {
    std::vector<std::string> result;
    permutation_core(result, str, 0);
    auto unique_ptr = std::unique(result.begin(), result.end());
    result.erase(unique_ptr, result.end());
    return result;
}

void test_permutation() {
    std::string str = "abcde";
    std::vector<std::string> result = permuation(str);

}

#endif //INC_1STPROGRAM_OFFER_38_PERMUTATION_H
