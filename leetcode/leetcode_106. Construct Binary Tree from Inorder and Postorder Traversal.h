/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_106. Construct Binary Tree from postorder and Postorder Traversal.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/06 17:13:00
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_106_CONSTRUCT_BINARY_TREE_FROM_postorder_AND_POSTORDER_TRAVERSAL_H
#define INC_1STPROGRAM_LEETCODE_106_CONSTRUCT_BINARY_TREE_FROM_postorder_AND_POSTORDER_TRAVERSAL_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        int in_begin = 0;
        int in_end = inorder.size() - 1;
        int post_begin = 0;
        int post_end = postorder.size() - 1;
        return dfs(inorder, postorder, in_begin, in_end, post_begin, post_end);
    }

    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int in_begin,
                  int in_end, int post_begin, int post_end) {
        int root_value = postorder[post_end];
        TreeNode *root = new TreeNode(root_value);
        if (post_begin == post_end) {
            if (in_begin == in_end && postorder[post_begin] == inorder[in_begin]) {
                return root;
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
            root->left = dfs(inorder, postorder, in_begin, in_root_location - 1,
                             post_begin, post_begin + left_length - 1);
        }
        if (post_end - post_begin - left_length) {
            root->right = dfs(inorder, postorder, in_root_location + 1, in_end,
                              post_begin + left_length, post_end - 1);
        }
        return root;
    }
};

void test_construct_tree() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = Solution().buildTree(inorder, postorder);
}

#endif //INC_1STPROGRAM_LEETCODE_106_CONSTRUCT_BINARY_TREE_FROM_postorder_AND_POSTORDER_TRAVERSAL_H
