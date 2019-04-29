/*************************************************************************
 *
 * Copyright (c) 2019 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_118. Pascal's Triangle.h
 * @author gmlyytt@outlook.com
 * @date 2019/4/29
 * @brief https://leetcode.com/problems/pascals-triangle/
 * */
#ifndef INC_1STPROGRAM_LEETCODE_118_PASCAL_S_TRIANGLE_H
#define INC_1STPROGRAM_LEETCODE_118_PASCAL_S_TRIANGLE_H

#include "../util/header_util.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int index = 0; index < numRows; ++index) {
            vector<int> elem_result(index+ 1, 1);
            for (int inner_index = 1; inner_index < index; ++inner_index) {
                elem_result[inner_index] = result[index - 1][inner_index - 1] + result[index - 1][inner_index];
            }
            result.push_back(elem_result);
        }

        return result;
    }
};

void test_generate() {
    int numRows = 5;
    vector<vector<int>> result = Solution().generate(numRows);
    print_2_dim_vector(result);
}
#endif //INC_1STPROGRAM_LEETCODE_118_PASCAL_S_TRIANGLE_H
