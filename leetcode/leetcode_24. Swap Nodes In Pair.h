// Created by Li,Yang(Duer04) on 2018/9/2.
// Author: liyang
//
//
#ifndef INC_1STPROGRAM_LEETCODE_24_SWAP_NODES_IN_PAIR_H
#define INC_1STPROGRAM_LEETCODE_24_SWAP_NODES_IN_PAIR_H

#include <iostream>

#include "../util/list_util.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* node = head;
        while (node && node->next) {
            ListNode* next_node = node->next;
            node->next = next_node->next;
            next_node->next = node;
            std::cout << node->value << std::endl;
            if (!pre) {
                head = next_node;
            } else {
                pre->next = next_node;
            }
            pre = node;
            node = node->next;
        }
        return head;
    }
};

void test_swap_pairs() {
    std::vector<int> arr = {1, 2, 3, 4};
    ListNode* head = create_list(arr);
    ListNode* result = Solution().swapPairs(head);
}
#endif //INC_1STPROGRAM_LEETCODE_24_SWAP_NODES_IN_PAIR_H
