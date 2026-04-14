#include "Header.h"
#include "Header.cpp"

int main(){
    using namespace std;
    setlocale(LC_ALL, "RU");
    int number, cnt;
    cout << "Введите номер задачи:" << endl;
    cin >> number;
    switch (number) {
    case 1:{
        addinfile(cnt);
        distrinfile(cnt);
        print();
        break;
    }
    case 2:{
        addinfile(cnt);
        deletenegativenumbers(cnt);
        break;
    }
    case 3:{
        int n;
        string s;
        cout << "Введите строку S:" << endl;
        cin >> s;
        cout << "Введите целое число N(>0):" << endl;
        cin >> n;
        createfile(n);
        break;
    }
    case 4:{
        string s;
        int i = 0;
        cout << "Введите выражение:" << endl;
        cin >> s;
        cout << "Значение выражения: " << expr(s,i);
        break;
    }
    }
    return 0;
}