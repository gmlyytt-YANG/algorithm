// Created by Li,Yang(Duer04) on 2018/8/16.
// Author: liyang
//
// 验证数组是不是二叉树的后序遍历序列

#ifndef INC_1STPROGRAM_OFFER_33_VALID_BST_H
#define INC_1STPROGRAM_OFFER_33_VALID_BST_H

#include <iostream>
#include <vector>

//bool valid_bst(std::vector<int>& arr, int begin, int end) {
//    if (arr.empty() || begin < 0 || end < 0) {
//        return false;
//    }
//    if (begin == end) {
//        return true;
//    }
//    int value = arr[end];
//
//    int left_index = begin;
//    for (; left_index < end; ++left_index) {
//        if (arr[left_index] > value) {
//            break;
//        }
//    }
//
//    int right_index = left_index;
//    for(; right_index < end; ++right_index) {
//        if (arr[right_index] < value) {
//            return false;
//        }
//    }
//
//    bool left = true;
//    if (left_index > begin) {
//        left = valid_bst(arr, begin, left_index - 1);
//    }
//    bool right = true;
//    if (left_index < end) {
//        right = valid_bst(arr, left_index, end - 1);
//    }
//    return left && right;
//}

bool valid_bst(std::vector<int>& arr, int begin, int end) {
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
