// Created by Li,Yang(Duer04) on 2018/8/16.
// Author: liyang
//
// 栈的压入和弹出序列

#ifndef INC_1STPROGRAM_OFFER_31_POP_AND_PUSH_H
#define INC_1STPROGRAM_OFFER_31_POP_AND_PUSH_H

#include <iostream>
#include <stack>
#include <vector>

//bool pop_and_push(std::vector<int>& arr1, std::vector<int>& arr2) {
//    int length1 = arr1.size();
//    int length2 = arr2.size();
//    if (!length1 || !length2 || length1 != length2) {
//        return false;
//    }
//    int i = 0;
//    int j = 0;
//    std::stack<int> stk;
//    while (j < length1) {
//        while (stk.empty() || (i < length1 && stk.top() != arr2[j])) {
//            stk.push(arr1[i]);
//            ++i;
//        }
//        stk.pop();
//        ++j;
//    }
//    if (j == length1 && stk.empty()) {
//        return true;
//    }
//}

bool IsPopOrder(std::vector<int> pushV,std::vector<int> popV) {
    if (!pushV.empty() && !popV.empty() && popV.size() == pushV.size()) {
        std::stack<int> stk;
        int push_index = 0;
        for (int pop_index = 0; pop_index < popV.size(); ++pop_index) {
            while (stk.empty() || (push_index < pushV.size() && stk.top() != popV[pop_index])) {
                stk.push(pushV[push_index++]);
            }
            if (stk.top() != popV[pop_index]) {
                return false;
            } else {
                stk.pop();
            }
        }
        if (stk.empty() && push_index == pushV.size()) {
            return true;
        }
    }
    return false;
}

void test_pop_and_push() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 2, 1, 5, 4};
    std::cout << IsPopOrder(arr1, arr2) << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_31_POP_AND_PUSH_H
