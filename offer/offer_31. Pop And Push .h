/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_31. Pop And Push .h
 * @author gmlyytt@outlook.com
 * @date 2018/08/16 10:29:00
 * @brief 剑指offer第31题 栈的压入和弹出序列
 * */

#ifndef INC_1STPROGRAM_OFFER_31_POP_AND_PUSH_H
#define INC_1STPROGRAM_OFFER_31_POP_AND_PUSH_H

#include "../util/header_util.h"

bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) {
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
