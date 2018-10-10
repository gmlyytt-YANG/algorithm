/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_43. Frequence Of 1.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/20 9:34:00
 * @brief 剑指offer43题 1到n的连续整数序列中1出现的次数
 * */

#ifndef INC_1STPROGRAM_OFFER_43_FREQUENCE_OF_1_H
#define INC_1STPROGRAM_OFFER_43_FREQUENCE_OF_1_H

#include "../util/header_util.h"

int frequence_of_1(const int num) {
    if (num <= 0) {
        return 0;
    }
    int result = 0;
    int base = 1;
    int traverse = num;
    while (traverse) {
        int weight = traverse % 10;
        traverse /= 10;
        result += traverse * base;
        if (weight > 1) {
            result += base;
        } else if (weight == 1) {
            result += (num % base) + 1;
        }
        base *= 10;
    }
    return result;
}

void test_frequence_of_1() {
    int count = 0;
    while (true) {
        int number = 0;
        std::cin >> number;
        std::cout << frequence_of_1(number) << std::endl;
        if (count++ > 5) {
            break;
        }
    }

}
#endif //INC_1STPROGRAM_OFFER_43_FREQUENCE_OF_1_H
