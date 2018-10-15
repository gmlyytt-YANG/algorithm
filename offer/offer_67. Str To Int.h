/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_67. Str To Int.h
 * @author gmlyytt@outlook.com
 * @date 2018/10/14 11:09:00
 * @brief 剑指offer67题 字符串转换为整数
 * */

#ifndef INC_1STPROGRAM_OFFER_67_STR_TO_INT_H
#define INC_1STPROGRAM_OFFER_67_STR_TO_INT_H

#include "../util/header_util.h"

int str_to_int(string &str) {
    if (str.empty()) {
        return 0;
    }
    int result = 0;
    bool minus = false;
    int flag = 1;
    int start = 0;
    if (str[0] == '-') {
        minus = true;
        ++start;
    } else if (str[0] == '+') {
        ++start;
    }
    flag = minus ? -1 : 1;
    for (; start < str.size(); ++start) {
        char bit = str[start] - '0';
        if (bit < 0 || bit > 9) {
            return 0;
        }
        result = result * 10 + flag * bit;
        if ((minus && result < (signed int) 0x80000000)
            || (!minus && result > 0x7fffffff)) {
            return 0;
        }
    }
    return result;
}

void test_str_to_int() {
    string a = "-1012029";
    int a_int = str_to_int(a);
    cout << a_int << endl;
}

#endif //INC_1STPROGRAM_OFFER_67_STR_TO_INT_H
