// Created by Li,Yang(Duer04) on 2018/8/15.
// Author: liyang
//
// 两个栈实现队列

#ifndef INC_1STPROGRAM_OFFER_9_TWO_STACK_QUEUE_H
#define INC_1STPROGRAM_OFFER_9_TWO_STACK_QUEUE_H

#include <iostream>
#include <stack>
#include <vector>

class SelfQueue {
public:
    SelfQueue() {}
    ~SelfQueue() {}

    void push(int value) {
        stk1.push(value);
    }

    void pop() {
        if (front() != -1) {
            stk2.pop();
        }
    }

    int front() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if (stk2.empty()) {
            std::cout << "invalid operation!" << std::endl;
            return -1;
        }
        return stk2.top();
    }

private:
    std::stack<int> stk1;
    std::stack<int> stk2;
};

void test_self_queue() {
    SelfQueue* sq = new SelfQueue();
    std::vector<int> arr = {1,2,3,4};
    for (auto& elem : arr) {
        sq->push(elem);
    }
    std::cout << sq->front() << std::endl;
    sq->pop();
    std::cout << sq->front() << std::endl;
    sq->pop();
    std::cout << sq->front() << std::endl;
}
#endif //INC_1STPROGRAM_OFFER_9_TWO_STACK_QUEUE_H
