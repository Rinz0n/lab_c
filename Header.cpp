#include "Header.h"

void clearInput() {
    using namespace std;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntInput(const std::string& prompt, int minVal, int maxVal) {
    using namespace std;
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        clearInput();
        cout << "Ошибка! Введите целое число: ";
    }
    
    if (minVal != -1 && value < minVal) {
        cout << "Ошибка! Значение должно быть >= " << minVal << ". Повторите ввод: ";
        return getIntInput(prompt, minVal, maxVal);
    }
    if (maxVal != -1 && value > maxVal) {
        cout << "Ошибка! Значение должно быть <= " << maxVal << ". Повторите ввод: ";
        return getIntInput(prompt, minVal, maxVal);
    }
    
    return value;
}

Time::Time(int sec) {
    seconds = sec % 86400;
    if (seconds < 0) seconds += 86400;
}

std::string Time::toString() const {
    using namespace std;
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    stringstream ss;
    ss << hours << ":" 
       << (minutes < 10 ? "0" : "") << minutes << ":"
       << (secs < 10 ? "0" : "") << secs;
    return ss.str();
}

void Time::print() const {
    using namespace std;
    cout << toString() << endl;
}

void Time::demoInput() {
    using namespace std;
    cout << "\nЗаполнение данных для задачи 1" << endl;
    cout << "Выберите способ заполнения:\n";
    cout << "1 - Ввод с клавиатуры\n";
    cout << "2 - Загрузка из файла\n";
    cout << "3 - Случайные значения\n";
    cout << "Ваш выбор: ";
    
    int choice = getIntInput("", 1, 3);
    
    vector<int> times;
    
    switch(choice) {
        case 1: {
            cout << "Введите количество значений времени: ";
            int count = getIntInput("", 1, 100);
            cout << "Введите " << count << " чисел (количество секунд): ";
            for (int i = 0; i < count; i++) {
                int t = getIntInput("");
                times.push_back(t);
            }
            break;
        }
        case 2: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }
            int t;
            while (file >> t) {
                times.push_back(t);
            }
            file.close();
            if (times.empty()) {
                cout << "Файл пуст или содержит некорректные данные!" << endl;
                return;
            }
            cout << "Загружено " << times.size() << " значений из файла." << endl;
            break;
        }
        case 3: {
            srand(time(nullptr));
            int count = getIntInput("Введите количество случайных значений: ", 1, 100);
            for (int i = 0; i < count; i++) {
                times.push_back(rand() % 1000000);
            }
            cout << "Сгенерировано " << count << " случайных значений." << endl;
            break;
        }
    }
    
    cout << "\nРезультаты:\n";
    for (int t : times) {
        Time time(t);
        cout << t << " секунд -> ";
        time.print();
    }
}

House::House(int floors) : floors(floors) {}

std::string House::toString() const {
    using namespace std;
    stringstream ss;
    ss << "дом с " << floors << " ";
    int lastDigit = floors % 10;
    int lastTwoDigits = floors % 100;
    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        ss << "этажами";
    } else if (lastDigit == 1) {
        ss << "этажом";
    } else {
        ss << "этажами";
    }
    return ss.str();
}

void House::print() const {
    using namespace std;
    cout << toString() << endl;
}

void House::demoInput() {
    using namespace std;
    cout << "\nЗаполнение данных для задачи 2" << endl;
    cout << "Выберите способ заполнения:\n";
    cout << "1 - Ввод с клавиатуры\n";
    cout << "2 - Загрузка из файла\n";
    cout << "3 - Случайные значения\n";
    cout << "Ваш выбор: ";
    
    int choice = getIntInput("", 1, 3);
    
    vector<int> floors;
    
    switch(choice) {
        case 1: {
            cout << "Введите количество домов: ";
            int count = getIntInput("", 1, 100);
            cout << "Введите количество этажей для " << count << " домов: ";
            for (int i = 0; i < count; i++) {
                int f = getIntInput("", 1, 1000);
                floors.push_back(f);
            }
            break;
        }
        case 2: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }
            int f;
            while (file >> f) {
                floors.push_back(f);
            }
            file.close();
            cout << "Загружено " << floors.size() << " значений из файла." << endl;
            break;
        }
        case 3: {
            srand(time(nullptr));
            int count = getIntInput("Введите количество случайных домов: ", 1, 100);
            for (int i = 0; i < count; i++) {
                floors.push_back(rand() % 100 + 1);
            }
            cout << "Сгенерировано " << count << " случайных домов." << endl;
            break;
        }
    }
    
    cout << "\nРезультаты:\n";
    for (int f : floors) {
        House house(f);
        house.print();
    }
}

