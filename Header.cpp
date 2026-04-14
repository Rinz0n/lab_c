#include "Header.h"

//  Добавляет числа в файл
void addinfile(int &cnt){
 using namespace std;
 setlocale(LC_ALL, "RU");
 fstream mainfile;
 float num;
 mainfile.open("file.dat", ios::out | ios::binary);
 cout << "Сколько чисел хотите ввести:" << endl;
 cin >> cnt;
 cout << "Введите число:" << endl;
 for (int i = 0; i < cnt; i++) {
  cin >> num;
  mainfile.write((char*)&num, sizeof(num));
 }
 mainfile.close();
}

void print(){
    using namespace std;
    fstream file1, file2, mainfile;
    file1.open("file1.dat", ios::in | ios::binary);
    file2.open("file2.dat", ios::in | ios::binary);
    mainfile.open("file.dat", ios::in | ios::binary);
    float num;
    cout << "Содержимое файла file1.dat:" << endl;
    while (file1.read((char*)&num, sizeof(num))){
        cout << num << endl;
    }
    cout << "Содержимое файла file2.dat:" << endl;
    while (file2.read((char*)&num, sizeof(num))){
        cout << num << endl;
    }
    cout << "Содержимое файла file.dat:" << endl;
    while (mainfile.read((char*)&num, sizeof(num))){
        cout << num << endl;
    }
    mainfile.close();
    file1.close();
    file2.close();
}

// Разделяет числа в файлы
void distrinfile(int &cnt){
 using namespace std;
 fstream mainfile, file1, file2;
 mainfile.open("file.dat", ios::in | ios::binary);
 file1.open("file1.dat", ios::out | ios::in | ios::binary);
 file2.open("file2.dat", ios::out | ios::in | ios::binary);
 float num;
 int c = 1;
 while (c <= cnt) {
  mainfile.read((char*)&num, sizeof(num));
  if (c % 2 != 0) {
   file1.write((char*)&num, sizeof(num));
  }
  else {
   file2.write((char*)&num, sizeof(num));
  }
  c++;
 }
 cout << "Числа добавлены в файлы file1 и file2!" << endl;
 mainfile.close();
 file1.close();
 file2.close();
}

// Удаляет из файла все отрицательные числа
void deletenegativenumbers(int &cnt){
 using namespace std;
 fstream mainfile;
 mainfile.open("file.dat", ios::in | ios::binary);
 vector<float> vec;
 float num;
 while (mainfile.read((char*)&num, sizeof(num))) {
  if (num >= 0) {
   vec.push_back(num);
  }
 }
 mainfile.close();
 mainfile.open("file.dat", ios::out | ios::binary | ios::trunc);
 for (int i = 0; i < vec.size(); i++) {
  mainfile.write((char*)&vec[i], sizeof(vec[i]));
 }
 cout << "Из файла были удалены все отрицательные числа!" << endl;
 mainfile.close();
 mainfile.open("file.dat", ios::in | ios::binary);
 cout << "Содержимое файла file.dat:" << endl;
 while (mainfile.read((char*)&num, sizeof(num))) {
    cout << num << endl;
 }
 mainfile.close();
}

// Функция для 4 задания
int expr(std::string s, int &i) {
 using namespace std;
 if (isdigit(s[i])) return s[i++] - '0';
 char op = s[i++];
 i++; 
 int a = expr(s,i);
 i++; 
 int b = expr(s,i);
 i++; 
 return op == 'M' ? max(a, b) : min(a, b);
}

void createfile(int n){
    using namespace std;
    string name;
    for (int i = 1; i<= n; i++){
        name = 'S' + to_string(i);
        fstream name;
        name.open('S' + to_string(i), ios::out | ios::binary);

    }
}
