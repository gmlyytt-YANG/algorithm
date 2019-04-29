#include "header_util.h"

void print_2_dim_vector(vector<vector<int>>& data) {
    for (auto& elem : data) {
        for (auto& tiny_elem : elem) {
            cout << tiny_elem << " ";
        }
        cout << endl;
    }
}