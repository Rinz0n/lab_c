#include "Header.h"

template<typename Container>
void printContainer(const Container& cont) {
    if (cont.empty()) {
        cout << "контейнер пуст" << endl;
        return;
    }
    for (auto it = cont.begin(); it != cont.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename Container>
void fillFromKeyboard(Container& cont, const string& name) {
    cont.clear();
    int n;
    cout << "Введите количество элементов в " << name << ": ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное целое число: ";
    }
    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        int value;
        while (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите целое число: ";
        }
        cont.insert(cont.end(), value);
    }
}

template<typename Container>
void fillFromFile(Container& cont, const string& name) {
    cont.clear();
    string filename;
    cout << "Введите имя файла для " << name << ": ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла! Используем ручной ввод." << endl;
        fillFromKeyboard(cont, name);
        return;
    }
    int value;
    while (file >> value) {
        cont.insert(cont.end(), value);
    }
    file.close();
    if (cont.empty()) {
        cout << "Файл пуст или содержит некорректные данные. Используем ручной ввод." << endl;
        fillFromKeyboard(cont, name);
    } else {
        cout << "Загрузка из файла завершена." << endl;
    }
}

template<typename Container>
void fillRandom(Container& cont, const string& name) {
    cont.clear();
    srand(static_cast<unsigned int>(time(nullptr)));
    int n;
    cout << "Введите количество случайных элементов в " << name << ": ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное целое число: ";
    }
    for (int i = 0; i < n; ++i) {
        cont.insert(cont.end(), rand() % 100);
    }
    cout << "Сгенерировано " << n << " случайных чисел." << endl;
}

template<typename Container>
void fillFromKeyboardString(Container& cont, const string& name) {
    cont.clear();
    int n;
    cout << "Введите количество элементов в " << name << ": ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное целое число: ";
    }
    cout << "Введите " << n << " слов: ";
    for (int i = 0; i < n; ++i) {
        string value;
        while (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите слово: ";
        }
        cont.insert(cont.end(), value);
    }
}

template<typename Container>
void fillFromFileString(Container& cont, const string& name) {
    cont.clear();
    string filename;
    cout << "Введите имя файла для " << name << ": ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла! Используем ручной ввод." << endl;
        fillFromKeyboardString(cont, name);
        return;
    }
    string value;
    while (file >> value) {
        cont.insert(cont.end(), value);
    }
    file.close();
    if (cont.empty()) {
        cout << "Файл пуст или содержит некорректные данные. Используем ручной ввод." << endl;
        fillFromKeyboardString(cont, name);
    } else {
        cout << "Загрузка из файла завершена." << endl;
    }
}

template<typename Container>
void fillRandomString(Container& cont, const string& name) {
    cont.clear();
    srand(static_cast<unsigned int>(time(nullptr)));
    int n;
    cout << "Введите количество случайных элементов в " << name << ": ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное целое число: ";
    }
    vector<string> words = {"APPLE", "DOG", "CAT", "BANANA", "BIRD", "ZEBRA", "ANT", "ELEPHANT", "FISH", "CAR"};
    for (int i = 0; i < n; ++i) {
        cont.insert(cont.end(), words[rand() % words.size()]);
    }
    cout << "Сгенерировано " << n << " случайных слов." << endl;
}

template<typename Container>
void fillContainer(Container& cont, const string& containerName) {
    cout << "\nВыберите способ заполнения " << containerName << ":" << endl;
    cout << "1 - С клавиатуры" << endl;
    cout << "2 - Из файла" << endl;
    cout << "3 - Случайными числами" << endl;
    cout << "Ваш выбор: ";
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите 1, 2 или 3: ";
    }
    
    switch (choice) {
    case 1:
        fillFromKeyboard(cont, containerName);
        break;
    case 2:
        fillFromFile(cont, containerName);
        break;
    case 3:
        fillRandom(cont, containerName);
        break;
    }
}

template<typename Container>
void fillContainerString(Container& cont, const string& containerName) {
    cout << "\nВыберите способ заполнения " << containerName << ":" << endl;
    cout << "1 - С клавиатуры" << endl;
    cout << "2 - Из файла" << endl;
    cout << "3 - Случайными словами" << endl;
    cout << "Ваш выбор: ";
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите 1, 2 или 3: ";
    }
    
    switch (choice) {
    case 1:
        fillFromKeyboardString(cont, containerName);
        break;
    case 2:
        fillFromFileString(cont, containerName);
        break;
    case 3:
        fillRandomString(cont, containerName);
        break;
    }
}

void task1(vector<int>& V) {
    auto it = find(V.begin(), V.end(), 0);
    if (it != V.end()) {
        auto it2 = find(++it, V.end(), 0);
        if (it2 != V.end()) {
            V.erase(it2);
        }
    }
}

void task21(list<int>& L1, list<int>& L2, int K) {
    if (K <= 0 || K >= 10) return;    
    if (L1.size() >= 10) {
        auto it = L1.begin();
        advance(it, L1.size() - K);
        rotate(L1.begin(), it, L1.end());
    }    
    if (L2.size() >= 10) {
        auto it = L2.begin();
        advance(it, K);
        rotate(L2.begin(), it, L2.end());
    }
}

void task45(deque<string>& D) {
    cout << "Исходный дек: ";
    printContainer(D);    
    sort(D.begin(), D.end());
    cout << "После сортировки по алфавиту: ";
    printContainer(D);
    SortbyLength sl; 
    stable_sort(D.begin(), D.end(), sl);
    cout << "После сортировки по длине: ";
    printContainer(D);
}

void task61(list<string>& L) {
    if (L.size() < 2) {
        cout << "Список должен содержать не менее 2 элементов!" << endl;
        return;
    }
    deque<string> D;
    MakePairString pair;  
    adjacent_difference(L.begin(), L.end(), back_inserter(D), pair);
    if (!D.empty()) {
        D.pop_front();
    }
    cout << "Полученный дек: ";
    printContainer(D);
}