cmake_minimum_required(VERSION 3.10)
project(1stProgram)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm
        main.cpp
        util/tree_util.h util/tree_util.cpp
        util/list_util.h util/list_util.cpp
        util/header_util.h
        "offer/offer_58. Left Rotate String.h"
        "leetcode/leetcode_73. Set Matrix Zeroes.h" "leetcode/leetcode_216. Combination Sum III.h" "leetcode/leetcode_229. Majority Element II.h" "leetcode/leetcode_148. Sort List.h" "leetcode/leetcode_20. Valid Parentheses.h" "leetcode/leetcode_234. Palindrome Linked List.h" "leetcode/leetcode_1. Two Sum.h")