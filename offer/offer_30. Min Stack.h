// Created by Li,Yang(Duer04) on 2018/8/16.
// Author: liyang
//
// 包含min函数的栈

#ifndef INC_1STPROGRAM_OFFER_30_MIN_STACK_H
#define INC_1STPROGRAM_OFFER_30_MIN_STACK_H

#include <iostream>
#include <stack>

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
    MinStack* stk = new MinStack();
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
