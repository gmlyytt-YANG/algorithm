/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_6. Binary Search Tree.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/13 20:35:00
 * @brief 二叉搜索树的查找
 * */

#ifndef INC_1STPROGRAM_COMMON_6_BINARY_SEARCH_TREE_H
#define INC_1STPROGRAM_COMMON_6_BINARY_SEARCH_TREE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int val) : value(val), left(nullptr), right(nullptr) {};
};

void insert_node(BinaryTreeNode *&root, const int value) {
    if (!root) {
        root = new BinaryTreeNode(value);
        return;
    }
    if (value == root->value) {
        std::cout << "duplicating nodes" << std::endl;
    } else if (value > root->value) {
        insert_node(root->right, value);
    } else {
        insert_node(root->left, value);
    }
}

BinaryTreeNode *build_tree() {
    int elem = 0;
    BinaryTreeNode *root = nullptr;
    while (std::cin >> elem) {
        insert_node(root, elem);
    }
    return root;
}

void delete_tree(BinaryTreeNode *&root) {
    if (root->left) {
        delete_tree(root->left);
    } else if (root->right) {
        delete_tree(root->right);
    }
    delete root;
    root = nullptr;
}

bool binary_search_tree_recursive(BinaryTreeNode *root, const int value) {
    if (!root) {
        return false;
    }
    bool found = false;
    if (root->value == value) {
        found = true;
    } else if (root->value > value) {
        found = binary_search_tree_recursive(root->left, value);
    } else {
        found = binary_search_tree_recursive(root->right, value);
    }
    return found;
}

BinaryTreeNode *binary_search_tree_iterative(BinaryTreeNode *root, const int value) {
    bool found = false;
    while (root) {
        if (root->value == value) {
            found = true;
            break;
        } else if (root->value > value) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

void test_binary_search_tree() {
    BinaryTreeNode *root = build_tree();
    int value = 2;
    bool result = binary_search_tree_recursive(root, value);
    BinaryTreeNode *result_node = binary_search_tree_iterative(root, value);
    delete_tree(root);
}

#endif //INC_1STPROGRAM_COMMON_6_BINARY_SEARCH_TREE_H
