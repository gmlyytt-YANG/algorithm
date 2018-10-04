// Created by Li,Yang(Duer04) on 2018/8/17.
// Author : liyang
//
// 数组中所有数字组合而成的最小数

#ifndef INC_1STPROGRAM_OFFER_45_COMBINATION_ARRAY_COMPARE_H
#define INC_1STPROGRAM_OFFER_45_COMBINATION_ARRAY_COMPARE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

//struct cmp {
//    bool operator()(const std::string& str1, const std::string& str2){
//        std::string combine1 = str1 + str2;
//        std::string combine2 = str2 + str1;
//        return combine1 < combine2;
//    }
//};

//long long combination_array_compare(std::vector<int>& arr) {
//    if (arr.empty()) {
//        return -1;
//    }
//    std::vector<std::string> tmp_result(arr.size(), "");
//    std::string tmp;
//    long long result;
//    for (int i = 0; i < arr.size(); ++i) {
//        std::stringstream is;
//        is << arr[i];
//        is >> tmp_result[i];
//    }
//    std::sort(tmp_result.begin(), tmp_result.end(), cmp());
//    for (auto& elem : tmp_result) {
//        tmp += elem;
//    }
//    std::stringstream is;
//    is << tmp;
//    is >> result;
//    return result;
//}
struct comp {
    bool operator()(std::string& str1, std::string& str2) {
        std::string combine1 = str1 + str2;
        std::string combine2 = str2 + str1;
        return combine1 < combine2;
    }
};

long long combination_array_compare(std::vector<int>& arr) {
    if (arr.empty()) {
        return -1;
    }
    long long result;
    std::vector<std::string> str_arr;
    for (auto& elem : arr) {
        std::string str;
        std::stringstream is;
        is << elem;
        is >> str;
        str_arr.push_back(str);
    }
    std::sort(str_arr.begin(), str_arr.end(), comp());
    std::string str_total;
    for (auto& elem : str_arr) {
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
