#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <locale>
#include <queue>
#include <vector>
#include <iomanip>
#include <climits>

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node();
    Node(int value);
    Node(int value, Node* l, Node* r);
    Node(const Node& other);
    ~Node();
    friend class Tree;
    friend class Validator;
    friend int main();
};

class Tree {
private:
    Node* root;
    void addNode(Node*& node, int value);
    Node* findMax(Node* node);
    Node* search(Node* node, int key, int& count);
    void printLevel(Node* node, int level, int targetLevel, std::vector<int>& result);
    int getHeight(Node* node);
    void printTreeGraphic(Node* node, int space, int indent);
    void destroyTree(Node* node);

public:
    Tree();
    Tree(const Tree& other);
    ~Tree();
    void add(int value);
    bool isEmpty() const;
    void show();
    void showGraphic();
    int task6();  
    Node* task15(int K, int& N);  
    void task22(int K, std::vector<int>& result);  
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
    Node* getRoot() const { return root; }
    friend class Validator;
};

class Validator {
private:
    bool isBST(Node* node, int min, int max);
    int getNodeCount(Node* node);
    bool hasDuplicates(Node* node);

public:
    Validator();
    bool validateTree(Tree& tree);
    void printValidationResult(Tree& tree);
};

int chooseInputMethod();
template<typename T>
void fillStructure(T& structure, const std::string& structureName);