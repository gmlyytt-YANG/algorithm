/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_57. Continuous Sequence.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/18 9:34:00
 * @brief 剑指offer57题 连续数字序列和为S
 * */

#ifndef INC_1STPROGRAM_OFFER_57_CONTINUOUS_SEQUENCE_H
#define INC_1STPROGRAM_OFFER_57_CONTINUOUS_SEQUENCE_H

#include "../util/header_util.h"

std::pair<int, int> find_continuous_seq(int sum) {
    std::pair<int, int> result = {0, 0};
    if (sum < 3) {
        return result;
    }
    int small = 1;
    int big = 2;
    int mid = (sum + 1) / 2;
    int current_sum = small + big;
    while (small < mid) {
        if (current_sum == sum) {
            return {small, big};
        }
        while (small < mid && current_sum > sum) {
            current_sum -= small;
            ++small;
            if (current_sum == sum) {
                return {small, big};
            }
        }
        ++big;
        current_sum += big;
    }
    return {0, 0};
};

void test_find_continuous_seq() {
    int num = 3;
    std::pair<int, int> result = find_continuous_seq(num);
}
#endif //INC_1STPROGRAM_OFFER_57_CONTINUOUS_SEQUENCE_H
