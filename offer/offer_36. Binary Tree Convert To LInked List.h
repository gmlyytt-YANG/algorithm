/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_36. Binary Tree Convert To LInked List.h
 * @author gmlyytt@outlook.com
 * @date 2018/7/31 16:32:00
 * @brief 把二叉搜索树转换为双向链表
 * */

#ifndef INC_1STPROGRAM_OFFER_36_BINARY_TREE_CONVERT_TO_LINKED_LIST_H
#define INC_1STPROGRAM_OFFER_36_BINARY_TREE_CONVERT_TO_LINKED_LIST_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

void binary_tree_2_linked_list_core(TreeNode *root, TreeNode **last_node) {
    if (!root) {
        return;
    }
    if (root->left) {
        binary_tree_2_linked_list_core(root->left, last_node);
    }
    root->left = *last_node;
    if (*last_node) {
        (*last_node)->right = root;
    }
    *last_node = root;
    if (root->right) {
        binary_tree_2_linked_list_core(root->right, last_node);
    }

}

TreeNode *binary_tree_2_linked_list(TreeNode *root) {
    if (!root) {
        return nullptr;
    }
    TreeNode *last_node = nullptr;
    binary_tree_2_linked_list_core(root, &last_node);
    while (last_node && last_node->left) {
        last_node = last_node->left;
    }
    return last_node;
}

void test_bst_2_list() {
    auto *node1 = new TreeNode(1);
    auto *node2 = new TreeNode(2);
    auto *node3 = new TreeNode(3);
    auto *node4 = new TreeNode(4);
    auto *node5 = new TreeNode(5);
    auto *node6 = new TreeNode(6);
    auto *node7 = new TreeNode(7);

    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);
    TreeNode *result = binary_tree_2_linked_list(node1);

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
}

#endif //INC_1STPROGRAM_OFFER_36_BINARY_TREE_CONVERT_TO_LINKED_LIST_H
