#include "Data.h"

Data::Data(int row) : row(row), answer(row, 0.0) {}

Data::~Data() {}

void Data::make_vector() {
    std::cout << "Заполните матрицу " << row << " порядка:" << '\n' << '\n';

    for (int i = 0; i < row; i++) {
        std::vector<int> temp;
        for (int j = 0; j < row; j++) {
            int inp;
            std::cin >> inp;
            temp.push_back(inp);
        }
        data.push_back(temp);
    }

    std::cout << '\n';

    std::cout << "Введите вектор свободных членов: ";

    data_temp.reserve(row);

    while (true) {
        int del;
        if (!(std::cin >> del)) {
            break;
        }
        data_temp.push_back(del);
    }

    if (data_temp.size() != row) {
        if (data_temp.size() > row) {
            throw MatrixException("Количество значений вектора превышает порядок матрицы.");
        }
        else if (data_temp.size() < row) {
            throw MatrixException("Количество значений вектора меньше порядка матрицы.");
        }
    }
}

void Data::print_vector() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << data[i][j] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for (int j = 0; j < row; j++) {
        std::cout << data_temp[j] << ' ';
    }

    std::cout << '\n';
}

void solve(){}
void print_answer(){}