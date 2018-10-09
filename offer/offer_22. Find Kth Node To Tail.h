/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_22. Find Kth Node To Tail.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/07 10:29:00
 * @brief 剑指offer第22题 链表的倒数第K个节点
 * */

#ifndef INC_1STPROGRAM_OFFER_22_FIND_KTH_NODE_TO_TAIL_H
#define INC_1STPROGRAM_OFFER_22_FIND_KTH_NODE_TO_TAIL_H

#include "../util/header_util.h"
#include "../util/list_util.h"

ListNode *find_kth_node_to_tail(ListNode *head, const int k) {
    if (!head || k <= 0) {
        return nullptr;
    }
    ListNode *front = head;
    ListNode *tail = head;
    for (int i = 0; i < k - 1; ++i) {
        if (front) {
            front = front->next;
        } else {
            return nullptr;
        }

    }
    while (front->next) {
        front = front->next;
        tail = tail->next;
    }
    return tail;
}

void test_find_kth_node_to_tail() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    ListNode *head = create_list(arr);
    ListNode *result = find_kth_node_to_tail(head, 3);
    std::cout << result->value << std::endl;
}

#endif //INC_1STPROGRAM_OFFER_22_FIND_KTH_NODE_TO_TAIL_H
