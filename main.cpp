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
        deque<int> D;
        list<int> L;
        cout << endl << "Заполнение вектора V " << endl;
        fillContainer(V, "вектор");
        cout << endl << "Заполнение дека D " << endl;
        fillContainer(D, "дек");
        cout << endl <<"Заполнение списка L " << endl;
        fillContainer(L, "список");
        cout << endl << "Исходные контейнеры:" << endl;
        cout << "V: "; printContainer(V);
        cout << "D: "; printContainer(D);
        cout << "L: "; printContainer(L);
        task7(V, D, L);
        cout << endl << "После замены средних элементов:" << endl;
        cout << "V: "; printContainer(V);
        cout << "D: "; printContainer(D);
        cout << "L: "; printContainer(L);
        break;
    }
    
    case 2: {
        vector<int> V;
        deque<int> D;
        cout << endl << "Заполнение вектора V " << endl;
        fillContainer(V, "вектор");
        cout << endl << "Заполнение дека D " << endl;
        fillContainer(D, "дек");
        cout << endl << "Исходные контейнеры:" << endl;
        cout << "V: "; printContainer(V);
        cout << "D: "; printContainer(D);
        task13(V, D);
        cout << endl << "После преобразования:" << endl;
        cout << "V: "; printContainer(V);
        cout << "D: "; printContainer(D);
        break;
    }
    
    case 3: {
        vector<int> V;
        cout << endl << "Заполнение вектора V " << endl;
        fillContainer(V, "вектор");
        cout << endl << "Исходный вектор:" << endl;
        cout << "V: "; printContainer(V);
        task21(V);
        cout << endl << "После удаления трех средних элементов:" << endl;
        cout << "V: "; printContainer(V);
        break;
    }
    
    case 4: {
        string name;
        string symbols;
        cout << endl << "Введите имя файла: ";
        cin >> name;
        cout << "Выберите способ ввода символов:" << endl;
        cout << "1 - С клавиатуры" << endl;
        cout << "2 - Из текстового файла" << endl;
        cout << "Ваш выбор: ";
        int inputChoice;
        while (!(cin >> inputChoice) || (inputChoice != 1 && inputChoice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите 1 или 2: ";
        }
        if (inputChoice == 1) {
            cout << "Введите набор символов: ";
            cin >> symbols;
        } else {
            string inputFile;
            cout << "Введите имя файла с символами: ";
            cin >> inputFile;
            ifstream file(inputFile);
            if (file.is_open()) {
                getline(file, symbols);
                file.close();
                cout << "Символы загружены из файла: " << symbols << endl;
            } else {
                cout << "Ошибка открытия файла! Используем ввод с клавиатуры." << endl;
                cout << "Введите набор символов: ";
                cin >> symbols;
            }
        }
        task17(name, symbols);
        cout << "Результат записан в файл " << name << endl;
        break;
    }
    
    default:
        cout << "Неверный номер задачи!" << endl;
    }
    
    return 0;
}