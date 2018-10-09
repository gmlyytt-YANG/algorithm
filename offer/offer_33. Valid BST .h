/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_33. Valid BST .h
 * @author gmlyytt@outlook.com
 * @date 2018/08/16 10:29:00
 * @brief 剑指offer第33题 验证数组是不是二叉树的后序遍历序列
 * */

#ifndef INC_1STPROGRAM_OFFER_33_VALID_BST_H
#define INC_1STPROGRAM_OFFER_33_VALID_BST_H

#include "../util/header_util.h"

bool valid_bst(std::vector<int> &arr, int begin, int end) {
    if (begin < 0 || end < 0 || begin > end) {
        return false;
    }
    if (begin == end) {
        return true;
    }
    int root_value = arr[end];
    int i = begin;
    for (; i < end; ++i) {
        if (arr[i] > root_value) {
            break;
        }
    }
    int j = i;
    for (; j < end; ++j) {
        if (arr[i] < root_value) {
            return false;
        }
    }
    bool left_valid = true;
    if (i > begin) {
        left_valid = valid_bst(arr, begin, i - 1);
    }
    bool right_valid = true;
    if (i < end) {
        right_valid = valid_bst(arr, i, end - 1);
    }
    return left_valid && right_valid;
}

void test_valid_bst() {
    std::vector<int> arr = {3, 4, 2, 7};
    std::cout << valid_bst(arr, 0, arr.size() - 1);
}

#endif //INC_1STPROGRAM_OFFER_33_VALID_BST_H
