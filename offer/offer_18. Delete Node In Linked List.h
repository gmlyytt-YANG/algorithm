// Created by Li,Yang(Duer04) on 2018/8/6.
// Author: liyang
//
// 删除链表中的节点

#ifndef INC_1STPROGRAM_OFFER_18_DELETE_NODE_IN_LINKED_LIST_H
#define INC_1STPROGRAM_OFFER_18_DELETE_NODE_IN_LINKED_LIST_H

#include <iostream>
#include "../util/list_util.h"

void delete_node_in_list(ListNode** head, ListNode*& to_be_deleted_node) {
    if (!head || !(*head) || !to_be_deleted_node) {
        return;
    }
    if (*head == to_be_deleted_node) {
        delete *head;
        *head = nullptr;
        to_be_deleted_node = nullptr;
    } else if (to_be_deleted_node->next != nullptr) {
        ListNode* next_node = to_be_deleted_node->next;
        to_be_deleted_node->value = next_node->value;
        to_be_deleted_node->next = next_node->next;
        delete next_node;
        next_node = nullptr;
    } else {
        ListNode* node = *head;
        while (node->next != to_be_deleted_node) {
            node = node->next;
        }
        node->next = nullptr;
        delete to_be_deleted_node;
        to_be_deleted_node = nullptr;
    }
}

void delete_duplicate_nodes_in_list(ListNode** head) {
    if (!head || !(*head)) {
        return;
    }
    ListNode* node = *head;
    ListNode* pre_node = nullptr;
    while (node) {
        if (node->next && node->value == node->next->value) {
            int value = node->value;
            while (node->next && node->next->value == value) {
                node = node->next;
            }
            if (!pre_node) {
                *head = node;
            } else {
                pre_node->next = node->next;
            }
        }
        else {
            pre_node = node;
        }
        node = node->next;
    }
}

void delete_duplicate_nodes_in_list_2(ListNode** head) {
    if (!head || !(*head)) {
        return;
    }
    ListNode* pre = *head;
    ListNode* cur = nullptr;
    while(pre) {
        cur = pre->next;
        if (cur && cur->value == pre->value) {
            pre->next = cur->next;
        } else {
            pre = cur;
        }
    }
}

void test_delete_node_in_list() {
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
    delete_node_in_list(&node0, node5);
}

void test_delete_duplicate_nodes_in_list() {
    ListNode* node0 = new ListNode(1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    delete_duplicate_nodes_in_list_2(&node0);
    std::cout << "end" << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_18_DELETE_NODE_IN_LINKED_LIST_H
