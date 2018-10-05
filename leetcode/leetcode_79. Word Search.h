/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_79. Word Search.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/22 10:01:00
 * @brief https://leetcode.com/problems/word-search/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_79_WORD_SEARCH_H
#define INC_1STPROGRAM_LEETCODE_79_WORD_SEARCH_H

#include <iostream>
#include <vector>

bool find_path_core(std::vector<std::vector<char>> &matrix, int row, int col,
                    int rows, int cols, std::vector<std::vector<bool>> &visited,
                    int &current_location, std::string &str) {
    if (current_location == str.size()) {
        return true;
    }
    if (row < 0 || row >= rows || col < 0 || col >= cols
        || visited[row][col] || str[current_location] != matrix[row][col]) {
        return false;
    }

    ++current_location;
    visited[row][col] = true;
    bool found = find_path_core(matrix, row, col - 1, rows, cols, visited, current_location, str)
                 || find_path_core(matrix, row, col + 1, rows, cols, visited, current_location, str)
                 || find_path_core(matrix, row - 1, col, rows, cols, visited, current_location, str)
                 || find_path_core(matrix, row + 1, col, rows, cols, visited, current_location, str);
    if (!found) {
        --current_location;
        visited[row][col] = false;
    }
    return found;
}

bool find_path(std::vector<std::vector<char>> &matrix, std::string &str) {
    if (str.empty() || matrix.empty() || matrix[0].empty()) {
        return false;
    }
    bool found = false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int current_location = 0;
    std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            found = find_path_core(matrix, row, col, rows, cols, visited, current_location, str);
            if (found) {
                break;
            }
        }
    }
    return found;
}

void test_matrix_route() {
    std::vector<std::vector<char>> matrix = {
            {'A', 'B', 'T'},
            {'G', 'C', 'F'},
            {'C', 'S', 'J'},
            {'D', 'E', 'H'}
    };
    std::string str = "ABFB";
    std::cout << find_path(matrix, str) << std::endl;
}

#endif //INC_1STPROGRAM_LEETCODE_79_WORD_SEARCH_H
