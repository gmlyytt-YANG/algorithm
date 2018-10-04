// Created by Li,Yang(Duer04) on 2018/8/9.
// Author: liyang
//
// 旋转数组的最小值

#ifndef INC_1STPROGRAM_OFFER_11_MIN_IN_ROTATE_ARRAY_H
#define INC_1STPROGRAM_OFFER_11_MIN_IN_ROTATE_ARRAY_H

#include <iostream>
#include <vector>
#include <exception>
#include <cstdio>

int min(std::vector<int>& arr, int low, int high) {
    if (low > high) {
        exit(-1);
    }
    int result = INT_MAX;
    for (int i = low; i <= high; ++i) {
        if (arr[i] < result) {
            result = arr[i];
        }
    }
    return result;
}

int min_inorder(std::vector<int>& arr) {
    if (arr.empty()) {
        exit(-1);
    }
    int low = 0;
    int high = arr.size() - 1;
    int result = 0;
    while (arr[low] >= arr[high]) {
        if (high - low == 1) {
            result = arr[high];
            break;
        }
        int mid = ((low + high) >> 1);
        if (arr[mid] == arr[high] && arr[high] == arr[low]) {
            result = min(arr, low, high);
            break;
        }
        if (arr[low] <= arr[mid]) {
            low = mid;
        }
        else if (arr[high] >= arr[mid]) {
            high = mid;
        }
    }
    return result;
}

void test_min_inorder() {
    std::vector<int> arr1 = {1, 0, 1, 1, 1};
    std::vector<int> arr2 = {5, 5, 5, 3, 4};
    int result = min_inorder(arr2);
    std::cout << result << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_11_MIN_IN_ROTATE_ARRAY_H
