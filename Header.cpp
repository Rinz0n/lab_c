#include "Header.h"

Node::Node() : data(0), left(nullptr), right(nullptr) {}
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}
Node::Node(int value, Node* l, Node* r) : data(value), left(l), right(r) {}
Node::Node(const Node& other) : data(other.data), left(nullptr), right(nullptr) {}
Node::~Node() {}

Tree::Tree() : root(nullptr) {
    std::cout << "Создано пустое дерево поиска" << std::endl;
}

Tree::Tree(const Tree& other) : root(nullptr) {
    std::cout << "Копирование дерева" << std::endl;
}

Tree::~Tree() {
    std::cout << "Удаление дерева" << std::endl;
    destroyTree(root);
}

void Tree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void Tree::addNode(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
        return;
    }
    if (value < node->data) {
        addNode(node->left, value);
    }
    else if (value > node->data) {
        addNode(node->right, value);
    }
}

void Tree::add(int value) {
    addNode(root, value);
    std::cout << "Добавлено в дерево: " << value << std::endl;
}

bool Tree::isEmpty() const {
    return root == nullptr;
}

void Tree::printTreeGraphic(Node* node, int space, int indent) {
    if (!node) return;
    space += indent;
    printTreeGraphic(node->right, space, indent);
    std::cout << std::endl;
    for (int i = indent; i < space; i++) {
        std::cout << " ";
    }
    std::cout << node->data << std::endl;
    printTreeGraphic(node->left, space, indent);
}

void Tree::show() {
    if (isEmpty()) {
        std::cout << "Дерево пусто" << std::endl;
        return;
    }
    std::cout << "\n=== СТРУКТУРА ДЕРЕВА (графическое представление) ===" << std::endl;
    printTreeGraphic(root, 0, 5);
    std::cout << "=====================================================" << std::endl;
}

void Tree::showGraphic() {
    show();
}

int Tree::getHeight(Node* node) {
    if (!node) return 0;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* Tree::findMax(Node* node) {
    if (!node) return nullptr;
    while (node->right) {
        node = node->right;
    }
    return node;
}

int Tree::task6() {
    if (isEmpty()) {
        std::cout << "Ошибка: дерево пусто!" << std::endl;
        return -1;
    }
    Node* maxNode = findMax(root);
    int maxValue = maxNode->data;
    std::cout << "Максимальное значение в дереве: " << maxValue << std::endl;
    return maxValue;
}

Node* Tree::search(Node* node, int key, int& count) {
    count++;
    if (!node) return nullptr;
    if (key == node->data) {
        return node;
    }
    else if (key < node->data) {
        return search(node->left, key, count);
    }
    else {
        return search(node->right, key, count);
    }
}

Node* Tree::task15(int K, int& N) {
    N = 0;
    if (isEmpty()) {
        std::cout << "Дерево пусто!" << std::endl;
        return nullptr;
    }
    Node* result = search(root, K, N);
    if (result) {
        std::cout << "Вершина со значением " << K << " найдена!" << std::endl;
        std::cout << "Указатель на вершину: " << result << std::endl;
    }
    else {
        std::cout << "Вершина со значением " << K << " не найдена!" << std::endl;
    }
    std::cout << "Количество проанализированных вершин: " << N << std::endl;
    return result;
}

void Tree::printLevel(Node* node, int level, int targetLevel, std::vector<int>& result) {
    if (!node) return;
    if (level == targetLevel) {
        result.push_back(node->data);
        return;
    }
    printLevel(node->left, level + 1, targetLevel, result);
    printLevel(node->right, level + 1, targetLevel, result);
}

void Tree::task22(int K, std::vector<int>& result) {
    result.clear();
    if (isEmpty()) {
        std::cout << "Дерево пусто!" << std::endl;
        return;
    }
    if (K < 0) {
        std::cout << "Ошибка: уровень не может быть отрицательным!" << std::endl;
        return;
    }
    printLevel(root, 0, K, result);
    std::cout << "Вершины на " << K << "-м уровне (слева направо): ";
    if (result.empty()) {
        std::cout << "нет вершин";
    }
    else {
        for (int val : result) {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}

void Tree::createFromInput() {
    int count, value;
    std::cout << "Сколько чисел добавить в дерево? ";
    std::cin >> count;
    std::cout << "Введите числа (без повторений): ";
    for (int i = 0; i < count; i++) {
        std::cin >> value;
        add(value);
    }
}

void Tree::createFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла " << filename << std::endl;
        return;
    }
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
    std::cout << "Загрузка из файла завершена" << std::endl;
}

void Tree::createRandom(int count) {
    srand(time(nullptr));
    for (int i = 0; i < count; i++) {
        int value = rand() % 200 - 100;
        add(value);
    }
}

Validator::Validator() {}

bool Validator::isBST(Node* node, int min, int max) {
    if (!node) return true;
    if (node->data < min || node->data > max) {
        return false;
    }
    return isBST(node->left, min, node->data - 1) &&
        isBST(node->right, node->data + 1, max);
}

int Validator::getNodeCount(Node* node) {
    if (!node) return 0;
    return 1 + getNodeCount(node->left) + getNodeCount(node->right);
}

bool Validator::hasDuplicates(Node* node) {
    if (!node) return false;
    return false;
}

bool Validator::validateTree(Tree& tree) {
    if (tree.isEmpty()) {
        return true;
    }
    return isBST(tree.getRoot(), INT_MIN, INT_MAX);
}

void Validator::printValidationResult(Tree& tree) {
    std::cout << "\n=== ПРОВЕРКА КОРРЕКТНОСТИ ДЕРЕВА ===" << std::endl;
    if (validateTree(tree)) {
        std::cout << "✓ Дерево является корректным деревом поиска!" << std::endl;
        std::cout << "✓ Свойство BST соблюдено (левые < корень < правые)" << std::endl;
    }
    else {
        std::cout << "✗ Дерево НЕ является корректным деревом поиска!" << std::endl;
    }
    if (!tree.isEmpty()) {
        std::cout << "✓ Количество вершин: " << getNodeCount(tree.getRoot()) << std::endl;
    }
    std::cout << "=====================================" << std::endl;
}

int chooseInputMethod() {
    std::cout << "\nВыберите способ заполнения:" << std::endl;
    std::cout << "1 - Ввод с консоли" << std::endl;
    std::cout << "2 - Загрузка из файла" << std::endl;
    std::cout << "3 - Случайная генерация" << std::endl;
    std::cout << "Ваш выбор: ";
    int method;
    std::cin >> method;
    return method;
}

template<typename T>
void fillStructure(T& structure, const std::string& structureName) {
    int method = chooseInputMethod();
    switch (method) {
    case 1:
        structure.createFromInput();
        break;
    case 2: {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        structure.createFromFile(filename);
        break;
    }
    case 3: {
        int count;
        std::cout << "Сколько случайных чисел сгенерировать? ";
        std::cin >> count;
        structure.createRandom(count);
        break;
    }
    default:
        std::cout << "Неверный выбор. Используем ввод с консоли." << std::endl;
        structure.createFromInput();
    }
}