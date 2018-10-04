// Created by Administrator on 2018/9/14.
// Author: liyang
//
// 用O(n)的方法刪除字符串内多余的括号,
// 例如，从abc,,,bdc,,a中删除多余的三个, 保留下能够分割字符串的,

#ifndef INC_1STPROGRAM_COMMON_21_DELETE_COMMA_H
#define INC_1STPROGRAM_COMMON_21_DELETE_COMMA_H

#include <iostream>

void move_string_part(std::string& str, int start, int end) {
    if (start < str.size() && end >= 0 && start > end) {
        for (int i = start; i < str.size(); ++i) {
            str[end++] = str[i];
        }
    }
}

void delete_comma(std::string &str) {
    if (str.empty()) {
        return;
    }
    int length = str.size();
    int start_comma = length - 1;
    int end_comma = start_comma;
    int comma_count = 0;
    std::cout << str << std::endl;
    for (int i = length - 2; i >= 1; --i) {
        int start_temp = start_comma;
        int end_temp = end_comma;
        if (str[i] == ',') {
            if (str[i + 1] != ',') {
                start_comma = i;
            } else if (str[i - 1] != ',') {
                end_comma = i;
            }
        }
        if (start_comma > end_comma && (start_comma != start_temp || end_comma != end_temp)) {
            move_string_part(str, start_comma, end_comma);
            std::cout << start_comma << " " << end_comma << " " << str << std::endl;
            comma_count += start_comma-end_comma;
        }
    }
    std::cout << comma_count << std::endl;
    for (int i = 0; i < comma_count; ++i) {
        str[length - 1 - i] = '\0';
    }
    std::cout << str << std::endl;
}

void test_delete_comma() {
    std::string str = "abc,,,bdc,,a";
    delete_comma(str);
    // std::cout << str << std::endl;
}

#endif //INC_1STPROGRAM_COMMON_21_DELETE_COMMA_H
