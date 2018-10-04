//
// Created by Li,Yang(Duer04) on 2018/7/23.
//

#include "tree_util.h"

void connect_tree_node(TreeNodeMulti* pRoot, std::vector<TreeNodeMulti*>& pNodes) {
    pRoot->children = pNodes;
}

void connect_tree_node(TreeNode* root, TreeNode* left, TreeNode* right) {
    if (root) {
        root->left = left;
        root->right = right;
    }
}

void connect_tree_node(TreeLinkNode* root, TreeLinkNode* left, TreeLinkNode* right) {
    if (root) {
        root->left = left;
        root->right = right;
    }
}

void connect_tree_node_with_parent(TreeNodeWithParent* root,
        TreeNodeWithParent* left, TreeNodeWithParent* right) {
    if (root) {
        root->left = left;
        root->right = right;
        if (left) {
            left->parent = root;
        }
        if (right) {
            right->parent = root;
        }
    }
}