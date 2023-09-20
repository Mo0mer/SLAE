#include <iostream>
#include <vector>

class Data {
private:
    int row; // Отвечает за количество строк

public:
    Data(int row = 2) : row(row) {}

    ~Data() {}

    std::vector<std::vector<int>> data;
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

        std::vector<int> data_temp;
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
        else {
            for (int i = 0; i < row; i++) {
                data[i].push_back(data_temp[i]);
            }
        }
    }

    void print_vector() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row + 1; j++) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
};

class Kramer : public Data {
private:
    std::vector<double> deter;
    std::vector<bool> view{ false, false, false };
    double det_m = 0, det_1 = 0, det_2 = 0, det_3 = 0;

public:
    Kramer(int row = 2) : Data(row) {}

    ~Kramer() {}

    void decision_order_2() {
        det_m = data[0][0] * data[1][1] - data[1][0] * data[0][1];

        det_1 = data[0][2] * data[1][1] - data[1][2] * data[0][1];
        det_2 = data[0][0] * data[1][2] - data[1][0] * data[0][2];

        if (det_m == 0) {
            if (det_1 == 0 && det_2 == 0) {
                view[1] = true; // СЛАУ имеет бесчисленное множество решений
            }
            else if (det_1 != 0 && det_2 != 0) {
                view[2] = true; // СЛАУ не имеет решений
            }
            return;
        }
        else {
            view[0] = true; // СЛАУ имеет решения

            deter.push_back(det_1);
            deter.push_back(det_2);

            answer.push_back(deter[0] / det_m);
            answer.push_back(deter[1] / det_m);
        }
    }

    void decision_order_3() {
        det_m = data[0][0] * data[1][1] * data[2][2] + data[1][0] * data[2][1] * data[0][2] + data[0][1] * data[1][2] * data[2][0] -
            data[2][0] * data[1][1] * data[0][2] - data[2][1] * data[1][2] * data[0][0] - data[1][0] * data[0][1] * data[2][2];

        det_1 = data[0][3] * data[1][1] * data[2][2] + data[1][3] * data[2][1] * data[0][2] + data[0][1] * data[1][2] * data[2][3] -
            data[2][3] * data[1][1] * data[0][2] - data[2][1] * data[1][2] * data[0][3] - data[1][3] * data[0][1] * data[2][2];

        det_2 = data[0][0] * data[1][3] * data[2][2] + data[1][0] * data[2][3] * data[0][2] + data[0][3] * data[1][2] * data[2][0] -
            data[2][0] * data[1][3] * data[0][2] - data[2][3] * data[1][2] * data[0][0] - data[1][0] * data[0][3] * data[2][2];

        det_3 = data[0][0] * data[1][1] * data[2][3] + data[1][0] * data[2][1] * data[0][3] + data[0][1] * data[1][3] * data[2][0] -
            data[2][0] * data[1][1] * data[0][3] - data[2][1] * data[1][3] * data[0][0] - data[1][0] * data[0][1] * data[2][3];

        if (det_m == 0) {
            if (det_1 == 0 && det_2 == 0 && det_3 == 0) {
                view[1] = true; // СЛАУ имеет бесчисленное множество решений
            }
            else if (det_1 != 0 && det_2 != 0 && det_3 != 0) {
                view[2] = true; // СЛАУ не имеет решений
            }
            return;
        }
        else {
            view[0] = true; // СЛАУ имеет решения

            deter.push_back(det_1);
            deter.push_back(det_2);
            deter.push_back(det_3);

            answer.push_back(deter[0] / det_m);
            answer.push_back(deter[1] / det_m);
            answer.push_back(deter[2] / det_m);
        }
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
private:
    //
public:

    Matr(int row = 2) : Data(row) {};

    ~Matr() {}
};

int main() {
    setlocale(LC_ALL, "Russian");

    int r;

    std::cout << "Введите порядок матрицы: ";
    std::cin >> r;
    std::cout << '\n';

    int method;

    std::cout << "Выберите метод решения СЛАУ:" << '\n' << "1) Крамер" << '\n' << "2) Гаус" << std::endl << '\n';
    std::cin >> method;
    std::cout << '\n';

    if (method == 1) {
        Kramer kr(r);
        kr.make_vector();

        if (r == 2) {
            kr.decision_order_2();
        }
        else if (r >= 3) {
            kr.decision_order_3();
        }

        kr.print_answer();
    }
    else if (method == 2) {
        Gaus gs(r);
        gs.make_vector();
        gs.SolveGaussian(r);
        gs.print_answer();
    }
    else {
        std::cout << "Неверный метод. Выход." << std::endl;
    }

    return 0;
}
