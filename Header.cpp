#include "Header.h"

Node::Node() : data(0), next(nullptr), prev(nullptr) {}

Node::Node(int value) : data(value), next(nullptr), prev(nullptr) {}

Node::Node(int value, Node* n, Node* p) : data(value), next(n), prev(p) {}

Node::Node(const Node& other) : data(other.data), next(nullptr), prev(nullptr) {}

Node::~Node() {}

RingList::RingList() : first(nullptr) {
    using namespace std;
    cout << "Создано пустое кольцо" << endl;
}

RingList::RingList(const RingList& other) : first(nullptr) {
    using namespace std;
    cout << "Копирование кольца" << endl;
    if (!other.first) return;
    
    Node* cur = other.first;
    do {
        add(cur->data);
        cur = cur->next;
    } while (cur != other.first);
}

RingList::~RingList() {
    using namespace std;
    cout << "Удаление кольца" << endl;
    if (!first) return;
    
    Node* cur = first;
    do {
        Node* next = cur->next;
        delete cur;
        cur = next;
    } while (cur != first);
}

void RingList::add(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    
    if (!first) {
        first = newNode;
        first->next = first;
    } else {
        Node* cur = first;
        while (cur->next != first) cur = cur->next;
        cur->next = newNode;
        newNode->next = first;
    }
    cout << "Добавлено в кольцо: " << value << endl;
}

bool RingList::isEmpty() const {
    return first == nullptr;
}

void RingList::show() const {
    using namespace std;
    if (isEmpty()) {
        cout << "Кольцо пусто" << endl;
        return;
    }
    
    cout << "Содержимое кольца: ";
    Node* cur = first;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while (cur != first);
    cout << endl;
}

void RingList::task1(const std::string& filename) {
    using namespace std;
    ofstream f(filename);
    if (!first) {
        f.close();
        return;
    }

    Node* cur = first;
    
    while (!isEmpty()) {
        // Запоминаем текущий элемент (тот, который выведем)
        Node* toPrint = cur;
        f << toPrint->data << " ";
        
        // Переходим к следующему элементу (он станет новым cur после удаления)
        Node* nextCur = cur->next;
        
        // Удаляем toPrint из списка
        if (cur->next == cur) {
            // Последний элемент
            delete cur;
            first = nullptr;
            break;
        }
        
        // Находим предыдущий элемент для удаления
        Node* prev = cur;
        while (prev->next != cur) {
            prev = prev->next;
        }
        
        prev->next = cur->next;
        if (cur == first) {
            first = cur->next;
        }
        delete cur;
        
        // Теперь нужно сделать шаг (пропустить один элемент)
        // nextCur сейчас указывает на элемент, следующий за удалённым
        if (!isEmpty()) {
            cur = nextCur->next;  // Переход к следующему (пропускаем один)
        }
    }
    
    f.close();
    cout << "Результат записан в файл " << filename << endl;
}

void RingList::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в кольцо? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        add(value);
    }
}

void RingList::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void RingList::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        add(rand() % 100);
    }
}

DoubleList1::DoubleList1() : first(nullptr) {
    using namespace std;
    cout << "Создан пустой двусвязный список" << endl;
}

DoubleList1::DoubleList1(const DoubleList1& other) : first(nullptr) {
    using namespace std;
    cout << "Копирование двусвязного списка" << endl;
    Node* cur = other.first;
    while (cur) {
        add(cur->data);
        cur = cur->next;
    }
}

DoubleList1::~DoubleList1() {
    using namespace std;
    cout << "Удаление двусвязного списка" << endl;
    while (first) {
        Node* cur = first;
        first = first->next;
        delete cur;
    }
}

void DoubleList1::add(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    
    if (!first) {
        first = newNode;
    } else {
        Node* cur = first;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
    }
    cout << "Добавлено в список: " << value << endl;
}

bool DoubleList1::isEmpty() const {
    return first == nullptr;
}

