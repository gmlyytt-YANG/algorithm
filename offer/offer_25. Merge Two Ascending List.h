// Created by Li,Yang(Duer04) on 2018/8/7.
// Author: liyang
//
// 合并两个排好序的链表

#ifndef INC_1STPROGRAM_OFFER_25_MERGE_TWO_ASCENDING_LIST_H
#define INC_1STPROGRAM_OFFER_25_MERGE_TWO_ASCENDING_LIST_H

#include <iostream>
#include "../util/list_util.h"

//ListNode* merge_two_ascending_list(ListNode* head1, ListNode* head2) {
//    if (!head1) {
//        return head2;
//    }
//    if (!head2) {
//        return head1;
//    }
//    ListNode* merged_head = nullptr;
//    if (head1->value < head2->value) {
//        merged_head = head1;
//        merged_head->next = merge_two_ascending_list(head1->next, head2);
//    } else {
//        merged_head = head2;
//        merged_head->next = merge_two_ascending_list(head1, head2->next);
//    }
//    return merged_head;
//}

ListNode* merge_two_ascending_list(ListNode* head1, ListNode* head2) {
    if (!head1) {
        return head2;
    }
    if (!head2) {
        return head1;
    }
    ListNode* head = nullptr;
    if (head1->value < head2->value) {
        head = head1;
        head->next = merge_two_ascending_list(head1->next, head2);
    } else {
        head = head2;
        head->next = merge_two_ascending_list(head1, head2->next);
    }
    return head;
}

ListNode* merge_two_ascending_list_recursive(ListNode* head1, ListNode* head2) {
    ListNode* head = nullptr;
    ListNode* pre = nullptr;
    while (head1 || head2) {
        int head1_value = head1 ? head1->value : INT_MAX;
        int head2_value = head2 ? head2->value : INT_MAX;
        int head_value = std::min(head1_value, head2_value);
        if (head_value == head1_value) {
            head1 = head1->next;
        } else {
            head2 = head2->next;
        }
        ListNode* node = new ListNode(head_value);
        std::cout << node->value << std::endl;
        if (!head) {
            head = node;
            pre = node;
        } else {
            pre->next = node;
            pre = pre->next;
        }
    }
    return head;
}

void test_merge_two_ascending_list() {
    std::vector<int> arr1 = {1, 3, 4, 5, 7, 9};
    std::vector<int> arr2 = {2, 5, 8, 10};
    ListNode* head1 = create_list(arr1);
    ListNode* head2 = create_list(arr2);
    // ListNode* result = merge_two_ascending_list(head1, head2);
    ListNode* result2 = merge_two_ascending_list_recursive(head1, head2);
    // print_list(result);
}
#endif //INC_1STPROGRAM_OFFER_25_MERGE_TWO_ASCENDING_LIST_H
