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

void task7(vector<int>& V, deque<int>& D, list<int>& L) {
    if (V.size() >= 2 && V.size() % 2 == 0) {
        int mid1 = V.size() / 2 - 1;
        int mid2 = V.size() / 2;
        swap(V[mid1], V[mid2]);  
    }
    if (D.size() >= 2 && D.size() % 2 == 0) {
        auto it1 = D.begin();
        advance(it1, D.size() / 2 - 1);
        auto it2 = it1;
        ++it2;
        swap(*it1, *it2);  
    }
    if (L.size() >= 2 && L.size() % 2 == 0) {
        auto it1 = L.begin();
        advance(it1, L.size() / 2 - 1);
        auto it2 = it1;
        ++it2;
        swap(*it1, *it2);
    }
}

void task13(vector<int>& V, deque<int>& D) {
    if (V.size() % 2 == 0 && D.size() % 2 == 0 && !V.empty() && !D.empty()) {
        size_t halfV = V.size() / 2;
        size_t halfD = D.size() / 2;
        vector<int>::iterator vMid = V.begin();
        advance(vMid, halfV);
        deque<int>::iterator dMid = D.begin();
        advance(dMid, halfD);
        D.insert(D.begin(), V.rbegin(), V.rbegin() + halfV);
        V.insert(V.end(), D.begin() + halfV, dMid);
    }
}

void task21(vector<int>& V) {
    if (V.size() >= 5 && V.size() % 2 != 0) {
        int N = V.size();
        int start = (N / 2) - 1;  
        V.erase(V.begin() + start, V.begin() + start + 3);
    }
}

void task17(const string& name, const string& symbols) {
    ofstream file(name);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    ostream_iterator<int> fileIterator(file, " ");
    stringstream ss(symbols);
    istream_iterator<char> inputBegin(ss);
    istream_iterator<char> inputEnd;
    transform(inputBegin, inputEnd, fileIterator,
              [](char c) { return static_cast<int>(c) * 2; });
    
    file.close();
}

