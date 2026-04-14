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
    Node* prev;  

public:
    Node();
    Node(int value);
    Node(int value, Node* n, Node* p);
    Node(const Node& other);
    ~Node();
    friend class RingList;
    friend class DoubleList1;
    friend class DoubleList2;
    friend class ListWithBarrier;
    friend class DoubleList3;
    friend int main();
};

class RingList {
private:
    Node* first;

public:
    RingList();
    RingList(const RingList& other);
    ~RingList();
    void add(int value);
    bool isEmpty() const;
    void show() const;
    void task1(const std::string& filename);
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

class DoubleList1 {
private:
    Node* first;

public:
    DoubleList1();
    DoubleList1(const DoubleList1& other);
    ~DoubleList1();
    void add(int value);
    bool isEmpty() const;
    void show() const;
    void task2();
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

class DoubleList2 {
private:
    Node* first;

public:
    DoubleList2();
    DoubleList2(const DoubleList2& other);
    ~DoubleList2();
    void add(int value);
    bool isEmpty() const;
    void show() const;
    void task3(const std::string& filename);
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

class TListB {
    public:
        Node* barrier;  
        Node* current;  
};

class ListWithBarrier {
private:
    TListB list;

public:
    ListWithBarrier();
    ListWithBarrier(const ListWithBarrier& other);
    ~ListWithBarrier();
    void add(int value);
    void show() const;
    void LBToFirst();
    void LBToNext();
    void LBSetData(int D);
    bool IsBarrier();
    void task4(int& count, Node*& newCurrent);
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

class DoubleList3 {
private:
    Node* first;

public:
    DoubleList3();
    DoubleList3(const DoubleList3& other);
    ~DoubleList3();
    void add(int value);
    bool isEmpty() const;
    void show() const;
    void task5();
    void createFromInput();
    void createFromFile(const std::string& filename);
    void createRandom(int count);
};

int chooseInputMethod();
template<typename T>
void fillStructure(T& structure, const std::string& structureName);