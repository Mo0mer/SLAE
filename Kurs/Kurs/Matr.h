#pragma once

#include "Data.h" // ¬ключаем заголовочный файл Data.h

class Matr : public Data {
public:
    Matr(int row = 2);
    ~Matr();

    void print_answer();
    void multiplyMatrixVector(std::vector<std::vector<double>>& y);
    int Gauss(std::vector<std::vector<int>>& matrica_a, int n, std::vector<double>& massiv_b, std::vector<double>& x);
    int INVERSE(std::vector<std::vector<int>>& a, int n, std::vector<std::vector<double>>& y);
    void begin_inverse();
};
