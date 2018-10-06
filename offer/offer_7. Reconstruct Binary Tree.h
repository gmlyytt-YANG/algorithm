/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_7. Reconstruct Binary Tree.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/15 10:29:00
 * @brief 剑指offer第7题 重构二叉树
 * */

#ifndef INC_1STPROGRAM_OFFER_7_RECONSTRUCT_BINARY_TREE_H
#define INC_1STPROGRAM_OFFER_7_RECONSTRUCT_BINARY_TREE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class SolutionPreIn {
public:
    /*
     * @brief build tree based on preorder and inorder
     *
     * @param preorder
     * @param inorder
     * @return tree root
     */
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

class SolutionInPost {
public:
    /*
     * @brief build tree based on inorder and postorder
     *
     * @param inorder
     * @param postorder
     * @return tree root
     */
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
    TreeNode* root = SolutionInPost().buildTree(inorder, postorder);
}

#endif //INC_1STPROGRAM_OFFER_7_RECONSTRUCT_BINARY_TREE_H
