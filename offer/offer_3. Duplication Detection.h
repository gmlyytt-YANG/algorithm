// Created by Li,Yang(Duer04) on 2018/8/21.
// Author: liyang
//
// 找出数组中重复的数字

#ifndef INC_1STPROGRAM_OFFER_3_DUPLICATION_DETECTION_H
#define INC_1STPROGRAM_OFFER_3_DUPLICATION_DETECTION_H

#include <iostream>
#include <vector>

bool duplicate(int numbers[], int length, int* duplication) {
    for (int i = 0; i < length; ++i) {
        if (numbers[i] > length -1 || numbers[i] < 0) {
            return false;
        }
    }
    for (int i = 0; i < length; ++i) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

void test_duplicate() {
    int numbers[] = {0, 1, 2, 2};
    int duplication = 0;
    int length = 4;
    if (duplicate(numbers, length, &duplication)) {
        std::cout << duplication << std::endl;
    }
}
#endif //INC_1STPROGRAM_OFFER_3_DUPLICATION_DETECTION_H
