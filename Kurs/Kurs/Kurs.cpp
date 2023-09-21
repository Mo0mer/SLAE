#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Data {
private:
    int row; // Отвечает за количество строк

public:
    Data(int row = 2) : row(row), answer(row, 0.0) {}

    ~Data() {
        // Инициализируем вектор data нулями
        data.resize(row, std::vector<int>(row, 0));
        // Инициализируем вектор data_temp нулями
        data_temp.resize(row, 0);
    }

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

        for (int j = 0; j < row; j++){
            std::cout << data_temp[j] << ' ';
        }

        std:: cout << '\n';
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

    bool allValuesEqualTo(std::vector<int> deter, int row){
        for (int i = 0; i < row; i++) {
            if (deter[i] != 0) {
                return false;
            }
        }
        return true;
    }

    bool allValuesNotEqualTo(std::vector<int> deter, int row){
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
    double pivot = 0, factor = 0;

public:
    Gaus(int row = 2) : Data(row) {}

    ~Gaus() {}

    void SolveGaussian(int n) {
        // Прямой ход метода Гаусса
        for (int i = 0; i < n; i++) {
            // Поиск максимального элемента в текущем столбце для частичного выбора строки
            int maxRow = i;
            for (int j = i + 1; j < n; j++) {
                if (std::abs(data[j][i]) > std::abs(data[maxRow][i])) {
                    maxRow = j;
                }
            }
            // Перестановка строк, если необходимо
            if (maxRow != i) {
                std::swap(data[i], data[maxRow]);
            }
            // Приведение текущей строки к виду, где главный элемент равен 1
            pivot = data[i][i];
            for (int j = i; j <= n; j++) {
                data[i][j] /= pivot;
            }
            // Обнуление элементов под текущим главным элементом
            for (int k = i + 1; k < n; k++) {
                factor = data[k][i];
                for (int j = i; j <= n; j++) {
                    data[k][j] -= factor * data[i][j];
                }
            }
        }
        // Обратный ход метода Гаусса
        for (int i = n - 1; i >= 0; i--) {
            answer[i] = data[i][n];
            for (int j = i + 1; j < n; j++) {
                answer[i] -= data[i][j] * answer[j];
            }
        }
    }

    void print_answer() {
        std::cout << '\n';

        for (double val : answer) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
};

class Matr : public Data {
public:

    Matr(int row = 2) : Data(row) {};

    ~Matr() {}

    void print_answer() {
        std::cout << '\n';

        for (double val : answer) {
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

int main() {
    setlocale(LC_ALL, "Russian");

    int r;

    std::cout << "Введите порядок матрицы: ";
    std::cin >> r;
    std::cout << '\n';

    int method;

    std::cout << "Выберите метод решения СЛАУ:" << '\n' << "1) Крамер" << '\n' << 
                                                            "2) Гаус" << std::endl <<
                                                            "3) Матричный" << std::endl << '\n';
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
        gs.SolveGaussian(r);
        gs.print_answer();
    }
    else if (method == 3) {
        Matr mt(r);
        mt.make_vector();
        mt.begin_inverse();
        mt.print_answer();
    }
    else {
        std::cout << "Неверный метод. Выход." << std::endl;
    }

    return 0;
}
