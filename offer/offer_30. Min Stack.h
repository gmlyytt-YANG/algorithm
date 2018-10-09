/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_30. Min Stack.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/16 10:29:00
 * @brief 剑指offer第30题 包含min函数的栈
 * */

#ifndef INC_1STPROGRAM_OFFER_30_MIN_STACK_H
#define INC_1STPROGRAM_OFFER_30_MIN_STACK_H

#include "../util/header_util.h"

class MinStack {
public:
    void push(int value) {
        if (stk1.empty() || value < stk2.top()) {
            stk2.push(value);
        } else {
            stk2.push(stk2.top());
        }
        stk1.push(value);
    }

    void pop() {
        stk1.pop();
        stk2.pop();
    }

    int min() {
        return stk2.top();
    }

private:
    std::stack<int> stk1;
    std::stack<int> stk2;
};

void test_min_stack() {
    MinStack *stk = new MinStack();
    stk->push(5);
    stk->push(2);
    stk->push(1);
    stk->push(3);
    std::cout << stk->min() << std::endl;
    stk->pop();
    std::cout << stk->min() << std::endl;
    stk->pop();
    std::cout << stk->min() << std::endl;
    stk->pop();
    std::cout << stk->min() << std::endl;

}

#endif //INC_1STPROGRAM_OFFER_30_MIN_STACK_H
