#include "Header.h"
#include "Header.cpp"

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    cout << "Выберите задачу (1-5):" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
        Stack stack1, stack2;
        cout << endl << "Создание первого стека:" << endl;
        fillStructure(stack1, "первый стек");
        cout << endl << "Создание второго стека:" << endl;
        fillStructure(stack2, "второй стек");
        cout << endl << "Первый стек:" << endl;
        stack1.show();
        cout << "Второй стек:" << endl;
        stack2.show();
        stack2.merge(stack1);
        cout << endl << "Результат (второй стек после слияния):" << endl;
        stack2.show();
        break;
    }

    case 2: {
        Queue queue;
        fillStructure(queue, "очередь");
        cout << endl << "Исходная очередь:" << endl;
        queue.show();
        int N;
        cout << endl << "Сколько элементов извлечь? ";
        cin >> N;
        queue.extractElements(N);
        cout << endl << "Очередь после извлечения:" << endl;
        queue.show();
        break;
    }

    case 3: {
        List list;
        fillStructure(list, "список");
        cout << endl << "Исходный список:" << endl;   
        list.show();
        Node* ptr = list.getPtrToElement(7);
        if (ptr != nullptr) {
            cout << "Указатель на 7-й элемент (Head → ... → 7-й): " << ptr << endl;
            cout << "Значение 7-го элемента: " << ptr->data << endl;
        }
        else {
            cout << "В списке меньше 7 элементов!" << endl;
        }
        break;
    }

    case 4: {
        List list;
        fillStructure(list, "список");
        cout << endl << "Исходный список:" << endl;
        list.show();
        int M;
        cout << "Введите значение M для вставки: ";
        cin >> M;
        list.insertAfterEveryThird(M);
        cout << endl << "Список после вставки:" << endl;
        list.show();
        break;
    }

    case 5: {
    List original;
    fillStructure(original, "исходный список");
    cout << endl << "Исходный список:" << endl;
    original.show();
    int M;
    cout << "Введите значение M для вставки в упорядоченный список: ";
    cin >> M;
    List* copy = original.copySorted(M);
    cout << endl << "Копия списка с вставленным значением " << M << ":" << endl;
    copy->show();
    cout << "Исходный список (не изменился):" << endl;
    original.show();
    delete copy; 
    break;
}
    default:
        cout << "Неверный номер задачи!" << endl;
    }
    return 0;
}