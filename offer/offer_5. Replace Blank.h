// Created by Li,Yang(Duer04) on 2018/8/20.
// Author: liyang
//
// 把字符串中的空格替换成指定字符

#ifndef INC_1STPROGRAM_OFFER_5_REPLACE_BLANK_H
#define INC_1STPROGRAM_OFFER_5_REPLACE_BLANK_H

#include <iostream>
#include <vector>

//std::string replace_blank(std::string& str, std::string& replacing_str) {
//    if (str.empty() || replacing_str.empty()) {
//        return "";
//    }
//    int blank_num = 0;
//    int length = str.size();
//    int new_length = 0;
//    for (auto& elem : str) {
//        if (elem == ' ') {
//            ++blank_num;
//        }
//    }
//    new_length = length + (replacing_str.size() - 1) * blank_num;
//    std::string new_string(new_length, ' ');
//    int old_tail = length - 1;
//    int new_tail = new_length - 1;
//    while (old_tail >= 0 && old_tail != new_tail) {
//        if (str[old_tail] == ' ') {
//            for (int i = replacing_str.size() - 1; i >= 0; --i) {
//                new_string[new_tail--] = replacing_str[i];
//            }
//        } else {
//            new_string[new_tail--] = str[old_tail];
//        }
//        --old_tail;
//    }
//    return new_string;
//}

std::string replace_blank(std::string& str, std::string& replacing_str) {
    if (str.empty()) {
        return replacing_str;
    }
    if (replacing_str.empty()) {
        return str;
    }
    int length = str.size();
    int blank_num = 0;
    for (auto& elem : str) {
        if (elem == ' ') {
            ++blank_num;
        }
    }
    int new_length = str.size() + blank_num * (replacing_str.size() - 1);
    int length_replace = replacing_str.size();
    std::string result(str);
    result.resize(new_length);
    int index_new = new_length - 1;
    int index_old = length - 1;
    while (index_old >= 0 && index_new > index_old) {
        if (str[index_old] == ' ') {
            int index_copy = length_replace - 1;
            while (index_copy >= 0) {
                result[index_new--] = replacing_str[index_copy--];
            }
        } else {
            result[index_new--] = str[index_old];
        }
        --index_old;
    }
    return result;
}

void test_replace_blank() {
    std::string str = " hello  world ";
    std::string replacing_str = "%%%%";
    std::string result = replace_blank(str, replacing_str);
}
#endif //INC_1STPROGRAM_OFFER_5_REPLACE_BLANK_H
