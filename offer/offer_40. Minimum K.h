// Created by Li,Yang(Duer04) on 2018/8/16.
// Author: liyang
//
// 数组中的最小的K个数

#ifndef INC_1STPROGRAM_OFFER_40_MINIMUM_K_H
#define INC_1STPROGRAM_OFFER_40_MINIMUM_K_H

#include <set>
#include <vector>

void minimum_K(std::vector<int>& arr, int k) {
    std::multiset<int, std::greater<int>> ctner;
    for (auto iter = arr.begin(); iter < arr.end(); ++iter) {
        if (ctner.size() < k) {
            ctner.insert(*iter);
        } else {
            if (*iter < *(ctner.begin())) {
                ctner.erase(ctner.begin());
                ctner.insert(*iter);
            }
        }
    }
    std::vector<int> result(ctner.begin(), ctner.end());
    std::sort(result.begin(), result.end());
}

void test_minimum_K() {
    std::vector<int> arr = {1, 2, 5, 4, 5, 6, 3};
    minimum_K(arr, 4);
}


#endif //INC_1STPROGRAM_OFFER_40_MINIMUM_K_H
