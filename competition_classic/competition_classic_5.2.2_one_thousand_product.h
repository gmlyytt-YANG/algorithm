/*************************************************************************
 *
 * Copyright (c) 2019 liyang. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file competition_classic_5.2.2_one_thousand_product.h
 * @author gmlyytt@outlook.com
 * @date 2019-07-29
 * @brief 1000!的阶乘
 * */
#ifndef INC_1STPROGRAM_COMPETITION_CLASSIC_5_2_2_ONE_THOUSAND_PRODUCT_H
#define INC_1STPROGRAM_COMPETITION_CLASSIC_5_2_2_ONE_THOUSAND_PRODUCT_H

#include "../util/header_util.h"

static const int max_bit = 3000;

bool one_thousand_product(int n) {
    if (n <= 0) {
        std::cout << "wrong input" << std::endl;
        return false;
    }

    std::vector<int> nums(max_bit, 0);

    nums[0] = 1;
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        for (int j = 0; j < max_bit; ++j) {
            int product_sum = nums[j] * i + carry;
            nums[j] = product_sum % 10;
            carry = product_sum / 10;
        }
    }

    int j = max_bit - 1;
    for (; j >= 0; --j) {
        if (nums[j]) {
            break;
        }
    }

    for (; j >= 0; --j) {
        std::cout << nums[j];
    }
    std::cout << std::endl;

    return true;
}

void test_one_thousand_product() {
    int n = 30;

    if (!one_thousand_product(n)) {
        std::cout << "wrong input" << std::endl;
    }
}

#endif //INC_1STPROGRAM_COMPETITION_CLASSIC_5_2_2_ONE_THOUSAND_PRODUCT_H
