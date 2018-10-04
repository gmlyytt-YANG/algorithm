// Created by Li,Yang(Duer04) on 2018/8/18.
// Author: liyang
//
// 平衡二叉树

#ifndef INC_1STPROGRAM_OFFER_51_BALANCE_TREE_H
#define INC_1STPROGRAM_OFFER_51_BALANCE_TREE_H

#include <iostream>
#include "../util/tree_util.h"

bool tree_is_balanced(TreeNode* root, int& depth) {
    if (!root) {
        depth = 0;
        return true;
    }
    int left = 0;
    int right = 0;
    if (tree_is_balanced(root->left, left) && tree_is_balanced(root->right, right)) {
        int depth_diff = left - right;
        depth = left > right ? (left + 1) : (right + 1);
        if (depth_diff <= 1 && depth_diff >= -1) {
            return true;
        }
    }
    return false;
}

void test_tree_is_balanced() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);

    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);

    int depth = 0;
    std::cout << tree_is_balanced(node1, depth) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_51_BALANCE_TREE_H
