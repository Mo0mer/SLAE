#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Data {
private:
    int row;

public:
    Data(int row = 2);
    ~Data();

    std::vector<std::vector<int>> data;
    std::vector<int> data_temp;
    std::vector<double> answer;

    void make_vector();
    void print_vector();
    virtual void solve(){}
    virtual void print_answer(){}
};