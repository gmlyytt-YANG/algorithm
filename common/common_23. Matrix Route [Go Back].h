/*************************************************************************
 *
 * Copyright (c) 2018 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file common_23. Matrix Route [Go Back].h
 * @author gmlyytt@outlook.com
 * @date 2018/09/16 20:35:00
 * @brief 路径的最小和， 可以任意方向走
 * */

#ifndef INC_1STPROGRAM_COMMON_23_MATRIX_ROUTE_GO_BACK_H
#define INC_1STPROGRAM_COMMON_23_MATRIX_ROUTE_GO_BACK_H

#include "../util/header_util.h"

int matrix_route(std::vector<std::vector<int>> &arr, int row, int col, int rows, int cols) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return -1;
    }
    return 0;
}

#endif //INC_1STPROGRAM_COMMON_23_MATRIX_ROUTE_GO_BACK_H
