/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_32. Print Bst.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/28 10:29:00
 * @brief 剑指offer第32题 从上到下打印二叉树
 * */


#ifndef INC_1STPROGRAM_OFFER_32_PRINT_BST_H
#define INC_1STPROGRAM_OFFER_32_PRINT_BST_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

/*
 * @brief 从上到下打印二叉树
 */
vector<vector<int> > Print(TreeNode *pRoot) {
    vector<vector<int> > result;
    if (pRoot == nullptr) {
        return result;
    }
    queue<TreeNode *> q;
    q.push(pRoot);
    while (!q.empty()) {
        int low = 0;
        int high = q.size();
        vector<int> temp;
        while (low++ < high) {
            TreeNode *front = q.front();
            q.pop();
            temp.push_back(front->val);
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        result.push_back(temp);
    }
    return result;
}

/*
 * @brief zigzag打印二叉树
 */
void print_zigzag(TreeNode *root) {
    if (!root) {
        return;
    }
    int current = 0;
    int next = 1;
    stack<TreeNode *> levels[2];
    levels[current].push(root);
    while (!levels[1].empty() || !levels[0].empty()) {
        cout << levels[current].top()->val << " ";
        TreeNode *top = levels[current].top();
        levels[current].pop();
        if (current == 0) {
            if (top->left) {
                levels[next].push(top->left);
            }
            if (top->right) {
                levels[next].push(top->right);
            }
        } else {
            if (top->right) {
                levels[next].push(top->right);
            }
            if (top->left) {
                levels[next].push(top->left);
            }
        }
        if (levels[current].empty()) {
            cout << endl;
            current = 1 - current;
            next = 1 - next;
        }
    }
}

void test_print_bst() {
    TreeNode *node1 = new TreeNode(8);
    TreeNode *node2 = new TreeNode(6);
    TreeNode *node3 = new TreeNode(10);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node6 = new TreeNode(9);
    TreeNode *node7 = new TreeNode(11);
    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);
    vector<vector<int>> result = Print(node1);
    print_zigzag(node1);
}

#endif //INC_1STPROGRAM_OFFER_32_PRINT_BST_H
