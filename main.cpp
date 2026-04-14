#include "Header.h"
#include "Header.cpp"
#include <limits>

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    cout << "Выберите задачу:" << endl;
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите число от 1 до 3: ";
    }
    switch (choice) {
    case 1: { 
        vector<int> V0;
        cout << "Заполнение вектора V0" << endl;
        fillContainer(V0, "вектор V0");
        int N;
        cout << endl << "Введите количество векторов V1...VN (N > 0): ";
        while (!(cin >> N) || N <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите положительное число: ";
        }
        vector<vector<int>> vectors(N);
        for (int i = 0; i < N; ++i) {
            string name = "вектор V" + to_string(i + 1);
            cout << endl << "Заполнение " << name << endl;
            fillContainer(vectors[i], name);
        }
        cout << "Вектор V0: ";
        printContainer(V0);
        for (int i = 0; i < N; ++i) {
            cout << "V" << i + 1 << ": ";
            printContainer(vectors[i]);
        }
        task3(V0, vectors);
        break;
    }
    case 2: { 
        vector<int> V;
        cout << "Заполнение вектора V" << endl;
        fillContainer(V, "вектор");
        cout << "Исходный вектор:" << endl;
        cout << "V: ";
        printContainer(V);
        task15(V);
        break;
    }
    case 3: { 
        vector<string> V;
        cout << "Заполнение вектора V словами (заглавными буквами)" << endl;
        fillContainerString(V, "вектор");
        cout << "Исходный вектор:" << endl;
        cout << "V: ";
        printContainer(V);
        task22(V);
        break;
    }
    default:
        cout << "Неверный номер задачи!" << endl;
    }
    return 0;
}