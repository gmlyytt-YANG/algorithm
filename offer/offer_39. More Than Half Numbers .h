// Created by Li,Yang(Duer04) on 2018/8/16.
// Author: liyang
//
// 数组中频率超过数组长度一半的数字

#ifndef INC_1STPROGRAM_OFFER_39_MORE_THAN_HALF_NUMBERS_H
#define INC_1STPROGRAM_OFFER_39_MORE_THAN_HALF_NUMBERS_H

#include <iostream>
#include <vector>

int partion(std::vector<int>& arr, int start, int end) {
    if (start > end) {
        std::cout << "invalid input" << std::endl;
        exit(-1);
    }
    int i = start - 1;
    int value = arr[end];
    for (int j = start; j < end; ++j) {
        if (arr[j] <= value) {
            std::swap(arr[j], arr[++i]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

bool check_more_than_half(std::vector<int>& arr, int num) {
    int count = 0;
    for (auto& elem : arr) {
        if (num == elem) {
            ++count;
        }
    }
    if (count * 2 > arr.size()) {
        return true;
    }
    return false;
}

int more_than_half(std::vector<int>& arr) {
    if (arr.empty()) {
        std::cout << "invalid input" << std::endl;
        exit(-1);
    }

    int length = arr.size();
    int middle = (length >> 1);
    int start = 0;
    int end = length - 1;
    int index = partion(arr, start, end);
    while (index != middle) {
        if (index > middle) {
            index = partion(arr, start, index - 1);
        } else {
            index = partion(arr, index + 1, end);
        }
    }

    if (check_more_than_half(arr, arr[index])) {
        return arr[index];
    } else {
        std::cout << "invalid input" << std::endl;
        exit(-1);
    }
}

int more_than_half_2(std::vector<int>& arr) {
    if (arr.empty()) {
        exit(-1);
    }
    int time = 1;
    int result = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (time == 0) {
            time = 1;
            result = arr[i];
        } else if (result == arr[i]) {
            ++time;
        } else {
            --time;
        }
    }
    if (check_more_than_half(arr, result)) {
        return result;
    } else {
        std::cout << "invalid input" << std::endl;
        exit(-1);
    }
}

void test_more_than_half() {
    std::vector<int> arr = {1, 5, 5, 5, 2};
    int result = more_than_half(arr);
}
#endif //INC_1STPROGRAM_OFFER_39_MORE_THAN_HALF_NUMBERS_H
