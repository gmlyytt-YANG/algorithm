/*************************************************************************
 *
 * Copyright (c) 2018 Administrator. All Rights Reserved
 *
 ************************************************************************/

/*
 * @file offer_41. Stream Median .h
 * @author gmlyytt@outlook.com
 * @date 2018/08/16 9:34:00
 * @brief 剑指offer41题 数据流的中位数
 * */

#ifndef INC_1STPROGRAM_OFFER_41_STREAM_MEDIAN_H
#define INC_1STPROGRAM_OFFER_41_STREAM_MEDIAN_H

#include "../util/header_util.h"

template<class T>
class StreamMedian {
public:
    void push(T value) {
        if (((Max.size() + Min.size()) & 1) == 0) {
            if (Max.size() > 0 && value < Max[0]) {
                Max.push_back(value);
                std::push_heap(Max.begin(), Max.end(), std::less<T>());
                value = Max[0];
                std::pop_heap(Max.begin(), Max.end(), std::less<T>());
                Max.pop_back();
            }
            Min.push_back(value);
            std::push_heap(Min.begin(), Min.end(), std::greater<T>());
        } else {
            if (Min.size() > 0 && value > Min[0]) {
                Min.push_back(value);
                std::push_heap(Min.begin(), Min.end(), std::greater<T>());
                value = Min[0];
                std::pop_heap(Min.begin(), Min.end(), std::greater<T>());
                Min.pop_back();
            }
            Max.push_back(value);
            std::push_heap(Max.begin(), Max.end(), std::less<T>());
        }
    }

    T get_median() {
        if (Min.size() + Max.size() == 0) {
            exit(-1);
        }
        if (((Min.size() + Max.size()) & 1) == 0) {
            return (Min[0] + Max[0]) / 2;
        } else {
            return Min[0];
        }
    }

private:
    std::vector<T> Max;
    std::vector<T> Min;
};

void test_stream_median() {
    StreamMedian<int> *sm = new StreamMedian<int>();
    std::vector<int> arr = {5, 4, 3, 5, 1};
    for (auto &elem : arr) {
        sm->push(elem);
        std::cout << sm->get_median() << std::endl;
    }
}

#endif //INC_1STPROGRAM_OFFER_41_STREAM_MEDIAN_H
