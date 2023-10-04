#include "Kramer.h"

Kramer::Kramer(int row) : Data(row) {}
Kramer::~Kramer(){}

void Kramer::make_answer(std::vector<int> deter, int row, int det_m) {
    for (int i = 0; i < row; i++) {
        int answer_temp = deter[i] / det_m;
        answer[i] = answer_temp;
    }
}

bool Kramer::allValuesEqualTo(std::vector<int> deter, int row) {
    for (int i = 0; i < row; i++) {
        if (deter[i] != 0) {
            return false;
        }
    }
    return true;
}

bool Kramer::allValuesNotEqualTo(std::vector<int> deter, int row) {
    for (int i = 0; i < row; i++) {
        if (deter[i] == 0) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> Kramer::swap_koef(int columnIndex, int row) {
    std::vector<std::vector<int>> swap_matrix;

    swap_matrix = data;

    for (int i = 0; i < row; i++) {
        swap_matrix[i][columnIndex] = data_temp[i];
    }

    return swap_matrix;
}

int Kramer::determinant(const std::vector<std::vector<int>>& matrix, int n) {
    // Базовый случай: матрица 1x1
    if (n == 1) {
        return matrix[0][0];
    }

    int det = 0;
    int sign = 1;

    // Создаем минор матрицы меньшего размера
    std::vector<std::vector<int>> minor(n - 1, std::vector<int>(n - 1, 0));

    for (int i = 0; i < n; ++i) {
        int minorRow = 0;
        for (int j = 1; j < n; ++j) {
            int minorCol = 0;
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    minor[minorRow][minorCol] = matrix[j][k];
                    minorCol++;
                }
            }
            minorRow++;
        }

        // Рекурсивно вычисляем определитель минора и добавляем к общему определителю
        det += sign * matrix[0][i] * determinant(minor, n - 1);
        sign = -sign;
    }

    return det;
}

void Kramer::solve() {
    int row = data.size();

    data_m = data;

    int det_m = determinant(data_m, row);

    for (int d = 0; d < row; d++) {
        std::vector<std::vector<int>> data_t = swap_koef(d, row);

        int det_t = determinant(data_t, row);

        deter.push_back(det_t);

    }
    if (det_m == 0) {
        bool all_equal = false, all_not_equal = false;

        all_equal = allValuesEqualTo(deter, row);
        all_not_equal = allValuesNotEqualTo(deter, row);

        if (all_equal == true && all_not_equal == false) {
            view[1] = true; // СЛАУ имеет бесчисленное множество решений
        }
        else if (all_not_equal == true && all_equal == false) {
            view[2] = true; // СЛАУ не имеет решений
        }
    }
    else {
        view[0] = true; // СЛАУ имеет решения
    }

    make_answer(deter, row, det_m);
}

void Kramer::print_answer() {
    std::cout << '\n';

    if (view[0] == true) {
        for (double val : answer) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
    else if (view[1] == true) {
        std::cout << "СЛАУ имеет бесчисленное множество решений." << '\n';
    }
    else if (view[2] == true) {
        std::cout << "СЛАУ не имеет решений." << '\n';
    }
}