Department::Department(const std::string& name) : name(name), chief(nullptr) {}

void Department::setChief(Employee* emp) { chief = emp; }

std::string Department::getName() const { return name; }

Employee* Department::getChief() const { return chief; }

void Department::print() const {
    using namespace std;
    cout << "Отдел: " << name << endl;
    if (chief) {
        cout << "Начальник: " << chief->getName() << endl;
    } else {
        cout << "Начальник: не назначен" << endl;
    }
}

Employee::Employee(const std::string& name, Department* dept) : name(name), department(dept) {}

std::string Employee::toString() const {
    using namespace std;
    if (department && department->getChief() == this) {
        return name + " начальник отдела " + department->getName();
    } else if (department && department->getChief()) {
        return name + " работает в отделе " + department->getName() 
               + ", начальник которого " + department->getChief()->getName();
    }
    return name;
}

void Employee::print() const {
    using namespace std;
    cout << toString() << endl;
}

void Employee::demoInput() {
    using namespace std;
    cout << "\n--- Заполнение данных для задачи 3 (Сотрудники) ---" << endl;
    
    string deptName;
    cout << "Введите название отдела: ";
    cin >> deptName;
    
    Department dept(deptName);
    
    cout << "Введите количество сотрудников: ";
    int count = getIntInput("", 1, 100);
    
    vector<Employee*> employees;
    vector<string> employeeNames;
    
    cout << "Введите имена сотрудников:\n";
    for (int i = 0; i < count; i++) {
        string name;
        cout << "Сотрудник " << i+1 << ": ";
        cin >> name;
        employees.push_back(new Employee(name, &dept));
        employeeNames.push_back(name);
    }
    
    string chiefName;
    bool chiefFound = false;
    while (!chiefFound) {
        cout << "Введите имя начальника отдела: ";
        cin >> chiefName;
        
        for (const string& name : employeeNames) {
            if (name == chiefName) {
                chiefFound = true;
                break;
            }
        }
        
        if (!chiefFound) {
            cout << "Ошибка! Сотрудника с именем \"" << chiefName << "\" нет в списке сотрудников." << endl;
            cout << "Список сотрудников: ";
            for (size_t i = 0; i < employeeNames.size(); i++) {
                cout << employeeNames[i];
                if (i < employeeNames.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
    
    for (auto emp : employees) {
        if (emp->getName() == chiefName) {
            dept.setChief(emp);
            break;
        }
    }
    
    cout << "\nРезультаты:\n";
    for (auto emp : employees) {
        emp->print();
    }
    
    for (auto emp : employees) {
        delete emp;
    }
}

DepartmentExtended::DepartmentExtended(const std::string& name) : name(name), chief(nullptr) {}

void DepartmentExtended::setChief(EmployeeExtended* emp) { chief = emp; }

void DepartmentExtended::addEmployee(EmployeeExtended* emp) { employees.push_back(emp); }

std::string DepartmentExtended::getName() const { return name; }

EmployeeExtended* DepartmentExtended::getChief() const { return chief; }

const std::vector<EmployeeExtended*>& DepartmentExtended::getEmployees() const { return employees; }

void DepartmentExtended::print() const {
    using namespace std;
    cout << "Отдел: " << name << endl;
    if (chief) {
        cout << "Начальник: " << chief->getName() << endl;
    } else {
        cout << "Начальник: не назначен" << endl;
    }
    cout << "Сотрудников: " << employees.size() << endl;
}

EmployeeExtended::EmployeeExtended(const std::string& name, DepartmentExtended* dept) 
    : name(name), department(dept) {
    if (dept) dept->addEmployee(this);
}

std::string EmployeeExtended::toString() const {
    using namespace std;
    if (department && department->getChief() == this) {
        return name + " начальник отдела " + department->getName();
    } else if (department && department->getChief()) {
        return name + " работает в отделе " + department->getName() 
               + ", начальник которого " + department->getChief()->getName();
    }
    return name;
}

void EmployeeExtended::print() const {
    using namespace std;
    cout << toString() << endl;
}

std::vector<EmployeeExtended*> EmployeeExtended::getDepartmentEmployees() const {
    if (department) return department->getEmployees();
    return {};
}

void EmployeeExtended::demoInput() {
    using namespace std;
    cout << "\n--- Заполнение данных для задачи 4 (Сотрудники расширенные) ---" << endl;
    
    string deptName;
    cout << "Введите название отдела: ";
    cin >> deptName;
    
    DepartmentExtended dept(deptName);
    
    cout << "Введите количество сотрудников: ";
    int count = getIntInput("", 1, 100);
    
    vector<EmployeeExtended*> employees;
    vector<string> employeeNames;
    
    cout << "Введите имена сотрудников:\n";
    for (int i = 0; i < count; i++) {
        string name;
        cout << "Сотрудник " << i+1 << ": ";
        cin >> name;
        employees.push_back(new EmployeeExtended(name, &dept));
        employeeNames.push_back(name);
    }
    
    string chiefName;
    bool chiefFound = false;
    while (!chiefFound) {
        cout << "Введите имя начальника отдела: ";
        cin >> chiefName;
        
        for (const string& name : employeeNames) {
            if (name == chiefName) {
                chiefFound = true;
                break;
            }
        }
        
        if (!chiefFound) {
            cout << "Ошибка! Сотрудника с именем \"" << chiefName << "\" нет в списке сотрудников." << endl;
            cout << "Список сотрудников: ";
            for (size_t i = 0; i < employeeNames.size(); i++) {
                cout << employeeNames[i];
                if (i < employeeNames.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
    
    for (auto emp : employees) {
        if (emp->getName() == chiefName) {
            dept.setChief(emp);
            break;
        }
    }
    
    cout << "\nРезультаты:\n";
    for (auto emp : employees) {
        emp->print();
    }
    
    cout << "\nСписок всех сотрудников через ссылку на первого сотрудника:\n";
    if (!employees.empty()) {
        vector<EmployeeExtended*> allEmps = employees[0]->getDepartmentEmployees();
        for (auto emp : allEmps) {
            cout << "  - " << emp->toString() << endl;
        }
    }
    
    for (auto emp : employees) delete emp;
}

// ========== ImmutableHouse ==========
ImmutableHouse::ImmutableHouse(int floors) : floors(floors) {}

std::string ImmutableHouse::toString() const {
    using namespace std;
    stringstream ss;
    ss << "дом с " << floors << " ";
    int lastDigit = floors % 10;
    int lastTwoDigits = floors % 100;
    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) ss << "этажами";
    else if (lastDigit == 1) ss << "этажом";
    else ss << "этажами";
    return ss.str();
}

void ImmutableHouse::print() const {
    using namespace std;
    cout << toString() << endl;
}

bool ImmutableHouse::tryChangeFloors(int newFloors) {
    using namespace std;
    cout << "Попытка изменить количество этажей с " << floors 
         << " на " << newFloors << " - НЕВОЗМОЖНО!" << endl;
    return false;
}

void ImmutableHouse::demoInput() {
    using namespace std;
    cout << "\nЗаполнение данных для задачи 5" << endl;
    cout << "Выберите способ заполнения:\n";
    cout << "1 - Ввод с клавиатуры\n";
    cout << "2 - Загрузка из файла\n";
    cout << "3 - Случайные значения\n";
    cout << "Ваш выбор: ";
    
    int choice = getIntInput("", 1, 3);
    
    vector<int> floors;
    
    switch(choice) {
        case 1: {
            cout << "Введите количество домов: ";
            int count = getIntInput("", 1, 100);
            cout << "Введите количество этажей: ";
            for (int i = 0; i < count; i++) {
                floors.push_back(getIntInput("", 1, 1000));
            }
            break;
        }
        case 2: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }
            int f;
            while (file >> f) floors.push_back(f);
            file.close();
            cout << "Загружено " << floors.size() << " значений." << endl;
            break;
        }
        case 3: {
            srand(time(nullptr));
            int count = getIntInput("Введите количество случайных домов: ", 1, 100);
            for (int i = 0; i < count; i++) {
                floors.push_back(rand() % 100 + 1);
            }
            cout << "Сгенерировано " << count << " случайных домов." << endl;
            break;
        }
    }
    
    cout << "\nРезультаты:\n";
    for (int f : floors) {
        ImmutableHouse house(f);
        house.print();
    }
    
    cout << "\nДемонстрация невозможности изменения:\n";
    if (!floors.empty()) {
        ImmutableHouse testHouse(floors[0]);
        testHouse.tryChangeFloors(floors[0] + 10);
    }
}

// ========== Gun ==========
Gun::Gun() : bullets(5) {}

Gun::Gun(int bullets) : bullets(bullets) {}

void Gun::shoot() {
    using namespace std;
    if (bullets > 0) {
        cout << "Бах!" << endl;
        bullets--;
    } else {
        cout << "Клац!" << endl;
    }
}

void Gun::print() const {
    using namespace std;
    cout << "Пистолет: " << bullets << (bullets % 10 == 1 && bullets % 100 != 11 ? " патрон" : " патронов") << endl;
}

int Gun::getBullets() const { return bullets; }

void Gun::demoInput() {
    using namespace std;
    cout << "\nЗаполнение данных для задачи 6" << endl;
    cout << "Выберите способ заполнения:\n";
    cout << "1 - Ввод с клавиатуры\n";
    cout << "2 - Загрузка из файла\n";
    cout << "3 - Случайные значения\n";
    cout << "Ваш выбор: ";
    
    int choice = getIntInput("", 1, 3);
    
    vector<int> bulletsList;
    
    switch(choice) {
        case 1: {
            int count = getIntInput("Введите количество пистолетов: ", 1, 100);
            for (int i = 0; i < count; i++) {
                bulletsList.push_back(getIntInput("Введите количество патронов для пистолета " + to_string(i+1) + ": ", 0, 1000));
            }
            break;
        }
        case 2: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            ifstream file(filename);
            if (!file.is_open()) {
                cout << "Ошибка открытия файла!" << endl;
                return;
            }
            int b;
            while (file >> b) bulletsList.push_back(b);
            file.close();
            cout << "Загружено " << bulletsList.size() << " пистолетов." << endl;
            break;
        }
        case 3: {
            srand(time(nullptr));
            int count = getIntInput("Введите количество случайных пистолетов: ", 1, 100);
            for (int i = 0; i < count; i++) {
                bulletsList.push_back(rand() % 21);
            }
            cout << "Сгенерировано " << count << " пистолетов." << endl;
            break;
        }
    }
    
    for (int b : bulletsList) {
        Gun gun(b);
        cout << "\nПистолет с " << b << " патронами:" << endl;
        gun.print();
        cout << "Производим выстрелы (минимум 5 или пока не закончатся):" << endl;
        for (int i = 1; i <= max(5, b + 2); i++) {
            cout << "Выстрел " << i << ": ";
            gun.shoot();
        }
        cout << "Состояние после стрельбы: ";
        gun.print();
        cout << "---" << endl;
    }
}