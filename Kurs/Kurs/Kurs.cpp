#include "Data.h"
#include "Kramer.h"
#include "Gaus.h"
#include "Matr.h"
#include "Jacob.h"
#include "exception.h"

int main() {
    setlocale(LC_ALL, "Russian");

    int r;

    std::cout << "Введите порядок матрицы: ";
    std::cin >> r;
    std::cout << '\n';

    int method;

    std::cout << "Выберите метод решения СЛАУ:" << '\n' << "1) Крамер" << '\n' <<
        "2) Гаус (не надо)" << std::endl <<
        "3) Матричный" << std::endl <<
        "4) Якоби (не надо)" << std::endl << '\n';
    std::cin >> method;
    std::cout << '\n';

    Data* solver = nullptr;

    if (method == 1) {
        solver = new Kramer(r);
    }
    else if (method == 2) {
        solver = new Gaus(r);
    }
    else if (method == 3) {
        solver = new Matr(r);
    }
    else if (method == 4) {
        solver = new Jacob(r);
    }
    else {
        std::cout << "Неверный метод. Выход." << std::endl;
        return 1; // Выйти из программы с ошибкой
    }

    if (solver) {
        try {
            solver->make_vector();
            solver->solve(); // Вызываем виртуальную функцию
            solver->print_answer();
        }
        catch (const MatrixException& ex) {
            // Обрабатываем пользовательское исключение
            std::cerr << "Исключение: " << ex.what() << std::endl;
        }
        delete solver; // Освобождаем память
    }

    return 0;
}
