// Created by Li,Yang(Duer04) on 2018/8/25.
// Author: liyang
//
// 环形链表中插入元素

#ifndef INC_1STPROGRAM_COMMON_14_INSERT_NODE_IN_ROTATE_LIST_H
#define INC_1STPROGRAM_COMMON_14_INSERT_NODE_IN_ROTATE_LIST_H

#include <iostream>

#include "../util/list_util.h"

void insert_node_in_rotate_list(ListNode** p_head, int value) {
    ListNode* new_node = new ListNode(value);
    if (!p_head) {
        *p_head = new_node;
        return;
    }
    ListNode* head = *p_head;
    ListNode* node = head;
    int Max = head->value;
    int end_flag = 0;
    while (true) {
        if (node->value > node->next->value) {
            end_flag = 1;
            break;
        } else if (node->value < value && node->next->value > value) {
            break;
        }
        node = node->next;
    }
    new_node->next = node->next;
    node->next = new_node;
    if (end_flag == 0) {
        return;
    }
    if (value < head->value) {
        *p_head = new_node;
    }
}

void test_insert_node_in_rotate_list() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node1;
    int value = 7;
    insert_node_in_rotate_list(&node1, value);
}
#endif //INC_1STPROGRAM_COMMON_14_INSERT_NODE_IN_ROTATE_LIST_H
