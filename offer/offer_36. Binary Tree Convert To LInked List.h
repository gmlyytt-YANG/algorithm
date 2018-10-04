//
// Created by Li,Yang(Duer04) on 2018/7/31.
//

#ifndef INC_1STPROGRAM_OFFER_36_BINARY_TREE_CONVERT_TO_LINKED_LIST_H
#define INC_1STPROGRAM_OFFER_36_BINARY_TREE_CONVERT_TO_LINKED_LIST_H

#include <iostream>

#include "../util/tree_util.h"

void binary_tree_2_linked_list_core(TreeNode* root, TreeNode** last_node);
TreeNode* binary_tree_2_linked_list(TreeNode* root);
void test_3();

#endif //INC_1STPROGRAM_OFFER_36_BINARY_TREE_CONVERT_TO_LINKED_LIST_H
