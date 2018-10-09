/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_16. Square.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/15 10:29:00
 * @brief 剑指offer第16题 数值的整数次幂
 * */

#ifndef INC_1STPROGRAM_OFFER_16_SQUARE_H
#define INC_1STPROGRAM_OFFER_16_SQUARE_H

#include "../util/header_util.h"

bool invalid_input = false;

bool equals_double(double a, double b) {
    return a - b > -0.0000001 && a - b < 0.0000001;
}

double power_pos_recursive(double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    if (exponent == 1) {
        return base;
    }
    double result = power_pos_recursive(base, exponent >> 1);
    result *= result;
    if (exponent & 1) {
        result *= base;
    }
    return result;
}

double power(double base, int exponent) {
    if (equals_double(base, 0.0) && exponent < 0) {
        invalid_input = false;
        return 0.0;
    }
    double result = 1.0;
    int exponent_pos = exponent;
    if (exponent < 0) {
        exponent_pos = -exponent;
    }
    // for (int i = 1; i <= exponent_pos; ++i) {
    //     result *= base;
    // }
    result = power_pos_recursive(base, exponent_pos);
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

void test_power() {
    double base = 5.0;
    int exponent = -2;
    double result = power(base, exponent);
    std::cout << result << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_16_SQUARE_H
