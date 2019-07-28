/*************************************************************************
 *
 * Copyright (c) 2019 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file competition_classic_5.2.1_pupil_arithmetic.h
 * @author gmlyytt@outlook.com
 * @date 2019-07-28
 * @brief 计算两个整数在相加时需要多少次进位
 * */
#ifndef INC_1STPROGRAM_COMPETITION_CLASSIC_5_2_1_PUPIL_ARITHMETIC_H
#define INC_1STPROGRAM_COMPETITION_CLASSIC_5_2_1_PUPIL_ARITHMETIC_H

#include "../util/header_util.h"

bool split(const std::string &s, const std::string &elem, std::pair<std::string, std::string> *result) {
    if (s.empty() || elem.empty() || result == nullptr) {
        return false;
    }

    size_t location = s.find(elem);

    if (location == std::string::npos) {
        return false;
    }

    // multi sub string
    std::cout << s.find_first_of(elem) << std::endl;
    std::cout << s.find_last_of(elem) << std::endl;
    if (s.find_first_of(elem) != s.find_last_of(elem)) {
        return false;
    }

    string s1 = s.substr(0, location);
    string s2 = s.substr(location + 1, s.size() - location - 1);

    *result = std::make_pair(s1, s2);

    return true;
}

void test_pupil_arithmetic() {
    // variable definition
    std::string s;
    std::string s1;
    std::string s2;
    std::string split_seperator(" ");

    int carry = 0;
    int count = 0;
    int sum = 0;

    // while input
    while (std::getline(std::cin, s)) {
        // judge
        if (s == "00" && s.empty()) {
            std::cout << 0 << std::endl;
            break;
        }

        // split
        std::pair<std::string, std::string> split_result;
        if (!split(s, split_seperator, &split_result)) {
            std::cout << "invalid input!" << std::endl;
            continue;
        }

        s1 = split_result.first;
        s2 = split_result.second;
        if (s1.empty() || s2.empty()) {
            std::cout << 0 << std::endl;
            continue;
        }

        // while carry sum
        int s1_i = s1.size() - 1;
        int s2_i = s2.size() - 1;

        while (s1_i >= 0 || s2_i >= 0 || carry > 0) {
            int n1 = s1_i >= 0 ? s1[s1_i] - '0' : 0;
            int n2 = s2_i >= 0 ? s2[s2_i] - '0' : 0;

            sum = n1 + n2 + carry;
            if (sum >= 10) {
                carry = 1;
                ++count;
            } else {
                carry = 0;
            }

            --s1_i;
            --s2_i;
        }

        std::cout << count << std::endl;
        count = 0;
    }
}

#endif //INC_1STPROGRAM_COMPETITION_CLASSIC_5_2_1_PUPIL_ARITHMETIC_H
