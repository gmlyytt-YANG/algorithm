/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_3. Sqrt.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/12 20:35:00
 * @brief 开平方
 * */

#ifndef INC_1STPROGRAM_COMMON_3_SQRT_H
#define INC_1STPROGRAM_COMMON_3_SQRT_H

#include "../util/header_util.h"

const float eps = 1e-12;

bool float_equal(const float& first, const float& second) {
    bool result = false;
    if (first - second > -eps && first - second < eps) {
        result = true;
    }
    return result;
}

float sqrt(float num) {
    if (num <= 0.0) {
        return num;
    }
    float result = num + 1;
    while (!float_equal(result * result, num)) {
        result = (result * result + num) / (2 * result + eps);
    }
    return result;
}

void test_sqrt() {
    float num = 0.0001;
    std::cout << sqrt(num) << std::endl;
    std::cout << sizeof(long) << " " << sizeof(long long) << std::endl;
}

#endif //INC_1STPROGRAM_COMMON_3_SQRT_H
