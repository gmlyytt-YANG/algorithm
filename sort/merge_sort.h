// Created by Li,Yang(Duer04) on 2018/8/2.
// Author: liyang
//
// 归并排序

#ifndef SORT_MERGE_SORT_H
#define SORT_MERGE_SORT_H

#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> arr_left(arr.begin() + low, arr.begin() + mid + 1);
    arr_left.push_back(INT_MAX);
    std::vector<int> arr_right(arr.begin() + mid + 1, arr.begin() + high + 1);
    arr_right.push_back(INT_MAX);

    int left_index = 0;
    int right_index = 0;
    for (int i = low; i <= high; ++i) {
        if (arr_left[left_index] <= arr_right[right_index]) {
            arr[i] = arr_left[left_index++];
        }
        else {
            arr[i] = arr_right[right_index++];
        }
        std::cout << arr[i] << " " << std::endl;
    }
    std::cout << std::endl;
}

void merge_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid , high);
    }
}

void test_merge_sort() {
    std::vector<int> arr = {1, 3, 2, 4, 5};
    merge_sort(arr, 0, static_cast<int>(arr.size() - 1));
}

#endif //SORT_MERGE_SORT_H
