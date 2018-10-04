// Created by Li,Yang(Duer04) on 2018/8/6.
// Author: liyang
//
// 两个链表的第一个公共节点

#ifndef INC_1STPROGRAM_OFFER_10_LAST_COMMON_NODE_IN_TWO_LISTS_H
#define INC_1STPROGRAM_OFFER_10_LAST_COMMON_NODE_IN_TWO_LISTS_H

#include <iostream>
#include "../util/list_util.h"

unsigned int list_length(ListNode* head) {
    unsigned int length = 0;
    while (head) {
        ++length;
        head = head->next;
    }
    return length;
}

ListNode* last_common_node(ListNode* head1, ListNode* head2) {
    if (!head1 || !head2) {
        return nullptr;
    }
    unsigned int length_1 = list_length(head1);
    unsigned int length_2 = list_length(head2);
    int length_diff = length_1 - length_2;
    ListNode* head_long = head1;
    ListNode* head_short = head2;
    if (length_diff < 0) {
        head_short = head1;
        head_long = head2;
        length_diff = -length_diff;
    }
    unsigned int move_head = 0;
    while (move_head < length_diff) {
        head_long = head_long->next;
        ++move_head;
    }
    while (head_long && head_short && head_long != head_short) {
        head_long = head_long->next;
        head_short = head_short->next;
    }
    ListNode* last_common_node = head_long;
    return head_long;
}

ListNode* last_common_node2(ListNode* head1, ListNode* head2) {
    if (!head1 || !head2) {
        return nullptr;
    }
    ListNode* front = head1;
    ListNode* tail = head2;
    while (front != tail) {
        front = front == nullptr ? head2 : front->next;
        tail = tail == nullptr ? head1 : tail->next;
    }
    return front;
}

void test_last_common_node() {
    ListNode* node11 = new ListNode(1);
    ListNode* node12 = new ListNode(2);
    ListNode* node13 = new ListNode(3);
    ListNode* node14 = new ListNode(4);
    ListNode* node15 = new ListNode(5);
    ListNode* node21 = new ListNode(1);

    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node21->next = node13;

    ListNode* result = last_common_node2(node11, node21);

    std::cout << result->value << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_10_LAST_COMMON_NODE_IN_TWO_LISTS_H
