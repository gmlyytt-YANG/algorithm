/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_576. Out of Boundary Paths.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/06 10:29:00
 * @brief https://leetcode.com/problems/out-of-boundary-paths/description/
 * @link http://note.youdao.com/noteshare?id=16188db0ea35a7c7d8e318636bb842b1&sub=5CB3C5ECB77348309CD9F6AE9494CFC0
 * */

#ifndef INC_1STPROGRAM_LEETCODE_576_OUT_OF_BOUNDARY_PATHS_H
#define INC_1STPROGRAM_LEETCODE_576_OUT_OF_BOUNDARY_PATHS_H

#include "../util/header_util.h"

class Solution {
public:
    int find_paths_TLE(int m, int n, int N, int i, int j) {
        if (!m || !n || i < 0 || i >= m || j < 0 || j >= n) {
            return -1;
        }
        int moves = 0;
        dfs(m, n, N, i, j, moves);
        return moves;
    }

private:
    void dfs(int m, int n, int N, int i, int j, int &moves) {
        if (N < 0) {
            return;
        }
        if (i < 0 || i >= m || j < 0 || j >= n) {
            ++moves;
            return;
        }
        dfs(m, n, N - 1, i - 1, j, moves);
        dfs(m, n, N - 1, i + 1, j, moves);
        dfs(m, n, N - 1, i, j - 1, moves);
        dfs(m, n, N - 1, i, j + 1, moves);
    }
};

class Solution2 {
public:
    int find_paths(int m, int n, int N, int i, int j) {
        if (!m || !n || i < 0 || i >= m || j < 0 || j >= n) {
            return -1;
        }
        vector<vector<vector<int>>> dp
                = vector<vector<vector<int>>>(50, vector<vector<int>>(50, vector<int>(51, -1)));
        return dfs(m, n, N, i, j, dp);
    }

    int dfs(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp) {
        int mod = 1e9 + 7;
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if (N <= 0) {
            return 0;
        }
        if (dp[i][j][N] != -1) {
            return dp[i][j][N];
        }
        int result = 0;
        for (int k = 0; k < 4; ++k) {
            int new_i = i + position[k].first;
            int new_j = j + position[k].second;
            result += dfs(m, n, N - 1, new_i, new_j, dp);
            result %= mod;
        }
        return dp[i][j][N] = result;
    }

private:
    const vector<pair<int, int>> position = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

void test_find_paths() {
    int m = 8;
    int n = 7;
    int N = 16;
    int i = 1;
    int j = 5;
    cout << Solution2().find_paths(m, n, N, i, j) << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_576_OUT_OF_BOUNDARY_PATHS_H
