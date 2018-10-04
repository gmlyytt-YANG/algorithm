// Created by Li,Yang(Duer04) on 2018/8/14.
// Author: liyang
//
// 两个大数相加

#ifndef INC_1STPROGRAM_LEETCODE_2_ADD_TWO_NUMBERS_H
#define INC_1STPROGRAM_LEETCODE_2_ADD_TWO_NUMBERS_H

#include <iostream>
#include "../util/list_util.h"

std::string add_two_numbers_string(std::string& str1, std::string& str2) {
    std::string str1_reverse = str1;
    std::string str2_reverse = str2;
    std::string result;
    std::reverse(str1_reverse.begin(), str1_reverse.end());
    std::reverse(str2_reverse.begin(), str2_reverse.end());
    int length1 = str1.size();
    int length2 = str2.size();
    int index_1 = 0;
    int index_2 = 0;
    int carry = 0;
    while (index_1 < length1 || index_2 < length2 || carry) {
        int bit_1 = index_1 < length1 ? str1_reverse[index_1] - '0' : 0;
        int bit_2 = index_2 < length2 ? str2_reverse[index_2] - '0' : 0;
        int sum = bit_1 + bit_2 + carry;
        result += sum % 10 + '0';
        carry = sum / 10;
        ++index_1;
        ++index_2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string add_two_numbers_string_recursive_core(std::string& str1, std::string& str2,
        int index_1, int index_2, int carry) {
    std::string result;
    if (index_1 < str1.size() || index_2 < str2.size() || carry) {
        int bit_1 = index_1 < str1.size() ? str1[index_1] - '0' : 0;
        int bit_2 = index_2 < str2.size() ? str2[index_2] - '0' : 0;
        int sum = bit_1 + bit_2 + carry;
        carry = sum / 10;
        result = sum % 10 + '0';
        result += add_two_numbers_string_recursive_core(str1, str2, ++index_1,
                ++index_2, carry);
    }
    return result;
}

std::string add_two_numbers_string_recursive(std::string& str1, std::string& str2) {
    std::string str1_reverse = str1;
    std::string str2_reverse = str2;
    std::string result;
    std::reverse(str1_reverse.begin(), str1_reverse.end());
    std::reverse(str2_reverse.begin(), str2_reverse.end());
    int index_1 = 0;
    int index_2 = 0;
    int carry = 0;
    result = add_two_numbers_string_recursive_core(str1_reverse, str2_reverse, index_1, index_2, carry);
    std::reverse(result.begin(), result.end());
    return result;
}

ListNode* add_two_numbers(ListNode* head1, ListNode* head2) {
    ListNode* head = new ListNode(0);
    ListNode* traverse_node = head;
    int carry = 0;
    while (head1 || head2 || carry) {
        int sum = (head1 ? head1->value : 0) + (head2 ? head2->value : 0) + carry;
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        traverse_node->next = node;
        traverse_node = traverse_node->next;
        head1 = head1 ? head1->next : nullptr;
        head2 = head2 ? head2->next : nullptr;
    }
    return head->next;
}

void add_two_numbers_recursive(ListNode* head1, ListNode* head2, ListNode* head, int carry) {
    if (head1 || head2 || carry) {
        int sum = (head1 ? head1->value : 0) + (head2 ? head2->value : 0) + carry;
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        head->next = node;
        head1 = head1 ? head1->next : nullptr;
        head2 = head2 ? head2->next : nullptr;
        add_two_numbers_recursive(head1, head2, node, carry);
    }
}

void test_add_two_numbers() {
    std::vector<int> arr1 = {1,2,3,4,5,7};
    std::vector<int> arr2 = {5,9,1,2,9,3};
    ListNode* head1 = create_list(arr1);
    ListNode* head2 = create_list(arr2);
    ListNode* head = new ListNode(0);
    ListNode* result = add_two_numbers(head1, head2);
    add_two_numbers_recursive(head1, head2, head, 0);

    std::string str1 = "754321";
    std::string str2 = "392195";
    // std::string result_string = add_two_numbers_string(str1, str2);
    std::string result_string_2 = add_two_numbers_string_recursive(str1, str2);
}
#endif //INC_1STPROGRAM_LEETCODE_2_ADD_TWO_NUMBERS_H
