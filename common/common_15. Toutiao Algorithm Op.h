/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_15. Toutiao Algorithm Op.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/25 20:35:00
 * @brief 求绝对值算法优化
 * */

#ifndef INC_1STPROGRAM_COMMON_15_ALGORITHM_OP_TOUTIAO_H
#define INC_1STPROGRAM_COMMON_15_ALGORITHM_OP_TOUTIAO_H

#include "../util/header_util.h"

double ori(std::vector<double> &arr) {
    double result = 0.0;
    double num = arr.size();
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            result += std::abs(arr[i] - arr[j]);
        }
    }
    return result;
}

double opt1(std::vector<double> &arr) {
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
        } else if (arr[i] < arr[0]) {
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