void DoubleList1::show() const {
    using namespace std;
    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return;
    }
    
    cout << "Содержимое списка: ";
    Node* cur = first;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void DoubleList1::task2() {
    using namespace std;
    if (!first) {
        cout << "Список пуст" << endl;
        return;
    }
    
    Node *minNode = first, *maxNode = first;
    Node* cur = first;
    
    while (cur) {
        if (cur->data < minNode->data) minNode = cur;
        if (cur->data > maxNode->data) maxNode = cur;
        cur = cur->next;
    }
    
    if (minNode == maxNode) {
        cout << "Min и Max совпадают" << endl;
        return;
    }
    
    cout << "Min = " << minNode->data << ", Max = " << maxNode->data << endl;
    cout << "Элементы между ними: ";
    
    Node* start = minNode;
    Node* end = maxNode;
    
    cur = first;
    bool minFirst = false;
    while (cur) {
        if (cur == minNode) minFirst = true;
        if (cur == maxNode) break;
        cur = cur->next;
    }
    
    if (minFirst) {
        start = minNode;
        end = maxNode;
    } else {
        start = maxNode;
        end = minNode;
    }
    
    cur = start->next;
    while (cur && cur != end) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void DoubleList1::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в список? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        add(value);
    }
}

void DoubleList1::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void DoubleList1::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        add(rand() % 100);
    }
}

DoubleList2::DoubleList2() : first(nullptr) {
    using namespace std;
    cout << "Создан пустой двусвязный список" << endl;
}

DoubleList2::DoubleList2(const DoubleList2& other) : first(nullptr) {
    using namespace std;
    cout << "Копирование двусвязного списка" << endl;
    Node* cur = other.first;
    while (cur) {
        add(cur->data);
        cur = cur->next;
    }
}

DoubleList2::~DoubleList2() {
    using namespace std;
    cout << "Удаление двусвязного списка" << endl;
    while (first) {
        Node* cur = first;
        first = first->next;
        delete cur;
    }
}

void DoubleList2::add(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    
    if (!first) {
        first = newNode;
    } else {
        Node* cur = first;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
    }
    cout << "Добавлено в список: " << value << endl;
}

bool DoubleList2::isEmpty() const {
    return first == nullptr;
}

void DoubleList2::show() const {
    using namespace std;
    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return;
    }
    
    cout << "Содержимое списка: ";
    Node* cur = first;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void DoubleList2::task3(const std::string& filename) {
    using namespace std;
    ofstream f(filename);
    if (!first) {
        f.close();
        return;
    }
    
    Node* last = first;
    while (last->next) last = last->next;
    
    Node* left = first;
    Node* right = last;
    
    while (left != right && left->prev != right) {
        f << right->data << " " << left->data << " ";
        right = right->prev;
        left = left->next;
    }
    
    if (left == right) {
        f << left->data;
    }
    
    f.close();
    cout << "Результат записан в файл " << filename << endl;
}

void DoubleList2::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в список? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        add(value);
    }
}

void DoubleList2::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void DoubleList2::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        add(rand() % 100);
    }
}

ListWithBarrier::ListWithBarrier() {
    using namespace std;
    list.barrier = new Node(0);
    list.barrier->next = list.barrier;
    list.barrier->prev = list.barrier;
    list.current = list.barrier;
    cout << "Создан список с барьерным элементом" << endl;
}

ListWithBarrier::ListWithBarrier(const ListWithBarrier& other) {
    using namespace std;
    list.barrier = new Node(0);
    list.barrier->next = list.barrier;
    list.barrier->prev = list.barrier;
    list.current = list.barrier;
    
    Node* cur = other.list.barrier->next;
    while (cur != other.list.barrier) {
        add(cur->data);
        cur = cur->next;
    }
    cout << "Копирование списка с барьером" << endl;
}

ListWithBarrier::~ListWithBarrier() {
    using namespace std;
    Node* cur = list.barrier->next;
    while (cur != list.barrier) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    delete list.barrier;
    cout << "Удаление списка с барьером" << endl;
}

void ListWithBarrier::add(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    newNode->prev = list.barrier->prev;
    newNode->next = list.barrier;
    list.barrier->prev->next = newNode;
    list.barrier->prev = newNode;
    list.current = newNode;
    cout << "Добавлено: " << value << endl;
}

