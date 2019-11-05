cmake_minimum_required(VERSION 3.10)
project(1stProgram)

set(CMAKE_CXX_STANDARD 11)

add_executable(1stProgram
        main.cpp
        util/tree_util.h util/tree_util.cpp
        util/list_util.h util/list_util.cpp
        util/header_util.h
        "offer/offer_58. Left Rotate String.h"
        "leetcode/leetcode_73. Set Matrix Zeroes.h" "leetcode/leetcode_216. Combination Sum III.h" "leetcode/leetcode_229. Majority Element II.h" "leetcode/leetcode_20. Valid Parentheses.h" "leetcode/leetcode_234. Palindrome Linked List.h" "leetcode/leetcode_1. Two Sum.h" "leetcode/leetcode_14. Longest Common Prefix.h" "leetcode/leetcode_58. Length of Last Word.h" "leetcode/leetcode_83. Remove Duplicates from Sorted List.h" "leetcode/leetcode_107. Binary Tree Level Order Traversal II.h" "leetcode/leetcode_108. Convert Sorted Array to Binary Search Tree.h" "leetcode/leetcode_118. Pascal's Triangle.h" util/header_util.cpp competition_classic/competition_classic_5.2.1_pupil_arithmetic.h competition_classic/competition_classic_5.2.2_one_thousand_product.h sumian/sunmian_1_monotone_stack.h)