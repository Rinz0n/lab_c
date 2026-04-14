#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <locale>

class Node {
private:
    int data;
    Node* next;

public:
    Node();
    Node(int value);
    Node(const Node& other);
    ~Node();
    friend class Stack;
    friend class Queue;
    friend class List;
    friend int main();
};

class Stack {
private:
    Node* Head;

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    void push(int value);
    int pop();
    bool isEmpty() const;
    void show() const;
    void merge(Stack& other);
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

class Queue {
private:
    Node* Head;
    Node* LastNode;

public:
    Queue();
    Queue(const Queue& other);
    ~Queue();
    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    void show() const;
    void extractElements(int N);
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

class List {
private:
    Node* Head;
    Node* LastNode;

public:
    List();
    List(const List& other);
    ~List();
    void addToEnd(int value);
    void insertAfterEveryThird(int value);
    void show() const;
    Node* getPtrToElement(int position) const;
    List* copy() const;
    List* copySorted(int M) const;  
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

int chooseInputMethod();
template<typename T>
void fillStructure(T& structure, const std::string& structureName);