/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_40. Minimum K.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/16 10:29:00
 * @brief 剑指offer第40题 数组中的最小的K个数
* */

#ifndef INC_1STPROGRAM_OFFER_40_MINIMUM_K_H
#define INC_1STPROGRAM_OFFER_40_MINIMUM_K_H

#include "../util/header_util.h"

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
