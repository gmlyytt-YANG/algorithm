/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_6. Print List Reversely.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/07 10:29:00
 * @brief 剑指offer第6题 从尾到头打印链表
 * */

#ifndef INC_1STPROGRAM_OFFER_6_PRINT_LIST_REVERSELY_H
#define INC_1STPROGRAM_OFFER_6_PRINT_LIST_REVERSELY_H

#include "../util/header_util.h"
#include "../util/list_util.h"

void print_list_reversely(ListNode *head) {
    std::stack<ListNode *> stk;
    ListNode *node = head;
    while (node) {
        stk.push(node);
        node = node->next;
    }
    while (!stk.empty()) {
        std::cout << stk.top()->value << std::endl;
        stk.pop();
    }
}

void print_list_reversely2(ListNode *head) {
    if (head || head->next) {
        print_list_reversely(head->next);
    }
    std::cout << head->value << std::endl;
}

void test_print_list_reversely() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = create_list(arr);
    print_list_reversely(head);
    print_list_reversely2(head);
}

#endif //INC_1STPROGRAM_OFFER_6_PRINT_LIST_REVERSELY_H
