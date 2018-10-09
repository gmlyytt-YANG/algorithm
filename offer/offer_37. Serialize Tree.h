/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_37. Serialize Tree.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/29 10:29:00
 * @brief 剑指offer第37题 序列化
 * */

#ifndef INC_1STPROGRAM_OFFER_37_SERIALIZE_TREE_H
#define INC_1STPROGRAM_OFFER_37_SERIALIZE_TREE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

std::string serialize(TreeNode* root) {
    if (!root) {
        return "";
    }
    std::string result;
    std::stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* top = stk.top();
        stk.pop();
        if (top) {
            stk.push(top->right);
            stk.push(top->left);
            result += std::to_string(top->val);
        } else {
            result += "~";
        }
        result += ",";
    }
    return result;
}

void serialize2(TreeNode* root, std::string& result) {
    if (!root) {
        result += "~,";
        return;
    }
    result += std::to_string(root->val) + ",";
    serialize2(root->left, result);
    serialize2(root->right, result);
}

void test_serialize() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    std::string result = serialize(node1);
    result = "";
    serialize2(node1, result);

}
#endif //INC_1STPROGRAM_OFFER_37_SERIALIZE_TREE_H
