/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_27. Mirror Tree.h
 * @author gmlyytt@outlook.com
 * @date 2018/07/31 16:32:00
 * */

#ifndef INC_1STPROGRAM_OFFER_27_MIRROR_TREE_H
#define INC_1STPROGRAM_OFFER_27_MIRROR_TREE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

void mirror_tree(TreeNode *root) {
    if (!root || (!root->left && !root->right)) {
        return;
    }
    TreeNode *temp_node = root->left;
    root->left = root->right;
    root->right = temp_node;
    mirror_tree(root->left);
    mirror_tree(root->right);
}

void test_mirror_tree() {
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
    mirror_tree(node1);
}

#endif //INC_1STPROGRAM_OFFER_27_MIRROR_TREE_H
