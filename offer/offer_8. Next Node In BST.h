/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_8. Next Node In BST.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/14 10:29:00
 * @brief 剑指offer第8题 二叉树的下一个节点
 * */

#ifndef INC_1STPROGRAM_OFFER_8_NEXT_NODE_IN_BST_H
#define INC_1STPROGRAM_OFFER_8_NEXT_NODE_IN_BST_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

TreeNodeWithParent *next_node_in_bst(TreeNodeWithParent *node) {
    if (!node) {
        return nullptr;
    }
    TreeNodeWithParent *next_node = nullptr;
    if (node->right) {
        next_node = node->right;
        while (next_node->left) {
            next_node = next_node->left;
        }
    } else {
        TreeNodeWithParent *parent_node = node->parent;
        if (parent_node) {
            while (parent_node && node == parent_node->right) {
                node = parent_node;
                parent_node = parent_node->parent;
            }
        }
        next_node = parent_node;
    }
    return next_node;
}

void test_next_node_in_bst() {
    TreeNodeWithParent *node1 = new TreeNodeWithParent(1);
    TreeNodeWithParent *node2 = new TreeNodeWithParent(2);
    TreeNodeWithParent *node3 = new TreeNodeWithParent(3);
    TreeNodeWithParent *node4 = new TreeNodeWithParent(4);
    TreeNodeWithParent *node5 = new TreeNodeWithParent(5);
    TreeNodeWithParent *node6 = new TreeNodeWithParent(6);
    connect_tree_node_with_parent(node1, node2, node3);
    connect_tree_node_with_parent(node2, node4, node5);
    connect_tree_node_with_parent(node5, node6, nullptr);
    TreeNodeWithParent *result = next_node_in_bst(node5);
}

#endif //INC_1STPROGRAM_OFFER_8_NEXT_NODE_IN_BST_H
