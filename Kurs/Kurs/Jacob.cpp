#include "Jacob.h"

Jacob::Jacob(int row) : Data(row) {}
Jacob::~Jacob(){}

void Jacob::print_answer() {
    for (int i : answer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

double Jacob::calculateResidualNorm(const std::vector<double>& x, int n) {
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

void Jacob::performJacobiIterations(double epsilon, int n) {
    int iterations = 0; // Счетчик итераций
    std::vector<double> x(n, 1.0);

    if (iterations >= maxIterations) {
        throw MatrixException("Метод не сходится к решению.");
    }

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

void Jacob::solve() {
    int n = data.size();

    // Создаем вектор для хранения собственных значений
    std::vector<double> eigenvalues(n, 1.0);

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

    std::cout << spectral_radius;

    if (spectral_radius >= 1 || spectral_radius <= 0) {

        throw MatrixException("Спектральный радиус матрицы больше 1. \nСистема не может быть решена методом Якоби");
    }
    else {
        double epsilon;
        try {
            std::cout << "Введите погрешность вычислений: " << std::endl;
            std::cin >> epsilon;

            if (std::cin.fail() || epsilon <= 0) {
                throw MatrixException("Погрешность должна быть положительным числом.");
            }

            performJacobiIterations(epsilon, n);
        }
        catch (const InvalidInputException& e) {
            std::cerr << "Ошибка ввода погрешности: " << e.what() << std::endl;
        }
    }
}