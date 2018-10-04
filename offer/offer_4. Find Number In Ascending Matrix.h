// Created by Li,Yang(Duer04) on 2018/8/15.
// Author: liyang
//
// 二位数组的查找

#ifndef INC_1STPROGRAM_OFFER_4_FIND_NUMBER_IN_ASCENDING_MATRIX_H
#define INC_1STPROGRAM_OFFER_4_FIND_NUMBER_IN_ASCENDING_MATRIX_H

#include <iostream>
#include <vector>

//bool find_in_ascending_matrix(std::vector<std::vector<int>>& arr, int num) {
//    int rows = arr.size();
//    int cols = arr[0].size();
//    int row = 0;
//    int col = cols - 1;
//    while (row < rows && col >= 0 && num != arr[row][col]) {
//        if (num > arr[row][col]) {
//            ++row;
//        } else {
//            --col;
//        }
//    }
//    if (row < rows && col >= 0) {
//        return true;
//    } else {
//        return false;
//    }
//}

bool find_in_ascending_matrix(std::vector<std::vector<int>>& arr, int num) {
    if (arr.size() == 0 || arr[0].size() == 0) {
        return false;
    }
    int rows = arr.size();
    int cols = arr.size();
    int row = 0;
    int col = cols - 1;
    bool found = false;
    while (row < rows && col >= 0) {
        if (arr[row][col] == num) {
            found = true;
            break;
        } else if (arr[row][col] < num) {
            ++row;
        } else {
            --col;
        }
    }
    return found;
}

void test_find_in_ascending_matrix() {
    std::vector<std::vector<int>> arr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    std::cout << find_in_ascending_matrix(arr, 8) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_4_FIND_NUMBER_IN_ASCENDING_MATRIX_H
