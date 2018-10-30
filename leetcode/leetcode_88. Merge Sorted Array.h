/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_88. Merge Sorted Array.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/30 20:26:00
 * @brief https://leetcode.com/problems/merge-sorted-array/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_88_MERGE_SORTED_ARRAY_H
#define INC_1STPROGRAM_LEETCODE_88_MERGE_SORTED_ARRAY_H

#include "../util/header_util.h"

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int size = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        // backward compute
        while (i >= 0 && j >= 0) {
            nums1[size--] = (nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]);
        }
        while (i >= 0) {
            nums1[size--] = nums1[i--];
        }
        while (j >= 0) {
            nums1[size--] = nums2[j--];
        }
    }
};

void test_merge() {
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {4, 5, 6};
    int m = 3;
    int n = 3;
    Solution().merge(arr1, m, arr2, n);
}

#endif //INC_1STPROGRAM_LEETCODE_88_MERGE_SORTED_ARRAY_H
