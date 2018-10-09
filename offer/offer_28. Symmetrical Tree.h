/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_28. Symmetrical Tree.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/21 10:29:00
 * @brief 剑指offer第28题 对称的二叉树
 * */

#ifndef INC_1STPROGRAM_OFFER_28_SYMMETRICAL_TREE_H
#define INC_1STPROGRAM_OFFER_28_SYMMETRICAL_TREE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

bool isSymmetrical(TreeNode *pRoot) {
    if (!pRoot) {
        return true;
    }
    std::queue<TreeNode *> q;
    q.push(pRoot->left);
    q.push(pRoot->right);
    while (!q.empty()) {
        TreeNode *node1 = q.front();
        q.pop();
        TreeNode *node2 = q.front();
        q.pop();
        if (!node1 && !node2) {
            continue;
        }
        if (!node1 || !node2 || node1->val != node2->val) {
            return false;
        }
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }
    return true;
}

#endif //INC_1STPROGRAM_OFFER_28_SYMMETRICAL_TREE_H
