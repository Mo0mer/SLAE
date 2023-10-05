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
    int iterations = 0; // ������� ��������
    std::vector<double> x(n, 1.0);

    if (iterations >= maxIterations) {
        throw MatrixException("����� �� �������� � �������.");
    }

    while (true) { // ����������� ����, ������� ���������� ��� ���������� �����������
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

        // ��������� ������� ������
        double residualNorm = calculateResidualNorm(x_new, n);
        std::cout << "�������� " << iterations + 1 << ", ����� �������: " << residualNorm << std::endl;

        if (residualNorm < epsilon) {
            std::cout << "������� ������� � �������� ������������." << std::endl;

            for (int i = 0; i < n; i++) {
                answer[i] = x_new[i];
            }
        }

        // ��������� ������� �����������
        x = x_new;

        iterations++;
    }
}

void Jacob::solve() {
    int n = data.size();

    // ������� ������ ��� �������� ����������� ��������
    std::vector<double> eigenvalues(n, 1.0);

    // �������� �������� ��� ���������� ����������� �������� �������
    for (int i = 0; i < n; ++i) {
        std::vector<double> x(n, 1.0); // ��������� ������������ ����������� ������
        double prevEigenvalue = 0.0;

        for (int iteration = 0; iteration < 1000; ++iteration) {
            // �������� ������� �� ������ x: Ax = A * x
            std::vector<double> Ax(n, 0.0);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    Ax[j] += data[j][k] * x[k];
                }
            }

            // ������� ����������� �������� ��� ��������� ���������� ������������ Ax � x
            double eigenvalue = 0.0;
            for (int j = 0; j < n; ++j) {
                eigenvalue += Ax[j] * x[j];
            }

            // ����������� ������ x
            double norm = 0.0;
            for (int j = 0; j < n; ++j) {
                norm += x[j] * x[j];
            }
            norm = std::sqrt(norm);

            for (int j = 0; j < n; ++j) {
                x[j] /= norm;
            }

            // ��������� �� ����������
            if (std::fabs(eigenvalue - prevEigenvalue) < 1e-6) { // �������� 1e-6
                eigenvalues[i] = eigenvalue;
                break;
            }

            prevEigenvalue = eigenvalue;
        }
    }

    // ������� ������������ ����������� ��������
    double spectral_radius = double(eigenvalues[0]);
    for (int i = 1; i < n; ++i) {
        if (double(eigenvalues[i]) > spectral_radius) {
            spectral_radius = double(eigenvalues[i]);
        }
    }

    std::cout << spectral_radius;

    if (spectral_radius >= 1 || spectral_radius <= 0) {

        throw MatrixException("������������ ������ ������� ������ 1. \n������� �� ����� ���� ������ ������� �����");
    }
    else {
        double epsilon;
        try {
            std::cout << "������� ����������� ����������: " << std::endl;
            std::cin >> epsilon;

            if (std::cin.fail() || epsilon <= 0) {
                throw MatrixException("����������� ������ ���� ������������� ������.");
            }

            performJacobiIterations(epsilon, n);
        }
        catch (const InvalidInputException& e) {
            std::cerr << "������ ����� �����������: " << e.what() << std::endl;
        }
    }
}