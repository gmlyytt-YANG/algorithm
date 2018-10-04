// Created by Li,Yang(Duer04) on 2018/8/8.
// Author: liyang
//
// 二叉树中和为某一个值的路径

#ifndef INC_1STPROGRAM_OFFER_34_FIND_PATH_H
#define INC_1STPROGRAM_OFFER_34_FIND_PATH_H

#include <iostream>
#include "../util/tree_util.h"

void print_elem(std::vector<int>& arr) {
    for (auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void find_path_core(TreeNode* root, int num, int sum, std::vector<int>& path,
        std::vector<std::vector<int>>& paths) {
    sum += root->val;
    path.emplace_back(root->val);
    bool is_leaf = (!root->left && !root->right);
    if (is_leaf && sum == num) {
        paths.emplace_back(path);
    }
    if (root->left) {
        find_path_core(root->left, num, sum, path, paths);
    }
    if (root->right) {
        find_path_core(root->right, num, sum, path, paths);
    }
    print_elem(path);
    path.pop_back();
    print_elem(path);
}

//void find_path_core(TreeNode* root, int num, int sum, std::vector<int>& path,
//        std::vector<std::vector<int>>& paths) {
//    if (!root) {
//        return;
//    }
//    sum += root->val;
//    path.push_back(root->val);
//    if (sum == num) {
//        paths.push_back(path);
//    }
//    find_path_core(root->left, num, sum, path, paths);
//    find_path_core(root->right, num, sum, path, paths);
//    path.pop_back();
//}

std::vector<std::vector<int>> find_path(TreeNode* root, int num) {
    std::vector<std::vector<int>> paths;
    if (!root) {
        return paths;
    }
    std::vector<int> path;
    int sum = 0;
    find_path_core(root, num, sum, path, paths);
    std::cout << "end" << std::endl;
    return paths;
}

void test_find_path() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(4);
    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);
    std::vector<std::vector<int>> result = find_path(node1, 8);
}
#endif //INC_1STPROGRAM_OFFER_34_FIND_PATH_H
