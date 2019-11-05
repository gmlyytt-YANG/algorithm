/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file tree_util.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/04 20:35:00
 * @brief 树的基本操作
 * */


#ifndef INC_1STPROGRAM_TREEUTIL_H
#define INC_1STPROGRAM_TREEUTIL_H

#include "../util/header_util.h"

#include <iostream>
#include <vector>
#include <list>

struct TreeNodeMulti {
    int value;
    std::vector<TreeNodeMulti *> children;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode*& in) {
        val = in->val;
        left = in->left;
        right = in->right;
    }
};

struct TreeNodeWithParent {
    int val;
    TreeNodeWithParent *left;
    TreeNodeWithParent *right;
    TreeNodeWithParent *parent;

    explicit TreeNodeWithParent(int x) : val(x), left(nullptr),
                                         right(nullptr), parent(nullptr) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    explicit TreeLinkNode(int x) :
            val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connect_tree_node_with_parent(TreeNodeWithParent *root,
                                   TreeNodeWithParent *left, TreeNodeWithParent *right);

void connect_tree_node(TreeNodeMulti *pRoot, std::vector<TreeNodeMulti *> &pNodes);

void connect_tree_node(TreeNode *root, TreeNode *left, TreeNode *right);

void connect_tree_node(TreeLinkNode *root, TreeLinkNode *left, TreeLinkNode *right);

void insert_bst(TreeNode*& root, int elem);

bool print_tree(const TreeNode& root);

#endif //INC_1STPROGRAM_TREEUTIL_H
