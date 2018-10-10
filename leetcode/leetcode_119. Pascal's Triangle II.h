/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_119. Pascal's Triangle II.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/10 9:26:00
 * @brief https://leetcode.com/problems/pascals-triangle-ii/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_119_PASCAL_S_TRIANGLE_II_H
#define INC_1STPROGRAM_LEETCODE_119_PASCAL_S_TRIANGLE_II_H

#include "../util/header_util.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            // store last state of result
            vector<int> last_result(result);
            for (int j = 1; j <= rowIndex / 2; ++j) {
                result[j] += last_result[j - 1];
            }
            int index = 1;
            for (int j = rowIndex / 2 + 1; j <= rowIndex; ++j) {
                result[j] = result[rowIndex - j];
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                result[j] += result[j - 1];
            }
        }
        return result;
    }
};

void test_get_row() {
    int rowIndex = 5;
    vector<int> result = Solution().getRow(rowIndex);
    cout << result << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_119_PASCAL_S_TRIANGLE_II_H
