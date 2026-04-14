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
        RingList list;
        fillStructure(list, "кольцо");
        cout << "\nИсходное кольцо:" << endl;
        list.show();
        list.task1("output1.txt");
        break;
    }
    
    case 2: {
        DoubleList1 list;
        fillStructure(list, "список");
        cout << "\nИсходный список:" << endl;
        list.show();
        list.task2();
        break;
    }
    
    case 3: {
        DoubleList2 list;
        fillStructure(list, "список");
        cout << "\nИсходный список:" << endl;
        list.show();
        list.task3("output3.txt");
        break;
    }
    
    case 4: {
        ListWithBarrier list;
        fillStructure(list, "список");
        cout << "\nИсходный список:" << endl;
        list.show();
        int count;
        Node* newCurrent;
        list.task4(count, newCurrent);
        cout << "Количество элементов: " << count << endl;
        cout << "Новый адрес текущего элемента (барьерный): " << newCurrent << endl;
        cout << "Список после обнуления нечетных:" << endl;
        list.show();
        break;
    }
    
    case 5: {
        DoubleList3 list;
        fillStructure(list, "список");
        cout << "\nИсходный список:" << endl;
        list.show();
        list.task5();
        break;
    }
    
    default:
        cout << "Неверный номер задачи!" << endl;
    }
    
    return 0;
}