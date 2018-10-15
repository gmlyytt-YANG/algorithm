/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_4. Merge K Ordered List.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/12 20:35:00
 * @brief 合并K个有序链表
 * */

#ifndef INC_1STPROGRAM_COMMON_4_MERGE_K_ORDERED_LIST_H
#define INC_1STPROGRAM_COMMON_4_MERGE_K_ORDERED_LIST_H

#include "../util/header_util.h"
#include "../util/list_util.h"

ListNode *merge_K_ordered_list(std::vector<ListNode *> list_table) {
    if (list_table.empty()) {
        return nullptr;
    }
    std::priority_queue<ListNode *, std::vector<ListNode *>, cmp> pq;
    for (auto &elem: list_table) {
        pq.push(elem);
    }
    ListNode *head = nullptr;
    ListNode *pre_node = nullptr;
    while (!pq.empty()) {
        ListNode *node = pq.top();
        pq.pop();
        if (node->next) {
            pq.push(node->next);
        }
        if (!head) {
            head = node;
        } else {
            pre_node->next = node;
        }
        pre_node = node;
    }
    return head;
}

void test_merge_K_ordered_list() {
    std::vector<int> arr_1 = {2, 2, 3, 4};
    std::vector<int> arr_2 = {1, 5, 6, 7};
    std::vector<int> arr_3 = {8, 9, 10, 11};
    std::vector<int> arr_4 = {11, 12, 13, 14};
    ListNode *head1 = create_list(arr_1);
    ListNode *head2 = create_list(arr_2);
    ListNode *head3 = create_list(arr_3);
    ListNode *head4 = create_list(arr_4);
    std::vector<ListNode *> list_table = {head1, head2, head3, head4};
    ListNode *result = merge_K_ordered_list(list_table);
}

#endif //INC_1STPROGRAM_COMMON_4_MERGE_K_ORDERED_LIST_H
