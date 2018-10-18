/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_2. Fibonacci.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/15 10:29:00
 * @brief 剑指offer第2题 斐波那契序列
 * */

#ifndef INC_1STPROGRAM_OFFER_10_FIBONACCI_H
#define INC_1STPROGRAM_OFFER_10_FIBONACCI_H

#include "../util/header_util.h"

long long fibonacci(int num) {
    int arr[] = {0, 1};
    if (num < 2) {
        return arr[num];
    }
    long long first = 1;
    long long second = 0;
    long long result = first + second;
    for (int i = 2; i < num; ++i) {
        second = first;
        first = result;
        result = first + second;
    }
    return result;
}

long long fibonacci2(int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    return fibonacci2(num - 1) + fibonacci2(num - 2);
}

void test_fibonacci() {
    int value = 100;
    std::cout << fibonacci(value) << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_10_FIBONACCI_H
