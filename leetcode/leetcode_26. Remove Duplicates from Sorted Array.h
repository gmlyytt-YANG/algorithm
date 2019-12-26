/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_26. Remove Duplicates from Sorted Array.h
 * @author gmlyytt@outlook.com
 * @date 2019/12/26 08:00:10
 * @brief https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * @tutorial https://github.com/gmlyytt-YANG/algorithm/blob/master/tutorial/leetcode/leetcode_26.%20Remove%20Duplicates%20from%20Sorted%20Array.md
 * */

#ifndef INC_1STPROGRAM_LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define INC_1STPROGRAM_LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H

#include "../util/header_util.h"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int slow = 0;
        for (int fast = 1; fast < length; ++fast) {
            if (nums[slow] != nums[fast]) {
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};

#endif //INC_1STPROGRAM_LEETCODE_26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
