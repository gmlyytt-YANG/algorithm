/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_130. Surrounded Regions.h
 * @author liyang921126@gmail.com
 * @date 2018/10/02 14:31:00
 * @brief leetcode 130
 * @link https://leetcode.com/problems/surrounded-regions/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_130_SURROUNDED_REGIONS_H
#define INC_1STPROGRAM_LEETCODE_130_SURROUNDED_REGIONS_H

#include "../util/header_util.h"

class Solution {
public:
    template<typename T>
    void print(vector<vector<T>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(vector<vector<char>> &board, int row, int col, int rows, int cols) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '%';
        dfs(board, row + 1, col, rows, cols);
        dfs(board, row - 1, col, rows, cols);
        dfs(board, row, col + 1, rows, cols);
        dfs(board, row, col - 1, rows, cols);
    }

    void solve(vector<vector<char>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        if (!rows || !cols) {
            return;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    dfs(board, i, j, rows, cols);
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == '%') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        print(board);
    }
};

void test_board_X_O() {
    vector<vector<char>> board =
            Solution().solve(board);
}

#endif //INC_1STPROGRAM_LEETCODE_130_SURROUNDED_REGIONS_H
