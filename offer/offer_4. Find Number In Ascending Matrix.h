/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_4. Find Number In Ascending Matrix.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/15 10:29:00
 * @brief 剑指offer第4题 二位数组的查找
 * */

#ifndef INC_1STPROGRAM_OFFER_4_FIND_NUMBER_IN_ASCENDING_MATRIX_H
#define INC_1STPROGRAM_OFFER_4_FIND_NUMBER_IN_ASCENDING_MATRIX_H

#include "../util/header_util.h"

bool find_in_ascending_matrix(std::vector<std::vector<int>> &arr, int num) {
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
