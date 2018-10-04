// Created by Li,Yang(Duer04) on 2018/8/15.
// Author: liyang
//
// 树的子结构

#ifndef INC_1STPROGRAM_OFFER_26_SUB_TREE_H
#define INC_1STPROGRAM_OFFER_26_SUB_TREE_H

#include <iostream>
#include "../util/tree_util.h"

bool sub_tree_for_same_root(TreeNode* root1, TreeNode* root2) {
    if (root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return sub_tree_for_same_root(root1->left, root2->left) &&
           sub_tree_for_same_root(root1->right, root2->right);
}

bool sub_tree(TreeNode* root1, TreeNode* root2) {
    bool is_sub = false;
    if (root1 && root2) {
        is_sub = sub_tree_for_same_root(root1, root2);
        if (!is_sub) {
            is_sub = sub_tree(root1->left, root2);
        }
        if (!is_sub) {
            is_sub = sub_tree(root1->right, root2);
        }
    }
    return is_sub;
}

void test_sub_tree() {
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

    TreeNode* node31 = new TreeNode(3);
    TreeNode* node61 = new TreeNode(6);
    TreeNode* node71 = new TreeNode(7);
    connect_tree_node(node31, node61, node71);

    std::cout << sub_tree(node1, node31) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_26_SUB_TREE_H
