// Created by Li,Yang(Duer04) on 2018/8/10.
// Author: liyang
//
// 字符串的全排列

#ifndef INC_1STPROGRAM_OFFER_38_PERMUTATION_H
#define INC_1STPROGRAM_OFFER_38_PERMUTATION_H

#include <iostream>
#include <vector>

void permutation_core(std::vector<std::string>& result, std::string& str, int begin);

std::vector<std::string> permuation(std::string& str) {
    std::vector<std::string> result;
    permutation_core(result, str, 0);
    auto unique_ptr = std::unique(result.begin(), result.end());
    result.erase(unique_ptr, result.end());
    return result;
}

void permutation_core(std::vector<std::string>& result, std::string& str, int begin) {
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

void test_permutation() {
    std::string str = "abcde";
    std::vector<std::string> result = permuation(str);

}
#endif //INC_1STPROGRAM_OFFER_38_PERMUTATION_H
