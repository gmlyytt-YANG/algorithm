// Created by Administrator on 2018/9/12.
// Author: liyang
//
// 打印1到n位数的最大值

#ifndef INC_1STPROGRAM_OFFER_17_1_TO_N_PRINT_H
#define INC_1STPROGRAM_OFFER_17_1_TO_N_PRINT_H

#include <iostream>
#include <vector>

bool increament(std::string& number) {
    int length = number.size();
    int take_over = 0;
    bool is_over_flow = false;
    for (int i = length - 1; i >= 0; --i) {
        int n_sum = number[i] - '0' + take_over;
        if (i == length - 1) {
            ++n_sum;
        }
        if (n_sum >= 10) {
            if (i == 0) {
                is_over_flow = true;
                break;
            } else {
                n_sum -= 10;
                take_over = 1;
                number[i] = static_cast<char>(n_sum + '0');
            }
        } else {
            number[i] = static_cast<char>(n_sum + '0');
            break;
        }
    }
    return is_over_flow;
}

void print_number(std::string& number) {
    bool is_begin_0 = true;
    for (char i : number) {
        if (is_begin_0 && i != '0') {
            is_begin_0 = false;
        }
        if (!is_begin_0) {
            std::cout << i;
        }
    }
    std::cout << std::endl;
}

void test_increament() {
    int n = 5;
    std::string number(n, '0');
    while (!increament(number)) {
        print_number(number);
    }
}
#endif //INC_1STPROGRAM_OFFER_17_1_TO_N_PRINT_H
