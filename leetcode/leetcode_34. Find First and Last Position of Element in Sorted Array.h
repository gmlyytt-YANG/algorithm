/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_34. Find First and Last Position of Element in Sorted Array.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/17 16:27:00
 * @brief https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define INC_1STPROGRAM_LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H

#include "../util/header_util.h"

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int length = nums.size();
        if (length == 0)
            return {-1, -1};
        int first = left(nums, target);
        int last = right(nums, target);
        if (first != -1 && last != -1) {
            return {first, last};
        } else {
            return {-1, -1};
        }
    }

    int left(vector<int> &nums, int target) {
        int length = nums.size();
        int low = 0;
        int high = length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (nums[high] == target) {
            return high;
        }
        return -1;
    }

    int right(vector<int> &nums, int target) {
        int length = nums.size();
        int low = 0;
        int high = length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2 + 1;
            if (nums[mid] <= target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (nums[low] == target) {
            return low;
        }
        return -1;
    }
};

void test_search_range() {
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = Solution().searchRange(arr, target);
}

#endif //INC_1STPROGRAM_LEETCODE_34_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
