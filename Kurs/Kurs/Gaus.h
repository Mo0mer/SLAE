#pragma once

#include "Data.h" // �������� ������������ ���� Data.h

class Gaus : public Data {
private:
    bool mistake = true;

public:
    Gaus(int row = 2);
    ~Gaus();

    void solve() override;
    void print_answer() override;
};
