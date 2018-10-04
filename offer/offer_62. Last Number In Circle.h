// Created by Li,Yang(Duer04) on 2018/8/29.
// Author: liyang
//
// 圆圈中剩下的最后一个数字

#ifndef INC_1STPROGRAM_OFFER_62_LAST_NUMBER_IN_CIRCLE_H
#define INC_1STPROGRAM_OFFER_62_LAST_NUMBER_IN_CIRCLE_H

#include <iostream>
#include <list>
#include <vector>

int LastRemaining_Solution1(unsigned int n, unsigned int m) {
    if (n <= 0 || m < 1)
        return -1;
    list<int> numbers;
    for (int i = 0; i<n; ++i)
        numbers.push_back(i);
    list<int>::iterator current = numbers.begin();
    // 原始数据中必须剩下一个数
    while (numbers.size() > 1) {
        for (int i = 1; i<m; ++i) {
            ++current;
            if (current == numbers.end()) {
                current = numbers.begin();
            }
        }
        list<int>::iterator next = ++current;
        if (next == numbers.end())
            next = numbers.begin();
        --current;
        numbers.erase(current);
        current = next;
    }
    return *current;
}
#endif //INC_1STPROGRAM_OFFER_62_LAST_NUMBER_IN_CIRCLE_H
