#include <iostream>
#include <vector>

using namespace std;

class Data {
private:
    int row; // отвечает за кол-во строк
    int column; // отвечает за кол-во столбцов
   
public:
    Data(int row = 2, int column = 3) :row(row), column(column) {};

    vector<vector<int>> data;
    vector<double> answer;
    
    void make_vector() {
        int inp;
        for (int i = 0; i < row; i++) {
            vector<int> temp;
            for (int j = 0; j < column; j++) {
                cin >> inp;
                temp.push_back(inp);
            }
            data.push_back(temp);
        }
    }

    void print_vector() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
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
    Kramer(int row = 2, int column = 3) : Data(row, column) {};

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

        if (view[0] == true) {
            for (int i = 0; i < 3; i++) {
                cout << answer[i] << ' ';
            }
            cout << '\n';
        }
        else if (view[1] == true) {
            cout << "СЛАУ имеет бесчисленное множество решений" << '\n';
        }
        else if (view[2] == true) {
            cout << "СЛАУ не имеет решений" << '\n';
        }
    }
};

int main()
{
    int r, c;
    cin >> r >> c;

    Kramer kr (r, c);

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
