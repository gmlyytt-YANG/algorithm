/*************************************************************************
 *
 * Copyright (c) 2019 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_107. Binary Tree Level Order Traversal II.h
 * @author gmlyytt@outlook.com
 * @date 2019/4/28
 * @brief https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * */
#ifndef INC_1STPROGRAM_LEETCODE_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
#define INC_1STPROGRAM_LEETCODE_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        int depth = 0;
        dfs(root, result, depth);
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(TreeNode *root, vector<vector<int>> &result, int depth) {
        if (!root) {
            return;
        }
        if (result.size() <= depth) {
            result.emplace_back(vector<int>());
        }
        result[depth].push_back(root->val);
        dfs(root->left, result, depth + 1);
        dfs(root->right, result, depth + 1);
    }
};

void test_level_order_bottom() {
    auto* node1 = new TreeNode(3);
    auto* node2 = new TreeNode(9);
    auto* node3 = new TreeNode(20);
    auto* node4 = new TreeNode(1);
    auto* node5 = new TreeNode(2);
    auto* node6 = new TreeNode(5);
    auto* node7 = new TreeNode(17);
    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);

    vector<vector<int>> result = Solution().levelOrderBottom(node1);
    for (auto & elem : result) {
        for (auto & tiny_elem : elem) {
            cout << tiny_elem << " ";
        }
        cout << endl;
    }
}

#endif //INC_1STPROGRAM_LEETCODE_107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H