void ListWithBarrier::show() const {
    using namespace std;
    if (list.barrier->next == list.barrier) {
        cout << "Список пуст" << endl;
        return;
    }
    
    cout << "Содержимое списка: ";
    Node* cur = list.barrier->next;
    while (cur != list.barrier) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void ListWithBarrier::LBToFirst() {
    list.current = list.barrier->next;
}

void ListWithBarrier::LBToNext() {
    if (list.current != list.barrier) {
        list.current = list.current->next;
    }
}

void ListWithBarrier::LBSetData(int D) {
    if (list.current != list.barrier) {
        list.current->data = D;
    }
}

bool ListWithBarrier::IsBarrier() {
    return list.current == list.barrier;
}

void ListWithBarrier::task4(int& count, Node*& newCurrent) {
    using namespace std;
    count = 0;
    LBToFirst();
    int pos = 1;
    
    while (!IsBarrier()) {
        if (pos % 2 == 1) {
            LBSetData(0);
        }
        count++;
        LBToNext();
        pos++;
    }
    
    newCurrent = list.barrier;
    list.current = list.barrier;
    cout << "Нечетные элементы обнулены" << endl;
}

void ListWithBarrier::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        add(value);
    }
}

void ListWithBarrier::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void ListWithBarrier::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        add(rand() % 100);
    }
}

DoubleList3::DoubleList3() : first(nullptr) {
    using namespace std;
    cout << "Создан пустой двусвязный список" << endl;
}

DoubleList3::DoubleList3(const DoubleList3& other) : first(nullptr) {
    using namespace std;
    cout << "Копирование двусвязного списка" << endl;
    Node* cur = other.first;
    while (cur) {
        add(cur->data);
        cur = cur->next;
    }
}

DoubleList3::~DoubleList3() {
    using namespace std;
    cout << "Удаление двусвязного списка" << endl;
    while (first) {
        Node* cur = first;
        first = first->next;
        delete cur;
    }
}

void DoubleList3::add(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    
    if (!first) {
        first = newNode;
    } else {
        Node* cur = first;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
    }
    cout << "Добавлено в список: " << value << endl;
}

bool DoubleList3::isEmpty() const {
    return first == nullptr;
}

void DoubleList3::show() const {
    using namespace std;
    if (isEmpty()) {
        cout << "Список пуст" << endl;
        return;
    }
    
    cout << "Содержимое списка: ";
    Node* cur = first;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void DoubleList3::task5() {
    using namespace std;
    if (!first) {
        cout << "Список пуст" << endl;
        return;
    }
    
    Node *minNode = first, *maxNode = first;
    Node* cur = first;
    
    while (cur) {
        if (cur->data < minNode->data) minNode = cur;
        if (cur->data > maxNode->data) maxNode = cur;
        cur = cur->next;
    }
    
    if (minNode == maxNode) {
        cout << "Min и Max совпадают" << endl;
        return;
    }
    
    cout << "Min = " << minNode->data << ", Max = " << maxNode->data << endl;
    cout << "Числа между ними в обратном порядке: ";
    
    Node* left = minNode;
    Node* right = maxNode;
    cur = first;
    bool minLeft = false;
    while (cur) {
        if (cur == minNode) minLeft = true;
        if (cur == maxNode) break;
        cur = cur->next;
    }
    
    if (!minLeft) {
        left = maxNode;
        right = minNode;
    }
    
    cur = right->prev;
    while (cur && cur != left) {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
}

void DoubleList3::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в список? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        add(value);
    }
}

void DoubleList3::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void DoubleList3::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        add(rand() % 100);
    }
}

int chooseInputMethod() {
    using namespace std;
    cout << "\nВыберите способ заполнения:" << endl;
    cout << "1 - Ввод с консоли" << endl;
    cout << "2 - Загрузка из файла" << endl;
    cout << "3 - Случайная генерация" << endl;
    cout << "Ваш выбор: ";
    
    int method;
    cin >> method;
    return method;
}

template<typename T>
void fillStructure(T& structure, const std::string& structureName) {
    using namespace std;
    int method = chooseInputMethod();
    switch (method) {
    case 1:
        structure.createFromInput();
        break;
    case 2: {
        string filename;
        cout << "Введите имя файла: ";
        cin >> filename;
        structure.createFromFile(filename);
        break;
    }
    case 3: {
        int count;
        cout << "Сколько случайных чисел сгенерировать? ";
        cin >> count;
        structure.createRandom(count);
        break;
    }
    default:
        cout << "Неверный выбор. Используем ввод с консоли." << endl;
        structure.createFromInput();
    }
}