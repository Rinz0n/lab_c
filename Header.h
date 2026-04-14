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
#include <set>
#include <map>

template<typename Container>
void printContainer(const Container& cont);

template<typename Container>
void fillFromKeyboard(Container& cont, const std::string& name);

template<typename Container>
void fillFromFile(Container& cont, const std::string& name);

template<typename Container>
void fillRandom(Container& cont, const std::string& name);

template<typename Container>
void fillContainer(Container& cont, const std::string& containerName);

template<typename Container>
void fillContainerString(Container& cont, const std::string& containerName);

void task3(std::vector<int>& V0, const std::vector<std::vector<int>>& vectors);

void task15(std::vector<int>& V);

void task22(std::vector<std::string>& V);