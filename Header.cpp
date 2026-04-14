#include "Header.h"

template<typename Container>
void printContainer(const Container& cont) {
    using namespace std;
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
void fillFromKeyboard(Container& cont, const std::string& name) {
    using namespace std;
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
void fillFromFile(Container& cont, const std::string& name) {
    using namespace std;
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
void fillRandom(Container& cont, const std::string& name) {
    using namespace std;
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
void fillFromKeyboardString(Container& cont, const std::string& name) {
    using namespace std;
    cont.clear();
    int n;
    cout << "Введите количество элементов в " << name << ": ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите положительное целое число: ";
    }
    cout << "Введите " << n << " слов (заглавными буквами): ";
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
void fillFromFileString(Container& cont, const std::string& name) {
    using namespace std;
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
void fillRandomString(Container& cont, const std::string& name) {
    using namespace std;
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
void fillContainer(Container& cont, const std::string& containerName) {
    using namespace std;
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
void fillContainerString(Container& cont, const std::string& containerName) {
    using namespace std;
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

void task3(std::vector<int>& V0, const std::vector<std::vector<int>>& vectors) {
    using namespace std;
    multiset<int> msV0(V0.begin(), V0.end());
    int count = 0;
    int N = vectors.size();
    for (int i = 0; i < N; ++i) {
        multiset<int> msVi(vectors[i].begin(), vectors[i].end());        
        if (includes(msVi.begin(), msVi.end(), msV0.begin(), msV0.end())) {
            count++;
        }
    }
    cout << "Количество векторов, содержащих все элементы V0 (с учетом повторений): " << count << endl;
}

void task15(std::vector<int>& V) {
    using namespace std;
    map<int, int> M;
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[*it]++; 
    }
    cout << "Результат подсчета повторений:" << endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

void task22(std::vector<std::string>& V) {
    using namespace std;
    multimap<char, string> M;
    for (auto it = V.rbegin(); it != V.rend(); ++it) {
        if (!it->empty()) {
            char lastChar = (*it)[it->length() - 1];
            M.insert(make_pair(lastChar, *it));
        }
    }
    cout << "Результат группировки по последней букве:" << endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}