/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode. 189. Rotate Array.h
 * @author gmlyytt@outlook.com
 * @date 2019/12/27 18:01:36
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_189_ROTATE_ARRAY_H
#define INC_1STPROGRAM_LEETCODE_189_ROTATE_ARRAY_H

#include "../util/header_util.h"

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length <= 1 || k % length == 0) {
            return;
        }
        int start = 0;
        int pre = nums[0];
        int cur = nums[0];
        int index = 0;
        for (int i = 0; i < length; ++i) {
            pre = cur;
            index = (index + k) % length;
            cur = nums[index];
            nums[index] = pre;
            if (index == start) {
                ++start;
                index = start;
                cur = nums[index];
            }
        }
    }

    void rotate2(vector<int> &nums, int k) {
        int length = nums.size();

        if (length == 0) {
            return;
        }
        k %= length;
        std::reverse(nums.begin(), nums.begin() + length - k);
        std::reverse(nums.begin() + length - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

#endif //INC_1STPROGRAM_LEETCODE_189_ROTATE_ARRAY_H
