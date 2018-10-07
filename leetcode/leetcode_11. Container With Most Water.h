/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_11. Container With Most Water.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/07 14:49:00
 * @brief https://leetcode.com/problems/container-with-most-water/description/
 * @link https://www.youtube.com/watch?v=UwpvInpgFmo
 * */

#ifndef INC_1STPROGRAM_LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
#define INC_1STPROGRAM_LEETCODE_11_CONTAINER_WITH_MOST_WATER_H

#include "../util/header_util.h"

class Solution1 {
public:
    int maxArea(vector<int> &height) {
        /*
         * @brief brute force
         */
        int length = height.size();
        int max_area = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                int temp_area = (j - i) * min(height[j], height[i]);
                if (max_area < temp_area) {
                    max_area = temp_area;
                }
            }
        }
        return max_area;
    }
};

class Solution2 {
public:
    int maxArea(vector<int> &height) {
        /*
         * @brief two pointers, O(n) time complexity
         */
        int length = height.size();
        int max_area = 0;
        int left = 0;
        int right = length - 1;
        while (left < right) {
            int min_height = min(height[left], height[right]);
            max_area = max(min_height * (right - left), max_area);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};

void test_max_area() {
    vector<int> height = {1, 3, 2, 4};
    int max_area = Solution2().maxArea(height);
    cout << max_area << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
