// Created by Li,Yang(Duer04) on 2018/8/5.
// Author: liyang
// 计数排序

#ifndef SORT_COUNT_SORT_H
#define SORT_COUNT_SORT_H

#include <iostream>
#include <vector>

//template <class T>
//int find_max(std::vector<T>& arr) {
//    if (arr.empty()) {
//        return -1;
//    }
//
//    T val = arr[0];
//    for (int i = 0; i < arr.size(); ++i) {
//        if (arr[i] > val) {
//            val = arr[i];
//        }
//    }
//    return static_cast<int>(val);
//}
//
////Summary:  计数排序
////Parameters:
////       A: 待排序的数组
////		 B: 排序后的数组
////Return : null
//
////Details:
////		C 中一开始存放的是A中每个元素出现的次数
////		而后C[A[j]]中统计的是A 中小于等于A[j]的元素个数
////		B 把C的下标和下标对应的元素互换，之后C[A[j]]--,即可得到对应结果，
//void count_sort(std::vector<int>& A, std::vector<int>& B) {
//    std::vector<int> C(find_max(A) + 1, 0);
//    for (auto& elem: A) {
//        ++C[elem];
//    }
//    for (int i = 1; i < C.size(); ++i) {
//        C[i] += C[i - 1];
//    }
//
//    // 从后到前遍历是为了保证算法的稳定性
//    for (int i = A.size(); i >= 0; --i) {
//        B[C[A[i]] - 1] = A[i];
//        --C[A[i]];
//    }
//}

template <class T>
T find_max(std::vector<T>& arr) {
    T Max = arr[0];
    for (auto& elem : arr) {
        if (Max < elem) {
            Max = elem;
        }
    }
    return Max;
}

void count_sort(std::vector<int>& arr, std::vector<int>& B) {
    int Max = find_max(arr);
    std::vector<int> C(Max + 1, 0);
    for (auto& elem : arr) {
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
    std::vector<int> A = {1,2,3,4,6,5,9,8,7};
    std::vector<int> B(A.size(), 0);
    count_sort(A, B);

    for (auto& elem: B) {
        std::cout << elem  << std::endl;
    }
}
#endif //SORT_COUNT_SORT_H
