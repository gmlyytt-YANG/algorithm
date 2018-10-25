cmake_minimum_required(VERSION 3.10)
project(1stProgram)

set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm
        main.cpp
        util/tree_util.h util/tree_util.cpp
        util/list_util.h util/list_util.cpp
        util/header_util.h
        "offer/offer_58. Left Rotate String.h"
        "leetcode/leetcode_73. Set Matrix Zeroes.h" "leetcode/leetcode_216. Combination Sum III.h" "leetcode/leetcode_229. Majority Element II.h")