#include "Header.h"
#include "Header.cpp"
#include <limits>

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    cout << endl << "Выберите задачу:" << endl;
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите число от 1 до 4: ";
    }
    switch (choice) {
    case 1: {
        vector<int> V;
        cout << endl << "Заполнение вектора V" << endl;
        fillContainer(V, "вектор");
        cout << endl << "Исходный вектор:" << endl;
        cout << "V: "; printContainer(V);
        task1(V);
        cout << endl << "После удаления второго нуля:" << endl;
        cout << "V: "; printContainer(V);
        break;
    }
    case 2: {
        list<int> L1, L2;
        int K;
        cout << endl << "Заполнение списка L1" << endl;
        fillContainer(L1, "список L1");
        cout << endl << "Заполнение списка L2" << endl;
        fillContainer(L2, "список L2");
        cout << endl << "Введите K (0 < K < 10): ";
        while (!(cin >> K) || K <= 0 || K >= 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите число от 1 до 9: ";
        }       
        cout << endl << "Исходные списки:" << endl;
        cout << "L1: "; printContainer(L1);
        cout << "L2: "; printContainer(L2);
        task21(L1, L2, K);
        cout << endl << "После циклического сдвига:" << endl;
        cout << "L1 (сдвиг вправо на " << K << "): "; printContainer(L1);
        cout << "L2 (сдвиг влево на " << K << "): "; printContainer(L2);
        break;
    }
    case 3: {
        deque<string> D;
        cout << endl << "Заполнение дека D словами" << endl;
        fillContainerString(D, "дек");
        task45(D);
        break;
    }
    case 4: {
        list<string> L;
        cout << endl << "Заполнение списка L словами" << endl;
        fillContainerString(L, "список");
        cout << endl << "Исходный список:" << endl;
        cout << "L: "; printContainer(L);  
        task61(L);
        break;
    }
    default:
        cout << "Неверный номер задачи!" << endl;
    }
    return 0;
}