// Created by Li,Yang(Duer04) on 2018/8/29.
// Author: liyang
//
// 机器人的运动范围

#ifndef INC_1STPROGRAM_OFFER_13_RANGE_OF_ROBOT_H
#define INC_1STPROGRAM_OFFER_13_RANGE_OF_ROBOT_H

#include <iostream>
#include <vector>

int count(int row, int col) {
    int count = 0;
    while (row) {
        count += row % 10;
        row /= 10;
    }
    while (col) {
        count += col % 10;
        col /= 10;
    }
    return count;
}

int robot_range_core(int threshold, int m, int n,
        int row, int col, std::vector<vector<bool>>& visited) {
    if (row > m - 1 || col > n - 1|| count(row, col) > threshold || visited[row][col]) {
        return 0;
    }
    visited[row][col] = true;
    return 1 + robot_range_core(threshold, m, n, row, col + 1, visited)
             + robot_range_core(threshold, m, n, row + 1, col, visited);
}

int robot_range(int threshold, int m, int n) {
    if (threshold < 0 || m < 0 || n < 0) {
        return 0;
    }
    if (threshold == 0) {
        return 1;
    }
    std::vector<vector<bool>> visited(m, std::vector<bool>(n, false));
    return robot_range_core(threshold, m, n, 0, 0, visited);
}

void test_robot_range() {
    int m = 100;
    int n = 1;
    int threshold = 15;
    int result = robot_range(threshold, m, n);
}
#endif //INC_1STPROGRAM_OFFER_13_RANGE_OF_ROBOT_H
