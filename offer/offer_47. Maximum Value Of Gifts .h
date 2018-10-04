// Created by Li,Yang(Duer04) on 2018/8/18.
// Author: liyang
//
// 礼物的最大值

#ifndef INC_1STPROGRAM_OFFER_47_MAXIMUM_VALUE_OF_GIFTS_H
#define INC_1STPROGRAM_OFFER_47_MAXIMUM_VALUE_OF_GIFTS_H

#include <iostream>
#include <vector>

int max_value_of_gifts(std::vector<std::vector<int>>& gifts) {
    int rows = gifts.size();
    int cols = gifts[0].size();
    if (rows == 0 || cols == 0) {
        return 0;
    }
    std::vector<int> max_values(cols, 0);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int left = 0;
            int up = 0;
            if (row > 0) {
                up = max_values[col];
            }
            if (col > 0) {
                left = max_values[col - 1];
            }
            max_values[col] = std::max(left, up) + gifts[row][col];
        }
    }
    return max_values[cols - 1];
}

void test_max_value_of_gifts() {
    std::vector<std::vector<int>> arr = {
            { 1, 10, 3, 8 },
            { 12, 2, 9, 6 },
            { 5, 7, 4, 11 },
            { 3, 7, 16, 5 }
    };

    std::cout << max_value_of_gifts(arr) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_47_MAXIMUM_VALUE_OF_GIFTS_H
