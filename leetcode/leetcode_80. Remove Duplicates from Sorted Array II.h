/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_80. Remove Duplicates from Sorted Array II.h
 * @author gmlyytt@outlook.com
 * @date 2019/12/26 08:11:48
 * @brief https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
#define INC_1STPROGRAM_LEETCODE_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H

#include "../util/header_util.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int slow = 0;
        int count = 1;
        for (int fast = 1; fast < length; ++fast) {
            if (nums[fast] == nums[slow]) {
                if (count == 1) {
                    ++slow;
                    nums[slow] = nums[fast];
                    ++count;
                }
            } else {
                ++slow;
                nums[slow] = nums[fast];
                count = 1;
            }
        }
        return slow + 1;
    }
};

#endif //INC_1STPROGRAM_LEETCODE_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
