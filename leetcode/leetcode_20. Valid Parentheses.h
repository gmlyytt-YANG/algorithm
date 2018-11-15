/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file leetcode_20 Valid Parentheses.h
 * @author gmlyytt@outlook.com
 * @date 2018/11/15 18:44
 * */

#ifndef INC_1STPROGRAM_LEETCODE_20_VALID_PARENTHESES_H
#define INC_1STPROGRAM_LEETCODE_20_VALID_PARENTHESES_H

#include "../util/header_util.h"

class Solution{
public:
    bool isValid(string s) {
        int length = s.size();
        stack<char> stk;
        for (int i = 0; i < length; ++i) {
            switch(s[i]) {
                case '(':
                    stk.push(')');
                    break;
                case '{':
                    stk.push('}');
                    break;
                case '[':
                    stk.push(']');
                    break;
                default:
                    if (stk.empty() || s[i] != stk.top()) {
                        return false;
                    }
                    stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};

void test_valid_parentheses() {
    string s = "[[[]]]()()(){}{}{}";
    cout << Solution().isValid(s) << endl;
}
#endif //INC_1STPROGRAM_LEETCODE_20_VALID_PARENTHESES_H
