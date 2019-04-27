/*************************************************************************
 *
 * Copyright (c) 2019 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_83. Remove Duplicates from Sorted List.h
 * @author gmlyytt@outlook.com
 * @date 2019/4/27
 * @brief https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * */
#ifndef INC_1STPROGRAM_LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
#define INC_1STPROGRAM_LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

#include "../util/header_util.h"
#include "../util/list_util.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        while (q) {
            while (q && q->value == p->value) {
                q = q->next;
            }
            p->next = q;
            p = p->next;
            if (q) {
                q = q->next;
            }
        }
        return head;
    }
};

void test_delete_duplicates() {
    vector<int> vec = {1, 1, 2, 2};
    ListNode* head = create_list(vec);
    ListNode* result = Solution().deleteDuplicates(head);
    print_list(result);
}
#endif //INC_1STPROGRAM_LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
