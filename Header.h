#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void clearInput();
int getIntInput(const std::string& prompt, int minVal = -1, int maxVal = -1);
void fillFromChoice(const std::string& prompt, const std::string& type);

class Time {
private:
    int seconds;
public:
    Time(int sec);
    std::string toString() const;
    void print() const;
    static void demoInput();
};

class House {
private:
    int floors;
public:
    House(int floors);
    std::string toString() const;
    void print() const;
    static void demoInput();
};

class Employee; 

class Department {
private:
    std::string name;
    Employee* chief;
    
public:
    Department(const std::string& name);
    void setChief(Employee* emp);
    std::string getName() const;
    Employee* getChief() const;
    void print() const;        
};

class Employee {
private:
    std::string name;
    Department* department;
public:
    Employee(const std::string& name, Department* dept);
    std::string toString() const;
    void print() const;
    std::string getName() const { return name; }  
    static void demoInput();
};

class EmployeeExtended;
class DepartmentExtended;

class DepartmentExtended {
private:
    std::string name;
    EmployeeExtended* chief;
    std::vector<EmployeeExtended*> employees;
public:
    DepartmentExtended(const std::string& name);
    void setChief(EmployeeExtended* emp);
    void addEmployee(EmployeeExtended* emp);
    std::string getName() const;
    EmployeeExtended* getChief() const;
    const std::vector<EmployeeExtended*>& getEmployees() const;
    void print() const;
};

class EmployeeExtended {
private:
    std::string name;
    DepartmentExtended* department;
public:
    EmployeeExtended(const std::string& name, DepartmentExtended* dept);
    std::string toString() const;
    void print() const;
    std::string getName() const { return name; }  // ← ДОБАВИТЬ ЭТУ СТРОКУ
    std::vector<EmployeeExtended*> getDepartmentEmployees() const;
    static void demoInput();
};

class ImmutableHouse {
private:
    const int floors;
public:
    explicit ImmutableHouse(int floors);
    std::string toString() const;
    void print() const;
    bool tryChangeFloors(int newFloors);
    static void demoInput();
};

class Gun {
private:
    int bullets;
public:
    Gun();
    explicit Gun(int bullets);
    void shoot();
    void print() const;
    int getBullets() const;
    static void demoInput();
};