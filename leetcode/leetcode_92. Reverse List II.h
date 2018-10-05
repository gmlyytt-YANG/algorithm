/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_92. Reverse List II.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/04 10:01:00
 * @brief https://leetcode.com/problems/reverse-linked-list-ii/description/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_92_REVERSE_LIST_2_H
#define INC_1STPROGRAM_LEETCODE_92_REVERSE_LIST_2_H

#include "../util/header_util.h"
#include "../util/list_util.h"

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head || m < 0 || n < 0 || m > n) {
        return nullptr;
    }
    ListNode *pre = new ListNode(0);
    pre->next = head;
    ListNode *node = pre;
    for (int i = 1; i < m; ++i) {
        if (node->next) {
            node = node->next;
        } else {
            return nullptr;
        }
    }
    cout << node->value << endl;
    ListNode *traverse = node->next;
    cout << traverse->value << endl;
    if (traverse == nullptr) {
        return nullptr;
    }
    for (int i = 1; i <= n - m; ++i) {
        ListNode *next = traverse->next;
        cout << next->value << endl;
        if (!next) {
            return nullptr;
        }
        traverse->next = next->next;
        next->next = node->next;
        node->next = next;
    }
    return pre->next;
}

void test_reverse_between() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = create_list(arr);
    ListNode *result = reverseBetween(head, 2, 4);
}

#endif //INC_1STPROGRAM_LEETCODE_92_REVERSE_LIST_2_H
