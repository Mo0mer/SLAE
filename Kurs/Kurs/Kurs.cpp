#include <iostream>
#include <vector>

using namespace std;

class Data {
private:
    int row; // отвечает за кол-во строк
   
public:
    Data(int row = 2) :row(row) {};

    vector<vector<int>> data;
    vector<double> answer;
    
    void make_vector() {
        int inp;

        cout << "Заполните матрицу " << row << " порядка:" << '\n' << '\n';

        for (int i = 0; i < row; i++) {
            vector<int> temp;
            for (int j = 0; j < row; j++) {
                cin >> inp;
                temp.push_back(inp);
            }
            data.push_back(temp);
        }

        cout << '\n';

        cout << "Введите вектор свободных членов: ";

        int del;
        vector<int> data_temp;

        while (cin >> del) {
            data_temp.push_back(del);
        }

        if (data_temp.size() != row) {
            
            if (data_temp.size() > row){
                cout << "Количество значений вектора превышает порядок матрицы, повторите ввод." << '\n';
            }
            else if (data_temp.size() < row) {
                cout << "Количество значений вектора меньше порядка матрицы, повторите ввод." << '\n';
            }
            data_temp.clear();

            while (cin >> del) {
                data_temp.push_back(del);
            }
        }
        else {

            for (int i = 0; i < data_temp.size(); i++) {
                data[i].push_back(data_temp[i]);
            }
        }
    }

    void print_vector() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row + 1; j++) {
                cout << data[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

class Kramer: public Data {
private:
    vector<double> deter;
    vector<bool> view{ false, false, false };
    double det_m = 0;

public:
    Kramer(int row = 2) : Data(row) {};

    void decicion_order_2() {
        det_m = data[0][0] * data[1][1] - data[1][0] * data[0][1];

        double det_1 = data[0][2] * data[1][1] - data[1][2] * data[0][1];
        double det_2 = data[0][0] * data[1][2] - data[1][0] * data[0][2];

        if (det_m == 0) {
            if (det_1 == 0 && det_2 == 0) {
                view[1] == true; //СЛАУ имеет бесчил. множество решений
            }
            else if (det_1 != 0 && det_2 != 0) {
                view[2] == true; //СЛАУ не имеет решений
            }
            return;
        }
        else {
            view[0] = true; //СЛАУ имеет решения

            deter.push_back(det_1);
            deter.push_back(det_2);

            answer.push_back((double)deter[0] / det_m);
            answer.push_back((double)deter[1] / det_m);
        }
    }

    void decicion_order_3() {
        det_m = data[0][0] * data[1][1] * data[2][2] + data[1][0] * data[2][1] * data[0][2] + data[0][1] * data[1][2] * data[2][0] -
                data[2][0] * data[1][1] * data[0][2] - data[2][1] * data[1][2] * data[0][0] - data[1][0] * data[0][1] * data[2][2];

        double det_1 = data[0][3] * data[1][1] * data[2][2] + data[1][3] * data[2][1] * data[0][2] + data[0][1] * data[1][2] * data[2][3] -
                        data[2][3] * data[1][1] * data[0][2] - data[2][1] * data[1][2] * data[0][3] - data[1][3] * data[0][1] * data[2][2];

        double det_2 = data[0][0] * data[1][3] * data[2][2] + data[1][0] * data[2][3] * data[0][2] + data[0][3] * data[1][2] * data[2][0] -
                        data[2][0] * data[1][3] * data[0][2] - data[2][3] * data[1][2] * data[0][0] - data[1][0] * data[0][3] * data[2][2];

        double det_3 = data[0][0] * data[1][1] * data[2][3] + data[1][0] * data[2][1] * data[0][3] + data[0][1] * data[1][3] * data[2][0] -
                        data[2][0] * data[1][1] * data[0][3] - data[2][1] * data[1][3] * data[0][0] - data[1][0] * data[0][1] * data[2][3];


        if (det_m == 0) {
            if (det_1 == 0 && det_2 == 0 && det_3 == 0) {
                view[1] == true; //СЛАУ имеет бесчил. множество решений
            }
            else if (det_1 != 0 && det_2 != 0 && det_3 != 0) {
                view[2] == true; //СЛАУ не имеет решений
            }
            return;
        }
        else {
            view[0] = true; //СЛАУ имеет решения

            deter.push_back(det_1);
            deter.push_back(det_2);
            deter.push_back(det_3);

            answer.push_back((double)deter[0] / det_m);
            answer.push_back((double)deter[1] / det_m);
            answer.push_back((double)deter[2] / det_m);
        }
    }

    void print_answer() {

        cout << '\n';

        if (view[0] == true) {
            for (int i = 0; i < answer.size(); i++) {
                cout << answer[i] << ' ';
            }
            cout << '\n';
        }
        else if (view[1] == true) {
            cout << "СЛАУ имеет бесчисленное множество решений." << '\n';
        }
        else if (view[2] == true) {
            cout << "СЛАУ не имеет решений." << '\n';
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int r;

    cout << "Введите порядок матрицы: ";

    cin >> r;

    cout << '\n';

    Kramer kr (r);

    kr.make_vector();

    //kr.print_vector();
    
    if (r == 2) {
        
        kr.decicion_order_2();
    }
    else if (r >= 3) {
        kr.decicion_order_3();
    }

    kr.print_answer();
    
}
