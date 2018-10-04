// Created by Li,Yang(Duer04) on 2018/8/14.
// Author: liyang
//
// 二叉树的下一个节点

#ifndef INC_1STPROGRAM_OFFER_8_NEXT_NODE_IN_BST_H
#define INC_1STPROGRAM_OFFER_8_NEXT_NODE_IN_BST_H

#include <iostream>

#include "../util/tree_util.h"

//TreeNodeWithParent* next_node_in_bst(TreeNodeWithParent* node) {
//    if (!node) {
//        return nullptr;
//    }
//    TreeNodeWithParent* node_next = nullptr;
//    if (node->right) {
//        node_next = node->right;
//        while (node_next->left) {
//            node_next = node_next->left;
//        }
//    } else {
//        TreeNodeWithParent* parent = node->parent;
//        if (parent) {
//            while (parent && node == parent->right) {
//                node = parent;
//                parent = parent->parent;
//            }
//        }
//        node_next = parent;
//    }
//    return node_next;
//}

TreeNodeWithParent* next_node_in_bst(TreeNodeWithParent* node) {
    if (!node) {
        return nullptr;
    }
    TreeNodeWithParent* next_node = nullptr;
    if (node->right) {
        next_node = node->right;
        while (next_node->left) {
            next_node = next_node->left;
        }
    } else {
        TreeNodeWithParent* parent_node = node->parent;
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
    TreeNodeWithParent* node1 = new TreeNodeWithParent(1);
    TreeNodeWithParent* node2 = new TreeNodeWithParent(2);
    TreeNodeWithParent* node3 = new TreeNodeWithParent(3);
    TreeNodeWithParent* node4 = new TreeNodeWithParent(4);
    TreeNodeWithParent* node5 = new TreeNodeWithParent(5);
    TreeNodeWithParent* node6 = new TreeNodeWithParent(6);
    connect_tree_node_with_parent(node1, node2, node3);
    connect_tree_node_with_parent(node2, node4, node5);
    connect_tree_node_with_parent(node5, node6, nullptr);
    TreeNodeWithParent* result = next_node_in_bst(node5);
}
#endif //INC_1STPROGRAM_OFFER_8_NEXT_NODE_IN_BST_H
