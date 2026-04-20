#include "Header.h"
void printSeparator() {
    std::cout << "\n" << std::string(60, '=') << "\n" << std::endl;
}
int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    cout << "Выберите задачу:" << endl;
    int choice;
    cin >> choice;
    Tree tree;
    Validator validator;
    switch (choice) {
    case 6: {
        fillStructure(tree, "дерево");
        printSeparator();
        cout << "Исходное дерево:" << endl;
        tree.show();
        printSeparator();
        validator.printValidationResult(tree);
        printSeparator();
        cout << "Результат задачи tree work 6:" << endl;
        int maxValue = tree.task6();
        cout << "Ответ: максимальное значение = " << maxValue << endl;
        break;
    }
    case 15: {
        fillStructure(tree, "дерево");
        printSeparator();
        cout << "Исходное дерево:" << endl;
        tree.show();
        printSeparator();
        validator.printValidationResult(tree);
        printSeparator();
        cout << "Результат задачи tree work 15:" << endl;
        int K;
        cout << "Введите значение K для поиска: ";
        cin >> K;
        int N;
        Node* P2 = tree.task15(K, N);
        cout << "\nИтоговый ответ:" << endl;
        if (P2) {
            cout << "P2 = " << P2 << " (указатель на вершину со значением " << K << ")" << endl;
        }
        else {
            cout << "P2 = NULL" << endl;
        }
        cout << "N = " << N << " (количество проанализированных вершин)" << endl;
        break;
    }
    case 22: {
        fillStructure(tree, "дерево");
        printSeparator();
        cout << "Исходное дерево:" << endl;
        tree.show();
        printSeparator();
        validator.printValidationResult(tree);
        printSeparator();
        cout << "Результат задачи tree work 22:" << endl;
        int K;
        cout << "Введите номер уровня K (нумерация с 0): ";
        cin >> K;
        vector<int> result;
        tree.task22(K, result);
        cout << "\nИтоговый ответ: ";
        if (result.empty()) {
            cout << "на уровне " << K << " нет вершин";
        }
        else {
            cout << "значения вершин на " << K << "-м уровне (слева направо): ";
            for (size_t i = 0; i < result.size(); i++) {
                cout << result[i];
                if (i < result.size() - 1) cout << ", ";
            }
        }
        cout << endl;
        break;
    }
    default:
        cout << "Ошибка: неверный номер задачи! Выберите 6, 15 или 22." << endl;
        return 1;
    }
    printSeparator();
    cout << "Программа завершена." << endl;
    return 0;
}