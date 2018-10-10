/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_46. Tranlate Number To String.h
 * @author gmlyytt@outlook.com
 * @date 2018/08/18 9:34:00
 * @brief 剑指offer46题 把数字翻译成字符串
 * */

#ifndef INC_1STPROGRAM_OFFER_46_TRANLATE_NUMBER_TO_STRING_H
#define INC_1STPROGRAM_OFFER_46_TRANLATE_NUMBER_TO_STRING_H

#include "../util/header_util.h"

int translater_number_to_string(int num) {
    if (num < 0) {
        return 0;
    }
    std::string str = std::to_string(num);
    int length = str.size();
    std::vector<int> dp(length + 1, 0);
    dp[length] = 1;
    dp[length - 1] = 1;
    for (int i = length - 2; i >= 0; --i) {
        int count = dp[i + 1];
        int num_i = str[i] - '0';
        int num_i1 = str[i + 1] - '0';
        int translate_num = num_i * 10 + num_i1;
        if (translate_num >= 0 && translate_num <= 25) {
            count += dp[i + 2];
        }
        dp[i] = count;
    }
    return dp[0];
}

void test_translater_number_to_string() {
    int num;
    int count = 0;
    while (count < 10) {
        std::cin >> num;
        std::cout << translater_number_to_string(num) << std::endl;
        ++count;
    }

}
#endif //INC_1STPROGRAM_OFFER_46_TRANLATE_NUMBER_TO_STRING_H
