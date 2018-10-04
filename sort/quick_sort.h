// Created by Li,Yang(Duer04) on 2018/8/2.
// Author: liyang
//
// 快速排序

#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H

#include <iostream>
#include <vector>
#include <stack>

//Summary:  找到最后一个元素的安放位置
//Parameters:
//       array: 待排序的数组
//Core:
//       以最后一个元素为标志元素, 大于这个元素的元素放到这个元素的右边，
//       小于等于这个元素的放到这个元素得左边，
//Return : 安放好的标志元素的位置， array已经部分有序
int partion(std::vector<int>& arr, int low, int high) {
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

//Summary:  快速排序
//Parameters:
//       array: 待排序的数组
//Core:
//       找到标志元素的安放位置后，递归的对两边元素进行排序
//Return : null, array 已经排好序
void quick_sort_recursive(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int index = partion(arr, low, high);
        quick_sort_recursive(arr, low, index - 1);
        quick_sort_recursive(arr, index + 1, high);
    }
}

//Summary:  快速排序迭代形式
//Parameters:
//       array: 待排序的数组
//Core:
//       找到标志元素的安放位置后，迭代的对两边元素进行排序
//Return : null, array 已经排好序
//void quick_sort_iterative(std::vector<int>& arr) {
//    if (arr.empty()) {
//        return;
//    }
//    int length = static_cast<int>(arr.size());
//    std::stack<int> stk;
//    stk.push(length - 1);
//    stk.push(0);
//    while (!stk.empty()) {
//        int low = stk.top();
//        stk.pop();
//        int high = stk.top();
//        stk.pop();
//        if (low >= high) {
//            continue;
//        }
//        int i = low;
//        int j = high;
//        int key = arr[low];
//        while (i < j) {
//            while (arr[j] > key) {
//                --j;
//            }
//            std::swap(arr[j], arr[i]);
//            while (arr[i] < key) {
//                ++i;
//            }
//            std::swap(arr[i], arr[j]);
//        }
//        stk.push(high);
//        stk.push(i + 1);
//        stk.push(i - 1);
//        stk.push(low);
//    }
//}

void quick_sort_iterative(std::vector<int>& arr) {
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
    quick_sort_recursive(arr, 0, static_cast<int>(arr.size())-1);
    for (auto& elem : arr) {
        std::cout << elem << std::endl;
    }

    // 迭代模式
    arr = {3, 2, 1, 3, 4, 5};
    quick_sort_iterative(arr);
    for (auto& elem : arr) {
        std::cout << elem << std::endl;
    }
}
#endif //SORT_QUICK_SORT_H
