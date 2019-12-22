/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_27. Remove Element.h
 * @author gmlyytt@outlook.com
 * @date 2019/12/22 10:32:29
 * @brief https://leetcode.com/problems/remove-element/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_27_REMOVE_ELEMENT_H
#define INC_1STPROGRAM_LEETCODE_27_REMOVE_ELEMENT_H

#include "../util/header_util.h"

class Solution {
public:
    int removeElement_slow_fast_pointer(vector<int> &nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        return slow;
    }

    int removeElement_low_high_pointer(vector<int> &nums, int val) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] == val) {
                nums[low] = nums[high];
                --high;
            } else {
                ++low;
            }
        }
        return low;
    }

};

#endif //INC_1STPROGRAM_LEETCODE_27_REMOVE_ELEMENT_H
