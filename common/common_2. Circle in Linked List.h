// Created by Li,Yang(Duer04) on 2018/8/5.
// Author: liyang
//
// 链表的入口节点

#ifndef INC_1STPROGRAM_COMMON_2_CIRCLE_IN_LINKED_LIST_H
#define INC_1STPROGRAM_COMMON_2_CIRCLE_IN_LINKED_LIST_H

#include <iostream>
#include "../util/list_util.h"

ListNode* circle_in_list(ListNode* head) {
    if (!head || !head->next) {
        return nullptr;
    }
    ListNode* slow = head->next;
    ListNode* fast = slow->next;
    ListNode* start = head;
    bool is_circle = false;
    while (slow && fast) {
        if (slow == fast) {
            is_circle = true;
            break;
        }
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
    }
    if (!is_circle && slow != fast) {
        return nullptr;
    }
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }
    return slow;
}

void test_circle_in_list() {
    ListNode* node0 = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;
    ListNode* result = circle_in_list(node0);
}
#endif //INC_1STPROGRAM_COMMON_2_CIRCLE_IN_LINKED_LIST_H
