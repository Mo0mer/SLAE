#include "Gaus.h"

Gaus::Gaus(int row) : Data(row) {}
Gaus::~Gaus() {}

void Gaus::SolveGaussian() {
    int n = data.size();

    const double eps = 0.00001;  // точность

    for (int k = 0; k < n; k++) {
        // Поиск строки с максимальным a[i][k]
        double max = std::abs(data[k][k]);
        int index = k;
        for (int i = k + 1; i < n; i++) {
            if (std::abs(data[i][k]) > max) {
                max = std::abs(data[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps) {
            // нет ненулевых диагональных элементов

            mistake = false;
        }

        std::swap(data[k], data[index]);
        std::swap(data_temp[k], data_temp[index]);

        // Нормализация уравнений
        for (int i = k; i < n; i++) {
            double temp = data[i][k];
            if (std::abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                data[i][j] = (double)data[i][j] / (double)temp;
            data_temp[i] = (double)data_temp[i] / (double)temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                data[i][j] = data[i][j] - data[k][j];
            data_temp[i] = data_temp[i] - data_temp[k];
        }
    }

    // обратная подстановка
    for (int k = n - 1; k >= 0; k--) {
        answer[k] = data_temp[k];
        for (int i = 0; i < k; i++)
            data_temp[i] = data_temp[i] - data[i][k] * answer[k];
    }
}

void Gaus::print_answer() {
    std::cout << '\n';

    if (mistake == true) {
        for (double val : answer) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
    else {
        std::cout << "Решение получить невозможно из-за нулевого столбца " << std::endl;
    }
}