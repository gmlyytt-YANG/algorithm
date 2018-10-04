// Created by Li,Yang(Duer04) on 2018/8/25.
// Author: liyang
//
// 求绝对值算法优化
#ifndef INC_1STPROGRAM_COMMON_15_ALGORITHM_OP_TOUTIAO_H
#define INC_1STPROGRAM_COMMON_15_ALGORITHM_OP_TOUTIAO_H

#include <iostream>
#include <vector>

double ori(std::vector<double>& arr) {
    double result = 0.0;
    double num = arr.size();
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            result += std::abs(arr[i] - arr[j]);
        }
    }
    return result;
}

double opt1(std::vector<double>& arr) {
    double result = 0.0;
    double temp_result = 0.0;
    double num = arr.size();
    for (int i = 0; i < num; ++i) {
        temp_result += std::abs(arr[0] - arr[i]);
    }
    result += temp_result;
    for (int i = 1; i < num; ++i) {
        if (arr[i] > arr[0]) {
            result += temp_result * (num - 1);
        } else if (arr[i] < arr[0]){
            result -= temp_result * (num - 1);
        }
    }
    return result;
}

void test_algorithm_opt() {
    std::vector<double> arr = {3.2, 4.5, 5.5, 6.7, 9.0};
    double result = ori(arr);
    double result_2 = opt1(arr);
}
#endif //INC_1STPROGRAM_COMMON_15_ALGORITHM_OP_TOUTIAO_H
