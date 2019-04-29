/*************************************************************************
 *
 * Copyright (c) 2019 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_108. Convert Sorted Array to Binary Search Tree.h
 * @author gmlyytt@outlook.com
 * @date 2019/4/29
 * @brief https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * */
#ifndef INC_1STPROGRAM_LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
#define INC_1STPROGRAM_LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* result = dfs(nums, 0, nums.size() - 1);
        return result;
    }

    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left > right || nums.empty()) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        auto* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, left, mid - 1);
        root->right = dfs(nums, mid + 1, right);

        return root;
    }
};

void test_sorted_array_to_bST() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* result = Solution().sortedArrayToBST(nums);
    cout << result << endl;
};
#endif //INC_1STPROGRAM_LEETCODE_108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
