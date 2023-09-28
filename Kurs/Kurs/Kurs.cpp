#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Data {
private:
    int row; // Отвечает за количество строк

public:
    Data(int row = 2) : row(row), answer(row, 0.0) {}

    ~Data() {}

    std::vector<std::vector<int>> data;
    std::vector<int> data_temp;
    std::vector<double> answer;

    void make_vector() {
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

        for (int i = 0; i < row; i++) {
            int inp;
            std::cin >> inp;
            data_temp.push_back(inp);
        }

        if (data_temp.size() != row) {
            if (data_temp.size() > row) {
                std::cout << "Количество значений вектора превышает порядок матрицы, повторите ввод." << '\n';
            }
            else if (data_temp.size() < row) {
                std::cout << "Количество значений вектора меньше порядка матрицы, повторите ввод." << '\n';
            }
            data_temp.clear();

            while (true) {
                int del;
                if (!(std::cin >> del)) {
                    break;
                }
                data_temp.push_back(del);
            }
        }
    }

    void print_vector() {
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
};

class Kramer : public Data {
private:
    std::vector<int> deter;
    std::vector<bool> view{ false, false, false };
    std::vector<std::vector<int>> data_m;

public:
    Kramer(int row = 2) : Data(row) {}

    ~Kramer() {}

    void make_answer(std::vector<int> deter, int row, int det_m) {
        for (int i = 0; i < row; i++) {
            int answer_temp = deter[i] / det_m;
            answer[i] = answer_temp;
        }
    }

    bool allValuesEqualTo(std::vector<int> deter, int row) {
        for (int i = 0; i < row; i++) {
            if (deter[i] != 0) {
                return false;
            }
        }
        return true;
    }

    bool allValuesNotEqualTo(std::vector<int> deter, int row) {
        for (int i = 0; i < row; i++) {
            if (deter[i] == 0) {
                return false;
            }
        }
        return true;
    }

    std::vector<std::vector<int>> swap_koef(int columnIndex, int row) {
        std::vector<std::vector<int>> swap_matrix;

        swap_matrix = data;

        for (int i = 0; i < row; i++) {
            swap_matrix[i][columnIndex] = data_temp[i];
        }

        return swap_matrix;
    }

