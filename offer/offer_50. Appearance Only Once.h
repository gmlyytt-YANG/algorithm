// Created by Li,Yang(Duer04) on 2018/8/20.
// Author: liyang
//
// 第一次出现的字母

#ifndef INC_1STPROGRAM_OFFER_50_APPEARANCE_ONLY_ONCE_H
#define INC_1STPROGRAM_OFFER_50_APPEARANCE_ONLY_ONCE_H

#include <iostream>
#include <vector>

char appearing_once(const std::string& str) {
    char result = ' ';
    if (str.empty()) {
        return result;
    }
    std::vector<int> ctner(256, 0);
    for (auto& elem : str) {
        ++ctner[elem - '0'];
    }
    for (auto& elem : str) {
        if (ctner[elem - '0'] == 1) {
            return elem;
        }
    }
    return ' ';
}

void test_appearing_once() {
    std::string str("google");
    std::cout << appearing_once(str) << std::endl;
}

int main(){
    test_appearing_once();
    return 0;
}
#endif //INC_1STPROGRAM_OFFER_50_APPEARANCE_ONLY_ONCE_H
