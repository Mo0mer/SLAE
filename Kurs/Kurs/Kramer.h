#pragma once

#include "Data.h"

class Kramer : public Data {
private:
    std::vector<int> deter;
    std::vector<bool> view{ false, false, false };
    std::vector<std::vector<int>> data_m;

public:
    Kramer(int row = 2);
    ~Kramer();

    void make_answer(std::vector<int> deter, int row, int det_m);
    bool allValuesEqualTo(std::vector<int> deter, int row);
    bool allValuesNotEqualTo(std::vector<int> deter, int row);
    std::vector<std::vector<int>> swap_koef(int columnIndex, int row);
    int determinant(const std::vector<std::vector<int>>& matrix, int n);
    void solve() override;
    void print_answer() override;
};