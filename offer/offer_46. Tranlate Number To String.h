// Created by Li,Yang(Duer04) on 2018/8/18.
// Author: liyang
//
// 把数字翻译成字符串

#ifndef INC_1STPROGRAM_OFFER_46_TRANLATE_NUMBER_TO_STRING_H
#define INC_1STPROGRAM_OFFER_46_TRANLATE_NUMBER_TO_STRING_H

#include <iostream>
#include <vector>

//int translater_number_to_string(int num) {
//    int result = 0;
//    if (num < 0) {
//        return result;
//    }
//    std::string string_num  = std::to_string(num);
//    int length = string_num.size();
//    std::vector<int> counts(length, 1);
//    for (int i = length - 2; i >= 0; --i) {
//        int count = counts[i + 1];
//        int num_i = string_num[i] - '0';
//        int num_i1 = string_num[i + 1] - '0';
//        if (num_i * 10 + num_i1 <= 25 && num_i * 10 + num_i1 >= 10) {
//            if (i == length - 2) {
//                count += 1;
//            } else {
//                count += counts[i + 2];
//            }
//        }
//        counts[i] = count;
//    }
//    return counts[0];
//}

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
