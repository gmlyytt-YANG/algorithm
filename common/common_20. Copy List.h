// Created by Administrator on 2018/9/11.
// Author : liyang
//
// 复制链表

#ifndef INC_1STPROGRAM_COMMON_20_COPY_LIST_H
#define INC_1STPROGRAM_COMMON_20_COPY_LIST_H

#include <iostream>
#include <vector>
#include <unordered_set>

#include "../util/list_util.h"

ListNode* copy_list(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    std::unordered_set<ListNode*> set;
    ListNode* node = head;
    ListNode* new_head = new ListNode(head->value);
    ListNode* new_node = new_head;
    while(set.empty() || node->next) {
        if (set.count(node)) {
            // 然后就不知道怎么写了。。。。
        }
        std::cout << node->value << std::endl;
        set.insert(node);
        ListNode* next = node->next;
        node = node->next;
        ListNode* new_next = new ListNode(next->value);
        new_node->next = new_next;
        new_node = new_node->next;
    }
    return new_head;
}

void test_copy_list() {
    // std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node2->next = node3;
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;
    node5->next = node3;
    // ListNode* head = create_list(arr);
    // ListNode* new_head = copy_list(head);
    ListNode* new_head2 = copy_list(node1);
    return;
}
#endif //INC_1STPROGRAM_COMMON_20_COPY_LIST_H
