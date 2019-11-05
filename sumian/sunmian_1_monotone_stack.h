/*************************************************************************
 *
 * Copyright (c) 2019 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file sunmian_1_monotone_stack.h
 * @author gmlyytt@outlook.com
 * @date 2019-11-05
 * @brief 用单调栈的方法来解决将一个数组变为一棵树，树的中序遍历为数组的原始顺序
 * */
#ifndef INC_1STPROGRAM_SUNMIAN_1_MONOTONE_STACK_H
#define INC_1STPROGRAM_SUNMIAN_1_MONOTONE_STACK_H

#include "../util/header_util.h"
#include "../util/tree_util.h"

TreeNode *origin_method_monotone_stack(const std::vector<int> &input_list, int left, int right) {
    if (input_list.empty()) {
        return nullptr;
    }
    if (left > right || left < 0 || right >= input_list.size()) {
        return nullptr;
    }
    int min_num = input_list[left];
    int min_idx = left;
    for (int idx = left; idx <= right; ++idx) {
        if (input_list[idx] < min_num) {
            min_num = input_list[idx];
            min_idx = idx;
        }
    }

    // 一定要new，不能直接定义，函数退出后会直接销毁栈内存
    auto* root = new TreeNode(min_num);
    root->left = origin_method_monotone_stack(input_list, left, min_idx - 1);
    root->right = origin_method_monotone_stack(input_list, min_idx + 1, right);

    return root;
}

void test_sunmian_1_monotone_stack() {
    std::vector<int> vec = {1, 4, 5, 6, 2, 3, 7};
    TreeNode* root = origin_method_monotone_stack(vec, 0, vec.size() - 1);
    print_tree(*root);
}

#endif //INC_1STPROGRAM_SUNMIAN_1_MONOTONE_STACK_H
