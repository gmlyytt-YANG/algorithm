// Created by Li,Yang(Duer04) on 2018/8/15.
// Author: liyang
//
// 斐波那契序列

#ifndef INC_1STPROGRAM_OFFER_10_FIBONACCI_H
#define INC_1STPROGRAM_OFFER_10_FIBONACCI_H

#include <iostream>

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

void test_fibonacci() {
    int value = 100;
    std::cout << fibonacci(value) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_10_FIBONACCI_H
