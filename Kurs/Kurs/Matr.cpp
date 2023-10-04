#include "Matr.h"

Matr::Matr(int row) : Data(row) {}
Matr::~Matr() {}

void Matr::print_answer() {
    std::cout << '\n';

    for (double val : answer) {
        if (std::abs(val) < 1e-6) {
            val = 0;
        }
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

void Matr::multiplyMatrixVector(std::vector<std::vector<double>>& y) {
    int numRows = y.size();
    int numCols = y[0].size();
    int vectorSize = data_temp.size();

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            answer[i] += y[i][j] * data_temp[j];
        }
    }
}

int Matr::Gauss(std::vector<std::vector<int>>& matrica_a, int n, std::vector<double>& massiv_b, std::vector<double>& x) {
    int i, j, k, r;
    double c, M, max, s;
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = matrica_a[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        b[i] = massiv_b[i];
    }

    for (k = 0; k < n; k++) {
        max = fabs(a[k][k]);
        r = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > max) {
                max = fabs(a[i][k]);
                r = i;
            }
        }
        for (j = 0; j < n; j++) {
            c = a[k][j];
            a[k][j] = a[r][j];
            a[r][j] = c;
        }
        c = b[k];
        b[k] = b[r];
        b[r] = c;
        for (i = k + 1; i < n; i++) {
            for (M = a[i][k] / a[k][k], j = k; j < n; j++) {
                a[i][j] -= M * a[k][j];
            }
            b[i] -= M * b[k];
        }
    }

    if (a[n - 1][n - 1] == 0) {
        if (b[n - 1] == 0) return -1;
        else return -2;
    }
    else {
        for (i = n - 1; i >= 0; i--) {
            for (s = 0, j = i + 1; j < n; j++) {
                s += a[i][j] * x[j];
            }
            x[i] = (b[i] - s) / a[i][i];
        }
        return 0;
    }
}

int Matr::INVERSE(std::vector<std::vector<int>>& a, int n, std::vector<std::vector<double>>& y) {
    int i, j, res = 0;
    std::vector<double> b(n);
    std::vector<double> x(n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i) b[j] = 1;
            else b[j] = 0;
        }
        res = Gauss(a, n, b, x);
        if (res != 0) break;
        else {
            for (j = 0; j < n; j++) {
                y[j][i] = x[j];
            }
        }
    }

    if (res != 0) return -1;
    else return 0;
}

void Matr::solve() {
    int N = data_temp.size();

    std::vector<std::vector<double>> matr_one(N, std::vector<double>(N));

    int result = INVERSE(data, N, matr_one);

    if (result == 0) {
        multiplyMatrixVector(matr_one);
    }
    else {
        std::cout << "Обратной матрицы не существует, СЛАУ решений не имеет" << std::endl;
    }
}