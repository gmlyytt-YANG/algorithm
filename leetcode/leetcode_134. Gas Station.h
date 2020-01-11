/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_134. Gas Station.h
 * @author gmlyytt@outlook.com
 * @date 2020/01/08 22:34:08
 * @brief 
 * */

#ifndef INC_1STPROGRAM_LEETCODE_134_GAS_STATION_H
#define INC_1STPROGRAM_LEETCODE_134_GAS_STATION_H

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length = gas.size();
        if (length != cost.size() || length == 0) {
            return -1;
        }

        int gas_sum = 0;
        int gas_sum_min = INT_MAX;

        int start = 0;

        for (int i = 0; i < length; ++i) {
            gas_sum += gas[i] - cost[i];
            if (gas_sum < gas_sum_min) {
                gas_sum_min = gas_sum;
                start = (i + 1) % length;
            }
        }

        return (gas_sum < 0) ? -1 : start;
    }
};

#endif //INC_1STPROGRAM_LEETCODE_134_GAS_STATION_H
