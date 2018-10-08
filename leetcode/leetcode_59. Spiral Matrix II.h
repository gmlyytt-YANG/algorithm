/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_59. Spiral Matrix II.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/08 16:37:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_59_SPIRAL_MATRIX_II_H
#define INC_1STPROGRAM_LEETCODE_59_SPIRAL_MATRIX_II_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (n <= 0) {
            return result;
        }
        int start = 0;
        int base = 1;
        while (start * 2 < n) {
            int end_x = n - 1 - start;
            int end_y = n - 1 - start;
            for (int i = start; i <= end_x; ++i) {
                result[start][i] = base++;
            }
            for (int i = start + 1; i <= end_y; ++i) {
                result[i][end_x] = base++;
            }
            for (int i = end_x - 1; i >= start; --i) {
                result[end_y][i] = base++;
            }
            for (int i = end_y - 1; i >= start + 1; --i) {
                result[i][start] = base++;
            }
            ++start;
        }
        return result;
    }
};

void test_spiral_matrix_II() {
    int n = 4;
    vector<vector<int>> result = Solution().generateMatrix(n);
}

#endif //INC_1STPROGRAM_LEETCODE_59_SPIRAL_MATRIX_II_H
