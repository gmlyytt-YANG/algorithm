/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file quick_sort.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/02 10:29:00
 * @brief 快速排序
 * */

#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H

#include "../util/header_util.h"

int partion(std::vector<int> &arr, int low, int high) {
    if (low > high) {
        return -1;
    }
    int i = low - 1;
    int key = arr[high];
    for (int j = low; j < high; ++j) {
        if (arr[j] <= key) {
            std::swap(arr[j], arr[++i]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_recursive(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int index = partion(arr, low, high);
        quick_sort_recursive(arr, low, index - 1);
        quick_sort_recursive(arr, index + 1, high);
    }
}

void quick_sort_iterative(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int low = 0;
    int high = arr.size() - 1;
    std::stack<int> stk;
    stk.push(high);
    stk.push(low);
    while (!stk.empty()) {
        int low = stk.top();
        stk.pop();
        int high = stk.top();
        stk.pop();
        if (low > high) {
            continue;
        }
        int q = partion(arr, low, high);
        if (q < high) {
            stk.push(high);
            stk.push(q + 1);
        }
        if (q > low) {
            stk.push(q - 1);
            stk.push(low);
        }
    }
}

void test_quick_sort() {
    // 递归模式
    std::vector<int> arr = {1, 4, 2, 5, 6, 3, 7};
    quick_sort_recursive(arr, 0, static_cast<int>(arr.size()) - 1);
    for (auto &elem : arr) {
        std::cout << elem << std::endl;
    }

    // 迭代模式
    arr = {3, 2, 1, 3, 4, 5};
    quick_sort_iterative(arr);
    for (auto &elem : arr) {
        std::cout << elem << std::endl;
    }
}

#endif //SORT_QUICK_SORT_H
