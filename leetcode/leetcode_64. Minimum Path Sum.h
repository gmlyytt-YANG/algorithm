/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_64. Minimum Path Sum.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/25 10:01:00
 * @brief https://leetcode.com/problems/minimum-path-sum/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_64_MINIMUM_PATH_SUM_H
#define INC_1STPROGRAM_LEETCODE_64_MINIMUM_PATH_SUM_H

#include "../util/header_util.h"

vector<int> minPathSum(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> final_result;
    if (rows == 0 || cols == 0) {
        return final_result;
    }
    vector<vector<int>> result = grid;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (i && j) {
                result[i][j] += min(result[i - 1][j], result[i][j - 1]);
            } else if (i) {
                result[i][j] += result[i - 1][j];
            } else if (j) {
                result[i][j] += result[i][j - 1];
            }
        }
    }
    int row = rows - 1;
    int col = cols - 1;
    final_result.push_back(grid[row][col]);
    while (row > 0 || col > 0) {
        int key = result[row][col] - grid[row][col];
        if (row > 0 && key == result[row - 1][col]) {
            row = row - 1;
        } else if (col > 0 && key == result[row][col - 1]) {
            col = col - 1;
        }
        final_result.push_back(grid[row][col]);
    }
    reverse(final_result.begin(), final_result.end());
    return final_result;
}

void test_minPathSum() {
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    vector<int> result = minPathSum(grid);

}

#endif //INC_1STPROGRAM_LEETCODE_64_MINIMUM_PATH_SUM_H
