/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_35. Copy List.h
 * @author gmlyytt@outlook.com
 * @date 2018/09/12 10:29:00
 * @brief 剑指offer第35题 复制链表
 * */

#ifndef INC_1STPROGRAM_OFFER_35_COPY_LIST_H
#define INC_1STPROGRAM_OFFER_35_COPY_LIST_H

#include "../util/header_util.h"
#include "../util/list_util.h"

void clone_list(ComplexListNode *head) {
    if (!head) {
        return;
    }
    ComplexListNode *node = head;
    while (node) {
        ComplexListNode *new_node = new ComplexListNode(node->value);
        new_node->next = node->next;
        node->next = new_node;
        node = new_node->next;
    }
}

void clone_random(ComplexListNode *head) {
    if (!head) {
        return;
    }
    ComplexListNode *node = head;
    while (node) {
        ComplexListNode *new_node = node->next;
        new_node->random = node->random->next;
        node = new_node->next;
    }
}

ComplexListNode *split_list(ComplexListNode *head) {
    if (!head) {
        return nullptr;
    }
    ComplexListNode *node = head;
    ComplexListNode *new_head = nullptr;
    ComplexListNode *new_node = nullptr;
    while (node) {
        if (!new_head) {
            new_head = node->next;
            new_node = new_head;
        } else {
            new_node->next = node->next;
            new_node = new_node->next;
        }
        node->next = new_node->next;
        node = node->next;
    }
    return new_head;
}

void test_clone_list() {
    ComplexListNode *node1 = new ComplexListNode(1);
    ComplexListNode *node2 = new ComplexListNode(2);
    ComplexListNode *node3 = new ComplexListNode(3);
    ComplexListNode *node4 = new ComplexListNode(4);
    ComplexListNode *node5 = new ComplexListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node1->random = node3;
    node2->random = node4;
    node3->random = node1;
    node4->random = node2;
    node5->random = node3;
    clone_list(node1);
    clone_random(node1);
    ComplexListNode *new_head = split_list(node1);
}

#endif //INC_1STPROGRAM_OFFER_35_COPY_LIST_H
