#include "Header.h"

Node::Node() : data(0), next(nullptr) {
}

Node::Node(int value) : data(value), next(nullptr) {
}

Node::Node(const Node& other) : data(other.data), next(nullptr) {
}

Node::~Node() {
}

Stack::Stack() : Head(nullptr) {
    using namespace std;
    cout << "Создан пустой стек" << endl;
}

Stack::Stack(const Stack& other) : Head(nullptr) {
    using namespace std;
    cout << "Копирование стека" << endl;
    if (other.Head == nullptr) return;
    int* temp = new int[100];
    int count = 0;
    Node* current = other.Head;
    while (current != nullptr) {
        temp[count++] = current->data;
        current = current->next;
    }
    for (int i = count - 1; i >= 0; i--) {
        push(temp[i]);
    }
    delete[] temp;
}

Stack::~Stack() {
    using namespace std;
    cout << "Удаление стека" << endl;
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    newNode->next = Head;
    Head = newNode;
}

int Stack::pop() {
    using namespace std;
    if (isEmpty()) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    Node* temp = Head;
    int value = temp->data;
    Head = Head->next;
    delete temp;
    cout << "Извлечено из стека: " << value << endl;
    return value;
}

bool Stack::isEmpty() const {
    return Head == nullptr;
}

void Stack::show() const {
    using namespace std;
    if (isEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }
    cout << "Содержимое стека: ";
    Node* current = Head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в стек? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        push(value);
    }
}

void Stack::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    int value;
    cout << "Чтение данных из файла " << filename << ":" << endl;
    while (file >> value) {
        push(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void Stack::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    cout << "Генерация " << count << " случайных чисел:" << endl;
    for (int i = 0; i < count; i++) {
        int value = rand() % 100;
        push(value);
    }
}

void Stack::merge(Stack& other) {
    using namespace std;
    while (!other.isEmpty()) {
        int value = other.pop();
        push(value);
    }
}

Queue::Queue() : Head(nullptr), LastNode(nullptr) {
    using namespace std;
    cout << "Создана пустая очередь" << endl;
}

Queue::Queue(const Queue& other) : Head(nullptr), LastNode(nullptr) {
    using namespace std;
    cout << "Копирование очереди" << endl;
    Node* current = other.Head;
    while (current != nullptr) {
        enqueue(current->data);
        current = current->next;
    }
}

Queue::~Queue() {
    using namespace std;
    cout << "Удаление очереди" << endl;
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    using namespace std;
    Node* newNode = new Node(value);
    if (isEmpty()) {
        Head = LastNode = newNode;
    }
    else {
        LastNode->next = newNode;
        LastNode = newNode;
    }
    cout << "Добавлено в очередь: " << value << endl;
}

int Queue::dequeue() {
    using namespace std;
    if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return -1;
    }
    Node* temp = Head;
    int value = temp->data;
    Head = Head->next;
    if (Head == nullptr) {
        LastNode = nullptr;
    }
    delete temp;
    cout << "Извлечено из очереди: " << value << endl;
    return value;
}
bool Queue::isEmpty() const {
    return Head == nullptr;
}

void Queue::show() const {
    using namespace std;
    if (isEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }
    cout << "Содержимое очереди: ";
    Node* current = Head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Queue::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в очередь? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        enqueue(value);
    }
}

void Queue::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    int value;
    cout << "Чтение данных из файла " << filename << ":" << endl;
    while (file >> value) {
        enqueue(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void Queue::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    cout << "Генерация " << count << " случайных чисел:" << endl;
    for (int i = 0; i < count; i++) {
        int value = rand() % 100;
        enqueue(value);
    }
}

void Queue::extractElements(int N) {
    using namespace std;
    cout << "Извлечение " << N << " элементов из очереди:" << endl;
    for (int i = 0; i < N && !isEmpty(); i++) {
        int value = dequeue();
        cout << "Извлечен: " << value << endl;
    }
    cout << "Новый адрес начала (Head): " << Head << endl;
    cout << "Новый адрес конца (LastNode): " << LastNode << endl;
}

List::List() : Head(nullptr), LastNode(nullptr) {
    using namespace std;
    cout << "Создан пустой список" << endl;
}

List::List(const List& other) : Head(nullptr), LastNode(nullptr) {
    using namespace std;
    cout << "Копирование списка" << endl;
    Node* current = other.Head;
    while (current != nullptr) {
        addToEnd(current->data);
        current = current->next;
    }
}

List::~List() {
    using namespace std;
    cout << "Удаление списка" << endl;
    Node* current = Head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void List::addToEnd(int value) {
    using namespace std;
    Node* newNode = new Node(value);

    if (Head == nullptr) {
        Head = LastNode = newNode;
    }
    else {
        LastNode->next = newNode;
        LastNode = newNode;
    }
    cout << "Добавлено в список: " << value << endl;
}

void List::show() const {
    using namespace std;
    if (Head == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }
    cout << "Содержимое списка: ";
    Node* current = Head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void List::createFromInput() {
    using namespace std;
    int count, value;
    cout << "Сколько чисел добавить в список? ";
    cin >> count;
    cout << "Введите числа: ";
    for (int i = 0; i < count; i++) {
        cin >> value;
        addToEnd(value);
    }
}

void List::createFromFile(const std::string& filename) {
    using namespace std;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }
    int value;
    cout << "Чтение данных из файла " << filename << ":" << endl;
    while (file >> value) {
        addToEnd(value);
    }
    file.close();
    cout << "Загрузка из файла завершена" << endl;
}

void List::createRandom(int count) {
    using namespace std;
    srand(time(nullptr));
    cout << "Генерация " << count << " случайных чисел:" << endl;
    for (int i = 0; i < count; i++) {
        int value = rand() % 100;
        addToEnd(value);
    }
}

Node* List::getPtrToElement(int position) const {
    Node* current = Head;
    int count = 1;
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }
    return current;
}

void List::insertAfterEveryThird(int value) {
    using namespace std;
    cout << "Вставка значения " << value << " после каждого 3-го элемента" << endl;
    Node* current = Head;
    int count = 1;
    while (current != nullptr) {
        if (count % 3 == 0) {
            Node* newNode = new Node(value);
            newNode->next = current->next;
            current->next = newNode;

            if (current == LastNode) {
                LastNode = newNode;
            }

            current = newNode->next;
            count++;
        }
        else {
            current = current->next;
            count++;
        }
    }
}

List* List::copy() const {
    List* newList = new List();
    Node* current = Head;
    while (current != nullptr) {
        newList->addToEnd(current->data);
        current = current->next;
    }
    return newList;
}

List* List::copySorted(int M) const {
    using namespace std;
    cout << "Создание копии списка с вставкой значения " << M << " (с сохранением упорядоченности)" << endl;
    List* newList = new List();
    Node* current = Head;
    bool inserted = false;
    while (current != nullptr) {
        if (!inserted && current->data >= M) {
            newList->addToEnd(M);
            inserted = true;
        }
        newList->addToEnd(current->data);
        current = current->next;
    }
    if (!inserted) {
        newList->addToEnd(M);
    }
    return newList;
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
    case 1: {
        structure.createFromInput();
        break;
    }
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