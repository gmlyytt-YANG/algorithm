/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_200. Number of Islands.h
 * @author liyang921126@gmail.com
 * @date 2018/10/02 11:10:00
 * @brief leetcode 200
 * @link https://leetcode.com/problems/number-of-islands/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_200_NUMBER_OF_ISLANDS_H
#define INC_1STPROGRAM_LEETCODE_200_NUMBER_OF_ISLANDS_H

#include "../util/header_util.h"

class Solution {
public:
    void dfs(vector<vector<string>> &grid, vector<vector<bool>> &visited, int row,
             int col, int rows, int cols) {
        if (row < 0 || row >= rows || col < 0 || col >= cols
            || grid[row][col] == "0" || visited[row][col]) {
            return;
        }
        visited[row][col] = true;
        dfs(grid, visited, row + 1, col, rows, cols);
        dfs(grid, visited, row - 1, col, rows, cols);
        dfs(grid, visited, row, col + 1, rows, cols);
        dfs(grid, visited, row, col - 1, rows, cols);
    }

    int numIslands(vector<vector<string>> &grid) {
        int rows = grid.size();
        if (!rows) {
            return 0;
        }
        int cols = grid[0].size();
        if (!cols) {
            return 0;
        }
        int count = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == "1" && !visited[i][j]) {
                    ++count;
                    dfs(grid, visited, i, j, rows, cols);
                }
            }
        }
        return count;
    }
};

void test_num_islands() {
    vector<vector<string>> grid = {{"1", "1", "1", "1", "0"},
                                   {"1", "1", "0", "1", "0"},
                                   {"1", "1", "0", "0", "0"},
                                   {"0", "0", "0", "0", "0"}};
    int count = Solution().numIslands(grid);
    cout << count << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_200_NUMBER_OF_ISLANDS_H
