/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_105. Construct Binary Tree from Preorder and Inorder Traversal.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/06 16:32:00
 * @brief https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H
#define INC_1STPROGRAM_LEETCODE_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        int pre_begin = 0;
        int pre_end = preorder.size() - 1;
        int in_begin = 0;
        int in_end = inorder.size() - 1;
        return dfs(preorder, inorder, pre_begin, pre_end, in_begin, in_end);
    }

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pre_begin,
                  int pre_end, int in_begin, int in_end) {
        int root_value = preorder[pre_begin];
        TreeNode *root = new TreeNode(root_value);
        if (pre_begin == pre_end) {
            if (in_begin == in_end && preorder[pre_begin] == inorder[in_begin]) {
                return root;
            } else {
                return nullptr;
            }
        }
        int left_length = 0;
        int in_root_location = in_begin;
        for (; in_root_location <= in_end; ++in_root_location) {
            if (inorder[in_root_location] == root_value) {
                break;
            }
            ++left_length;
        }
        if (in_root_location > in_end) {
            return nullptr;
        }
        if (left_length) {
            root->left = dfs(preorder, inorder, pre_begin + 1, pre_begin + left_length,
                             in_begin, in_root_location - 1);
        }
        if (pre_end - pre_begin - left_length) {
            root->right = dfs(preorder, inorder, pre_begin + left_length + 1, pre_end,
                              in_root_location + 1, in_end);
        }
        return root;
    }
};

void test_construct_tree() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = Solution().buildTree(preorder, inorder);

}

#endif //INC_1STPROGRAM_LEETCODE_105_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H
