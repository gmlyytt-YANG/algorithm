/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file count_sort.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/05 10:29:00
 * @brief 计数排序
 * */

#ifndef SORT_COUNT_SORT_H
#define SORT_COUNT_SORT_H

#include "../util/header_util.h"

template<class T>
T find_max(std::vector<T> &arr) {
    T Max = arr[0];
    for (auto &elem : arr) {
        if (Max < elem) {
            Max = elem;
        }
    }
    return Max;
}

void count_sort(std::vector<int> &arr, std::vector<int> &B) {
    int Max = find_max(arr);
    std::vector<int> C(Max + 1, 0);
    for (auto &elem : arr) {
        ++C[elem];
    }

    for (int i = 1; i < C.size(); ++i) {
        C[i] += C[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        B[C[arr[i]] - 1] = arr[i];
        --C[arr[i]];
    }
}

void test_count_sort() {
    std::vector<int> A = {1, 2, 3, 4, 6, 5, 9, 8, 7};
    std::vector<int> B(A.size(), 0);
    count_sort(A, B);

    for (auto &elem: B) {
        std::cout << elem << std::endl;
    }
}

#endif //SORT_COUNT_SORT_H
