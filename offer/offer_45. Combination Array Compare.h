/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_45. Combination Array Compare.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/17 9:34:00
 * @brief 剑指offer45题 数组中所有数字组合而成的最小数
 * */

#ifndef INC_1STPROGRAM_OFFER_45_COMBINATION_ARRAY_COMPARE_H
#define INC_1STPROGRAM_OFFER_45_COMBINATION_ARRAY_COMPARE_H

#include "../util/header_util.h"

struct comp {
    bool operator()(std::string &str1, std::string &str2) {
        std::string combine1 = str1 + str2;
        std::string combine2 = str2 + str1;
        return combine1 < combine2;
    }
};

long long combination_array_compare(std::vector<int> &arr) {
    if (arr.empty()) {
        return -1;
    }
    long long result;
    std::vector<std::string> str_arr;
    for (auto &elem : arr) {
        std::string str;
        std::stringstream is;
        is << elem;
        is >> str;
        str_arr.push_back(str);
    }
    std::sort(str_arr.begin(), str_arr.end(), comp());
    std::string str_total;
    for (auto &elem : str_arr) {
        str_total += elem;
    }
    std::stringstream is;
    is << str_total;
    is >> result;
    return result;
}

void test_combination_array_compare() {
    std::vector<int> arr = {0, 0, 0, 0};
    long long result = combination_array_compare(arr);
    std::cout << result << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_45_COMBINATION_ARRAY_COMPARE_H
