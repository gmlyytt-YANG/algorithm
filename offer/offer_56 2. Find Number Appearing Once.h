// Created by Li,Yang(Duer04) on 2018/8/9.
// Author: liyang
//
// 一个数组中除了一个元素出现一次之外都出现三次，找出这个数字

#ifndef INC_1STPROGRAM_OFFER_56_2_FIND_NUMBER_APPEARING_ONCE_H
#define INC_1STPROGRAM_OFFER_56_2_FIND_NUMBER_APPEARING_ONCE_H

#include <iostream>
#include <vector>

int find_number_appearing_once(std::vector<int>& arr) {
    if (arr.empty()) {
        exit(-1);
    }
    std::vector<int> bit_sum(32, 0);
    for (auto& elem : arr) {
        int base = 1;
        for (int index = 0; index < 32; ++index) {
            int bit = base & elem;
            if (bit != 0) {
                bit_sum[index] += 1;
            }
            base = (base << 1);
        }
    }
    int result = 0;
    int base = 1;
    for (auto& elem : bit_sum) {
        int true_num = elem % 3;
        result += true_num * base;
        base = base << 1;
    }
    return result;
}
//int find_number_appearing_once(std::vector<int>& arr) {
//    if (arr.empty()) {
//        std::cout << "invalid parameters" << std::endl;
//        return -1;
//    }
//    int result = 0;
//    std::vector<int> bit_sum(32, 0);
//    for (auto& elem : arr) {
//        int bit_one_hot = 1;
//        for (int i = 31; i >= 0; --i) {
//            int bit_result = bit_one_hot & elem;
//            if (bit_result) {
//                bit_sum[i] += 1;
//            }
//            bit_one_hot = bit_one_hot << 1;
//        }
//    }
//    for (int i = 0; i < 32; ++i) {
//        result = result << 1;
//        result += bit_sum[i] % 3;
//    }
//    return result;
//}

void test_find_number_appearing_once() {
    std::vector<int> arr = {1, 3, 4, 3, 4, 3, 4, 5, 5, 5};
    int result = find_number_appearing_once(arr);
    std::cout << result << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_56_2_FIND_NUMBER_APPEARING_ONCE_H
