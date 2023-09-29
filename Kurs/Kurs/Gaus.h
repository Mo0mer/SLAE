#pragma once

#include "Data.h" // ¬ключаем заголовочный файл Data.h

class Gaus : public Data {
private:
    bool mistake = true;

public:
    Gaus(int row = 2);
    ~Gaus();

    void SolveGaussian();
    void print_answer();
};
