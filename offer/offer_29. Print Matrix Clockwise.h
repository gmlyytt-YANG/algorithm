/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_29. Print Matrix Clockwise.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/15 10:29:00
 * @brief 剑指offer第29题 顺时针打印矩阵
 * */

#ifndef INC_1STPROGRAM_OFFER_29_PRINT_MATRIX_CLOCKWISE_H
#define INC_1STPROGRAM_OFFER_29_PRINT_MATRIX_CLOCKWISE_H

#include "../util/header_util.h"

void print_one_clock(std::vector<std::vector<int>> &matrix, int rows, int cols, int start) {
    int end_x = cols - 1 - start;
    int end_y = rows - 1 - start;
    for (int i = start; i <= end_x; ++i) {
        std::cout << matrix[start][i] << " ";
    }
    for (int i = start + 1; i <= end_y; ++i) {
        std::cout << matrix[i][end_x] << " ";
    }
    for (int i = end_y - 1; i >= start; --i) {
        std::cout << matrix[end_y][i] << " ";
    }
    for (int i = end_y - 1; i >= start + 1; --i) {
        std::cout << matrix[i][start] << " ";
    }
    std::cout << std::endl;
}

void print_matrix(std::vector<std::vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }
    int start = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    while (rows > start * 2 && cols > start * 2) {
        print_one_clock(matrix, rows, cols, start++);
    }
}

void test_print_matrix() {
    std::vector<std::vector<int>> arr = {
            {1,  2,  3,  4,  5},
            {5,  6,  7,  8,  9},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };
    print_matrix(arr);
}

#endif //INC_1STPROGRAM_OFFER_29_PRINT_MATRIX_CLOCKWISE_H
