#pragma once

#include "Data.h" // ¬ключаем заголовочный файл Data.h

class Jacob : public Data {
public:
    Jacob(int row = 2);
    ~Jacob();

    bool flag = true;

    void print_answer();
    double calculateResidualNorm(const std::vector<double>& x, int n);
    void performJacobiIterations(double epsilon, int n);
    void computeSpectralRadius();
};
