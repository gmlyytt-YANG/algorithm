//
// Created by Li,Yang(Duer04) on 2018/8/2.
// 堆排序

#ifndef SORT_HEAP_SORT_H
#define SORT_HEAP_SORT_H

#include <iostream>
#include <vector>

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void max_heapify(std::vector<int>& arr, int i, int delta = 0) {
    int largest = 0;
    if (left(i) < arr.size() - delta && arr[left(i)] > arr[i]) {
        largest = left(i);
    }
    else {
        largest = i;
    }
    if (right(i) < arr.size() - delta && arr[right(i)] > arr[i]) {
        largest = right(i);
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, delta);
    }
}

void build_maxheap(std::vector<int>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        max_heapify(arr, i);
        for (auto& elem : arr) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void heap_sort(std::vector<int>& arr) {
    int delta = 0;
    build_maxheap(arr);
    for (int i = arr.size() - 1; i >= 0; --i) {
        std::swap(arr[0], arr[arr.size() - delta - 1]);
        max_heapify(arr, 0, ++delta);
    }
}

void test_heap_sort() {
    std::vector<int> arr = {3, 2, 1, 4, 5};
    heap_sort(arr);
}
#endif //SORT_HEAP_SORT_H
