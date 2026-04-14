#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iterator>
#include <limits>
#include <sstream>  
#include <functional>
#include <numeric>

using namespace std;

struct SortbyLength {
    bool operator()(const string& a, const string& b) const {
        return a.length() < b.length();
    }
};

struct MakePairString {
    string operator()(const string& right, const string& left) const {
        if (left.empty() || right.empty()) return "";
        return string(1, left.front()) + string(1, right.back());
    }
};

template<typename Container>
void printContainer(const Container& cont);

template<typename Container>
void fillFromKeyboard(Container& cont, const string& name);

template<typename Container>
void fillFromFile(Container& cont, const string& name);

template<typename Container>
void fillRandom(Container& cont, const string& name);

template<typename Container>
void fillContainer(Container& cont, const string& containerName);

template<typename Container>
void fillContainerString(Container& cont, const string& containerName);

void task1(vector<int>& V);
void task21(list<int>& L1, list<int>& L2, int K);
void task45(deque<string>& D);
void task61(list<string>& L);