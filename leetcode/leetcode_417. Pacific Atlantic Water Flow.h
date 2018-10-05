/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_417. Pacific Atlantic Water Flow.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/05 10:01:00
 * @brief http://note.youdao.com/noteshare?id=ccf6ba669716019998e2748e7fff6ba7&sub=EEF2BEC832914FA7BE2FA03F0B11A057
 * */

#ifndef ALGORITHM_CXX_LEETCODE_417_PACIFIC_ATLANTIC_WATER_FLOW_H
#define ALGORITHM_CXX_LEETCODE_417_PACIFIC_ATLANTIC_WATER_FLOW_H

#include "../util/header_util.h"

class Solution {
public:
    void dfs(vector<pair<int, int>> &result, vector<vector<int>> &matrix,
             int row, int col, int rows, int cols) {
        pair<int, int> temp({row, col});
        if (row < 0 || col < 0 || row >= rows || col >= cols
            || find(result.begin(), result.end(), temp) != result.end()) {
            return;
        }
        result.emplace_back(row, col);
        if (row > 0 && matrix[row][col] <= matrix[row - 1][col]) {
            dfs(result, matrix, row - 1, col, rows, cols);
        }
        if (row < rows - 1 && matrix[row][col] <= matrix[row + 1][col]) {
            dfs(result, matrix, row + 1, col, rows, cols);
        }
        if (col > 0 && matrix[row][col] <= matrix[row][col - 1]) {
            dfs(result, matrix, row, col - 1, rows, cols);
        }
        if (col < cols - 1 && matrix[row][col] <= matrix[row][col + 1]) {
            dfs(result, matrix, row, col + 1, rows, cols);
        }
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> pacific_result;
        vector<pair<int, int>> atlantic_result;
        if (!rows || !cols) {
            return pacific_result;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || j == 0) {
                    dfs(pacific_result, matrix, i, j, rows, cols);
                }
                if (i == rows - 1 || j == cols - 1) {
                    dfs(atlantic_result, matrix, i, j, rows, cols);
                }
            }
        }
        for (auto iter = pacific_result.begin(); iter != pacific_result.end();) {
            if (find(atlantic_result.begin(), atlantic_result.end(), *iter)
                == atlantic_result.end()) {
                iter = pacific_result.erase(iter);
            } else {
                ++iter;
            }
        }
        return pacific_result;
    }
};

class Solution2 {
public:
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &ocean,
             int i, int j) {
        if (ocean[i][j]) {
            return;
        }
        ocean[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int new_i = i + position[k].first;
            int new_j = j + position[k].second;
            if (new_i < 0 || new_i >= matrix.size() || new_j < 0
                || new_j >= matrix[0].size()) {
                continue;
            }
            if (matrix[i][j] <= matrix[new_i][new_j]) {
                dfs(matrix, ocean, new_i, new_j);
            }
        }
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<pair<int, int>> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    const vector<pair<int, int>> position = {{-1, 0},
                                             {1,  0},
                                             {0,  -1},
                                             {0,  1}};
};

void test_pacific_atlantic() {
    vector<vector<int>> matrix = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
    };
    vector<pair<int, int>> result = Solution2().pacificAtlantic(matrix);
}


#endif //ALGORITHM_CXX_LEETCODE_417_PACIFIC_ATLANTIC_WATER_FLOW_H
