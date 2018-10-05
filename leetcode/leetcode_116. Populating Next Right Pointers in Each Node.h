/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_116. Populating Next Right Pointers in Each Node.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/04 17:25:00
 * @brief https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 * @method http://note.youdao.com/noteshare?id=7cdcf21e5866ec3607efa46ecf747d6b&sub=270F5B54B3C9401392166EB69C348AD8
 * */

#ifndef INC_1STPROGRAM_LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H
#define INC_1STPROGRAM_LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (!(root->left) && !(root->right)) {
            return;
        }
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};

void test_connect_tree_node() {
    TreeLinkNode *node1 = new TreeLinkNode(1);
    TreeLinkNode *node2 = new TreeLinkNode(2);
    TreeLinkNode *node3 = new TreeLinkNode(3);
    TreeLinkNode *node4 = new TreeLinkNode(4);
    TreeLinkNode *node5 = new TreeLinkNode(5);
    TreeLinkNode *node6 = new TreeLinkNode(6);
    TreeLinkNode *node7 = new TreeLinkNode(7);
    connect_tree_node(node1, node2, node3);
    connect_tree_node(node2, node4, node5);
    connect_tree_node(node3, node6, node7);
    Solution().connect(node1);
}

#endif //INC_1STPROGRAM_LEETCODE_116_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H
