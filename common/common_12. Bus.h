// Created by Li,Yang(Duer04) on 2018/8/25.
// Author: liyang
//
// 每个队伍可能有1-4人，一辆大巴最多只能容纳4人，每个队伍必须在一辆车上，问最少需要几辆大巴
#ifndef INC_1STPROGRAM_COMMON_12_BUS_H
#define INC_1STPROGRAM_COMMON_12_BUS_H

#include <iostream>
#include <vector>
#include <map>

int bus(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    std::map<int, std::vector<int>> ctner;
    for (int i = 0; i < arr.size(); ++i) {
        ctner[arr[i]].push_back(i);
    }
    int result = 0;
    result += ctner[4].size();
    int result_1_3 = std::min(ctner[1].size(), ctner[3].size());
    if (result_1_3 == ctner[1].size()) {


    }
}
#endif //INC_1STPROGRAM_COMMON_12_BUS_H
