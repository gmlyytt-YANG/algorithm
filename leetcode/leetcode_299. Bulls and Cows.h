/*************************************************************************
 *
 * Copyright (c) gmlyytt@outlook.com. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_299. Bulls and Cows.h
 * @author gmlyytt@outlook.com
 * @date 2020/01/05 19:49:40
 * @brief https://leetcode.com/problems/bulls-and-cows/
 * */

#ifndef INC_1STPROGRAM_LEETCODE_299_BULLS_AND_COWS_H
#define INC_1STPROGRAM_LEETCODE_299_BULLS_AND_COWS_H

#include "../util/header_util.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int length_s = secret.size();
        int length_g = secret.size();
        if (length_s != length_g) {
            return "";
        }

        std::vector<int> ctnr(10);
        int cows = 0;
        for (int i = 0; i < length_s; ++i) {
            if (secret[i] == guess[i]) {
                ++cows;
            } else {
                ++ctnr[secret[i] - '0'];
            }
        }

        int bulls = 0;
        for (int i = 0; i < length_g; ++i) {
            int pos = guess[i] - '0';
            if (secret[i] != guess[i] && ctnr[pos] > 0) {
                --ctnr[pos];
                ++bulls;
            }
        }

        return std::to_string(cows) + "A" + std::to_string(bulls) + "B";
    }
};

#endif //INC_1STPROGRAM_LEETCODE_299_BULLS_AND_COWS_H
