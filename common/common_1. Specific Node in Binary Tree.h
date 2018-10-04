//
// Created by Li,Yang(Duer04) on 2018/8/2.
//

#ifndef INC_1STPROGRAM_COMMON_1_SPECIFIC_NODE_IN_BINARY_TREE_H
#define INC_1STPROGRAM_COMMON_1_SPECIFIC_NODE_IN_BINARY_TREE_H

#include <iostream>
#include <queue>

#include "../util/tree_util.h"

int specific_node_in_tree(TreeNode* root, int layer_num, int node_num) {
    if (!root) {
        return -1;
    }
    if (layer_num < 0 || node_num < 0) {
        return -1;
    }
    if (layer_num == 1 && node_num == 1 && root) {
        return root->val;
    }
    int layer_to_be_stat = 1;
    int layer_num_increment = 1;
    int node_num_next_level = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current_node = q.front();
        q.pop();
        if (current_node->left) {
            q.push(current_node->left);
            ++node_num_next_level;
            if (layer_num_increment + 1 == layer_num && node_num_next_level == node_num) {
                return current_node->left->val;
            }
        }
        if (current_node->right) {
            q.push(current_node->right);
            ++node_num_next_level;
            if (layer_num_increment + 1 == layer_num && node_num_next_level == node_num) {
                return current_node->right->val;
            }
        }

        --layer_to_be_stat;
        if (layer_to_be_stat == 0) {
            ++layer_num_increment;
            if (layer_num_increment == layer_num && node_num_next_level < node_num) {
                std::cout << "there is no such node in this layer" << std::endl;
                return -1;
            }


            layer_to_be_stat = node_num_next_level;
            node_num_next_level = 0;
        }
    }

    if (layer_num_increment < layer_num) {
        std::cout << "Invalid layer_num input" << std::endl;
    }
    return -1;
}

void test_specific_node_in_tree() {
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2_1 = new TreeNode(9);
    TreeNode* node2_2 = new TreeNode(20);
    TreeNode* node3_3 = new TreeNode(15);
    TreeNode* node3_4 = new TreeNode(7);

    node1->left = node2_1;
    node1->right = node2_2;
    node2_2->left = node3_3;
    node2_2->right = node3_4;

    int result = specific_node_in_tree(node1, 1, 1);

}
#endif //INC_1STPROGRAM_COMMON_1_SPECIFIC_NODE_IN_BINARY_TREE_H
