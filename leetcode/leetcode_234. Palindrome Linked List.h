/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_234. Palindrome Linked List.h
 * @author gmlyytt@outlook.com
 * @date 2018/11/15 18:44
 * */

#ifndef INC_1STPROGRAM_LEETCODE_234_PALINDROME_LINKED_LIST_H
#define INC_1STPROGRAM_LEETCODE_234_PALINDROME_LINKED_LIST_H

#include "../util/header_util.h"
#include "../util/list_util.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !(head->next)) {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse_list(slow->next);
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

private:
    ListNode *reverse_list(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *p = head->next;
        while (p->next) {
            ListNode *q = p->next;
            p->next = q->next;
            q->next = head;
            head = q;
        }
        return head;
    }
};

void test_palindrome_list() {
    vector<int> arr = {1, 2, 3, 4, 3, 2, 1};
    ListNode* head = create_list(arr);
    cout << Solution().isPalindrome(head) << endl;
}

#endif //INC_1STPROGRAM_LEETCODE_234_PALINDROME_LINKED_LIST_H
