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

TreeNode *construct_tree_core(std::vector<int> &pre, std::vector<int> &in,
                              int pre_begin, int pre_end, int in_begin, int in_end) {
    TreeNode *root = new TreeNode(pre[pre_begin]);
    int root_value = root->val;

    // 树上只有一个节点
    if (pre_begin == pre_end) {
        if (in_begin == in_end && pre[pre_begin] == in[in_begin]) {
            return root;
        } else {
            return nullptr;
        }
    }

    // 找到中序遍历的根节点位置
    int root_in_location = in_begin;
    int left_length = 0;
    for (int i = in_begin + 1; i <= in_end; ++i) {
        ++left_length;
        if (in[i] == root_value) {
            root_in_location = i;
            break;
        }
    }

    // 在中序遍历中根本找不到根节点
    if (root_in_location == in_begin) {
        return nullptr;
    }

    if (left_length) {
        root->left = construct_tree_core(pre, in, pre_begin + 1,
                                         pre_begin + left_length, in_begin, root_in_location - 1);
    }
    if (pre_end - pre_begin - left_length) {
        root->right = construct_tree_core(pre, in, pre_begin + left_length + 1, pre_end,
                                          root_in_location + 1, in_end);
    }
    return root;
}

TreeNode *reconstruct_tree(std::vector<int> &pre, std::vector<int> &in) {
    if (pre.empty() || in.empty() || pre.size() != in.size()) {
        return nullptr;
    }
    return construct_tree_core(pre, in, 0, pre.size() - 1, 0, in.size() - 1);
}

void test_reconstruct_tree() {
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    TreeNode *result = reconstruct_tree(pre, in);
}

#endif //INC_1STPROGRAM_OFFER_7_RECONSTRUCT_BINARY_TREE_H
