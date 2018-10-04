// Created by Li,Yang(Duer04) on 2018/8/13.
// Author: liyang
//
// 链表是不是回文串

#ifndef INC_1STPROGRAM_COMMON_10_LINKED_LIST_PALINDROME_H
#define INC_1STPROGRAM_COMMON_10_LINKED_LIST_PALINDROME_H

#include <iostream>
#include "../util/list_util.h"

ListNode* reverse_list(ListNode* head) {
    if (!head || !(head->next)) {
        return head;
    }
    ListNode* node = head;
    while (node->next) {
        ListNode* node_next = node->next;
        node->next = node_next->next;
        node_next->next = head;
        head = node_next;
    }
    return head;
}

bool palindrome(ListNode* head) {
    if (!head || !(head->next)) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse_list(slow->next);;
    slow = slow->next;
    while (slow) {
        if (slow->value != head->value) {
            return false;
        }
        slow = slow->next;
        head = head->next;
    }
    return true;
}

void test_palindrome() {
    std::vector<int> arr = {1, 2, 2, 1};
    ListNode* head = create_list(arr);
    std::cout << palindrome(head) << std::endl;
}
#endif //INC_1STPROGRAM_COMMON_10_LINKED_LIST_PALINDROME_H
