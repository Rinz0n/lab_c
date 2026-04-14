#include "Header.h"
#include "Header.cpp"

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    srand(time(nullptr));
    while (true) {
        cout << "   Демонстрация решения всех задач" << endl;
        cout << "Выберите задачу:" << endl;
        cout << "Ваш выбор: ";
        
        int choice = getIntInput("", 0, 6);
        
        if (choice == 0) {
            cout << "Программа завершена." << endl;
            break;
        }
        
        switch(choice) {
            case 1: Time::demoInput(); break;
            case 2: House::demoInput(); break;
            case 3: Employee::demoInput(); break;
            case 4: EmployeeExtended::demoInput(); break;
            case 5: ImmutableHouse::demoInput(); break;
            case 6: Gun::demoInput(); break;
        }
        
        cout << "\nНажмите Enter для продолжения...";
        clearInput();
        cin.get();
    }
    
    return 0;
}