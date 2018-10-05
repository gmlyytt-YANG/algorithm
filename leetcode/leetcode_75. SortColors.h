/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_75. SortColors.h
 * @author gmlyytt@outlook.com
 * @date 2018/07/16 10:01:00
 * @brief https://leetcode.com/problems/sort-colors/description/
 * */

#ifndef INC_1STPROGRAM_SORTCOLORS_HPP
#define INC_1STPROGRAM_SORTCOLORS_HPP

#include "../util/header_util.h"

class Solution {
public:
    void print(vector<int> &nums) {
        for (auto elem: nums)
            cout << elem << " ";
        cout << endl;
    }

    void sortColors(vector<int> &nums) {
        auto length = static_cast<int>(nums.size());
        if (length <= 1)
            return;
        int head = 0, tail = length - 1;
        for (int i = 0; i <= tail; ++i) {
            if (nums[i] == 2)
                swap(nums[i--], nums[tail--]);
            else if (nums[i] == 0)
                swap(nums[i], nums[head++]);
            print(nums);
        }
    }
};

#endif //INC_1STPROGRAM_SORTCOLORS_HPP
