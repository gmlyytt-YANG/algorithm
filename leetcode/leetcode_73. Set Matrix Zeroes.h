/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_73. Set Matrix Zeroes.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/09 9:34:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_73_SET_MATRIX_ZEROES_H
#define INC_1STPROGRAM_LEETCODE_73_SET_MATRIX_ZEROES_H

#include "../util/header_util.h"

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> positions;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    positions.push_back({i, j});
                }
            }
        }
        for (auto &position : positions) {
            for (int j = 0; j < cols; ++j) {
                matrix[position.first][j] = 0;
            }
            for (int i = 0; i < rows; ++i) {
                matrix[i][position.second] = 0;
            }
        }
    }

    void setZeroes_best(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < rows; ++i) {
            // matrix[i][0] won't be re-written
            // because the order of traversing is from up to down.
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j > 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // col0 == 0 means the first col should be all 0.
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};

void test_set_zeroes() {
    vector<vector<int>> matrix = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
    };
    Solution().setZeroes_best(matrix);
}

#endif //INC_1STPROGRAM_LEETCODE_73_SET_MATRIX_ZEROES_H
