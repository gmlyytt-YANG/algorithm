// Created by Li,Yang(Duer04) on 2018/9/3.
// Author: liyang
//
// 桶排序

#ifndef SORT_BUCKET_SORT_H
#define SORT_BUCKET_SORT_H

#include <iostream>
#include <vector>

#include "count_sort.h"

void bucket_sort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    int Max = find_max(arr);
    std::vector<int> temp(Max + 1, 0);
    for (auto& elem : arr) {
        ++temp[elem];
    }
    int index = 0;
    for (int i = 0; i < Max + 1; ++i) {
        for (int j = 0; j < temp[i]; ++j) {
            arr[index++] = i;
        }
    }
}

void test_bucket_sort() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 5, 6, 3, 2, 1, 9};
    bucket_sort(arr);
}
#endif //SORT_BUCKET_SORT_H
