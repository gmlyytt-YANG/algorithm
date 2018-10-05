/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_102. Binary Tree Level Order Traversal.h
 * @author gmlyytt@outlook.com
 * @date 2018/07/29 10:01:00
 * @brief https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define INC_1STPROGRAM_LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        result.emplace_back();
        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();
            if (!front) {
                if (q.empty()) {
                    break;
                }
                q.push(nullptr);
                result.emplace_back();
            } else {
                result.back().push_back(front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
        }
        return result;
    }

    vector<vector<int>> levelOrder2(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);
        result.emplace_back();
        int to_be_push = 1, next_level_num = 0;
        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();
            result.back().push_back(front->val);
            if (front->left) {
                q.push(front->left);
                ++next_level_num;
            }
            if (front->right) {
                q.push(front->right);
                ++next_level_num;
            }
            --to_be_push;
            if (to_be_push == 0 && !q.empty()) {
                result.emplace_back();
                to_be_push = next_level_num;
                next_level_num = 0;
            }
        }
        return result;
    }
};

void test() {
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2_1 = new TreeNode(9);
    TreeNode *node2_2 = new TreeNode(20);
    TreeNode *node3_3 = new TreeNode(15);
    TreeNode *node3_4 = new TreeNode(7);

    node1->left = node2_1;
    node1->right = node2_2;
    node2_2->left = node3_3;
    node2_2->right = node3_4;

    vector<vector<int>> result = Solution().levelOrder2(node1);

}

#endif //INC_1STPROGRAM_LEETCODE_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
