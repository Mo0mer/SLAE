#include "Data.h"
#include "Kramer.h"
#include "Gaus.h"
#include "Matr.h"
#include "Jacob.h"

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

    if (method == 1) {
        Kramer kr(r);
        kr.make_vector();
        kr.decision_order();
        kr.print_answer();
    }
    else if (method == 2) { // Гаус выдает не до конца правильные ответы
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
    else if (method == 4) { // Тоже куча своих тараканов
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
