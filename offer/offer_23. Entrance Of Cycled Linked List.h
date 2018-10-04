// Created by Li,Yang(Duer04) on 2018/8/21.
// Author: liyang
//
// 链表的入口节点

#ifndef INC_1STPROGRAM_OFFER_23_ENTRANCE_OF_CYCLED_LINKED_LIST_H
#define INC_1STPROGRAM_OFFER_23_ENTRANCE_OF_CYCLED_LINKED_LIST_H

#include <iostream>

#include "../util/list_util.h"

ListNode* entrance_of_linked_list(ListNode* head) {
    if (head == NULL)
        return NULL;
    ListNode* slow = head->next;
    // 先判断是否存在第二个节点
    if (slow == NULL)
        return NULL;
    ListNode* fast = slow->next;
    ListNode* start = head;
    bool isCycle = false;
    // while 循环的条件如果不满足，则直接跳出，证明没有环
    while (fast != NULL) {
        if (fast == slow) {
            isCycle = true;
            break;
        }
        slow = slow->next;
        fast = fast->next;
        // 这个判断的目的是防止如果不是环，fast可能会越界的情况
        if (fast)
            fast = fast->next;
    }
    if (!isCycle)
        return NULL;
    while (start != slow) {
        slow = slow->next;
        start = start->next;
    }
    return slow;
}

void test_entrance_of_linked_list() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    node2->next = node1;
    ListNode* result = entrance_of_linked_list(node1);
}
#endif //INC_1STPROGRAM_OFFER_23_ENTRANCE_OF_CYCLED_LINKED_LIST_H
