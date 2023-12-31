#pragma once

#include "Data.h" // �������� ������������ ���� Data.h

class Jacob : public Data {
public:
    Jacob(int row = 2);
    ~Jacob();

    int maxIterations = 3000;

    void print_answer() override;
    double calculateResidualNorm(const std::vector<double>& x, int n);
    void performJacobiIterations(double epsilon, int n);
    void solve() override;
};
