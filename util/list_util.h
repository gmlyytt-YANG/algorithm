/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file tree_util.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/04 20:35:00
 * @brief 链表的基本操作
 * */

#ifndef INC_1STPROGRAM_LISTUTIL_H
#define INC_1STPROGRAM_LISTUTIL_H

#include <iostream>
#include <vector>

struct ListNode {
    int value;
    ListNode* next;

    explicit ListNode(int val) {
        value = val;
        next = nullptr;
    }

    explicit ListNode(const ListNode*& rhs) {
        value = rhs->value;
        next = rhs->next;
    }
};

struct ComplexListNode {
    int value;
    ComplexListNode* next;
    ComplexListNode* random;

    explicit ComplexListNode(int val) {
        value = val;
        next = nullptr;
        random = nullptr;
    }

    explicit ComplexListNode(const ComplexListNode*& rhs) {
        if (rhs) {
            value = rhs->value;
            next = rhs->next;
            random = rhs->random;
        }
    }
};

struct cmp {
    bool operator()(const ListNode* lhs, const ListNode* rhs) const {
        return lhs->value > rhs->value;
    }
};

ListNode* create_list(std::vector<int>& values);
void print_list(ListNode* head);
#endif //INC_1STPROGRAM_LISTUTIL_H