    int determinant(const std::vector<std::vector<int>>& matrix, int n) {
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

    void decision_order() {
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

    void print_answer() {
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
};

class Gaus : public Data {
private:
    bool mistake = true;

public:
    Gaus(int row = 2) : Data(row) {}

    ~Gaus() {}

    void SolveGaussian() {
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

    void print_answer() {
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
};

class Matr : public Data {
public:

    Matr(int row = 2) : Data(row) {};

    ~Matr() {}

    void print_answer() {
        std::cout << '\n';

        for (double val : answer) {
            if (std::abs(val) < 1e-6) {
                val = 0;
            }
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    void multiplyMatrixVector(std::vector<std::vector<double>>& y) {
        int numRows = y.size();
        int numCols = y[0].size();
        int vectorSize = data_temp.size();

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                answer[i] += y[i][j] * data_temp[j];
            }
        }
    }

    int Gauss(std::vector<std::vector<int>>& matrica_a, int n, std::vector<double>& massiv_b, std::vector<double>& x) {
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

    int INVERSE(std::vector<std::vector<int>>& a, int n, std::vector<std::vector<double>>& y) {
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

    void begin_inverse() {
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

};

class Jacob : public Data {
public:
    Jacob(int row = 2) : Data(row) {};

    bool flag = true;

    ~Jacob() {}

    void print_answer() {
        if (flag) {
            for (int i : answer) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }

    // Функция для вычисления нормы невязки
    double calculateResidualNorm(const std::vector<double>& x, int n) {
        double norm = 0.0;
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                sum += data[i][j] * x[j];
            }
            double residual = sum - data_temp[i];
            norm += residual * residual;
        }
        return sqrt(norm);
    }

    // Функция для выполнения итераций метода Якоби
    void performJacobiIterations(double epsilon, int n) {
        int iterations = 0; // Счетчик итераций
        std::vector<double> x(n, 0.0);

        while (true) { // Бесконечный цикл, который завершится при достижении погрешности
            std::vector<double> x_new(n);

            for (int i = 0; i < n; i++) {
                double sum = 0.0;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        sum += data[i][j] * x[j];
                    }
                }
                x_new[i] = (data_temp[i] - sum) / data[i][i];
            }

            // Проверяем условие выхода
            double residualNorm = calculateResidualNorm(x_new, n);
            std::cout << "Итерация " << iterations + 1 << ", Норма невязки: " << residualNorm << std::endl;

            if (residualNorm < epsilon) {
                std::cout << "Решение найдено с заданной погрешностью." << std::endl;
                
                for (int i = 0; i < n; i++) {
                    answer[i] = x_new[i];
                }
            }

            // Обновляем текущее приближение
            x = x_new;

            iterations++;
        }
    }
    
    void computeSpectralRadius() {
        int n = data.size();

        // Создаем вектор для хранения собственных значений
        std::vector<double> eigenvalues(n, 0.0);

        // Проводим итерации для нахождения собственных значений матрицы
        for (int i = 0; i < n; ++i) {
            std::vector<double> x(n, 1.0); // Начальный приближенный собственный вектор
            double prevEigenvalue = 0.0;

            for (int iteration = 0; iteration < 1000; ++iteration) {
                // Умножаем матрицу на вектор x: Ax = A * x
                std::vector<double> Ax(n, 0.0);
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        Ax[j] += data[j][k] * x[k];
                    }
                }

                // Находим собственное значение как отношение скалярного произведения Ax и x
                double eigenvalue = 0.0;
                for (int j = 0; j < n; ++j) {
                    eigenvalue += Ax[j] * x[j];
                }

                // Нормализуем вектор x
                double norm = 0.0;
                for (int j = 0; j < n; ++j) {
                    norm += x[j] * x[j];
                }
                norm = std::sqrt(norm);

                for (int j = 0; j < n; ++j) {
                    x[j] /= norm;
                }

                // Проверяем на сходимость
                if (std::fabs(eigenvalue - prevEigenvalue) < 1e-6) { // Точность 1e-6
                    eigenvalues[i] = eigenvalue;
                    break;
                }

                prevEigenvalue = eigenvalue;
            }
        }

        // Находим максимальное собственное значение
        double spectral_radius = double(eigenvalues[0]);
        for (int i = 1; i < n; ++i) {
            if (double(eigenvalues[i]) > spectral_radius) {
                spectral_radius = double(eigenvalues[i]);
            }
        }

        if (spectral_radius > 1) {
            flag = false;

            std::cout << std::endl << "Спектральный радиус матрицы больше 1 " << '\n' <<
                "Система не может быть решена методом Якоби" << std::endl << std::endl;
        }
        else {
            double epsilon;
            std::cout << "Введите погрешность вычислений: " << std::endl;
            std::cin >> epsilon;
            performJacobiIterations(epsilon, n);
        }

    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    int r;

    std::cout << "Введите порядок матрицы: ";
    std::cin >> r;
    std::cout << '\n';

    int method;

    std::cout << "Выберите метод решения СЛАУ:" << '\n' << "1) Крамер" << '\n' <<
        "2) Гаус" << std::endl <<
        "3) Матричный" << std::endl <<
        "4) Якоби" << std::endl << '\n';
    std::cin >> method;
    std::cout << '\n';

    if (method == 1) {
        Kramer kr(r);
        kr.make_vector();
        kr.decision_order();
        kr.print_answer();
    }
    else if (method == 2) {
        Gaus gs(r);
        gs.make_vector();
        gs.SolveGaussian();
        gs.print_answer();
    }
    else if (method == 3) {
        Matr mt(r);
        mt.make_vector();
        mt.begin_inverse();
        mt.print_answer();
    }
    else if (method == 4) {
        Jacob jc(r);
        jc.make_vector();
        jc.computeSpectralRadius();
        jc.print_answer();
    }
    else {
        std::cout << "Неверный метод. Выход." << std::endl;
    }

    return 0;
}
