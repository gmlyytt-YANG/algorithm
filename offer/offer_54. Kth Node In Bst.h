/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_54. Kth Node In Bst.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/16 9:34:00
 * @brief 剑指offer54题 二叉搜索树中序遍历的第k个节点
 * */

#ifndef INC_1STPROGRAM_OFFER_54_KTH_NODE_IN_BST_H
#define INC_1STPROGRAM_OFFER_54_KTH_NODE_IN_BST_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

TreeNode *kth_node_in_bst(TreeNode *root, int &k) {
    if (!root || k <= 0) {
        return nullptr;
    }
    std::stack<TreeNode *> stk;
    while (root || !stk.empty()) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        if (!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            if (k == 1) {
                return top;
            }
            --k;
            root = top->right;
        }
    }
    return nullptr;
}

void test_kth_node_in_bst() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);

    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);

    int k = 3;
    TreeNode *node = kth_node_in_bst(node1, k);
}

#endif //INC_1STPROGRAM_OFFER_54_KTH_NODE_IN_BST_H
