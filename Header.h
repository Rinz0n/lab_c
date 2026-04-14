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

using namespace std;

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

void task7(vector<int>& V, deque<int>& D, list<int>& L);
void task13(vector<int>& V, deque<int>& D);
void task21(vector<int>& V);
void task17(const string& name, const string& symbols);