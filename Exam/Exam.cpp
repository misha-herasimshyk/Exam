#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main() {
    int m;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    
    cout << "Введiть розмiр масиву: ";
    cin >> m;

    if (m <= 0) {
        cout << "Розмiр масиву повинен бути бiльше 0." << endl;
        return 1; 
    }

    int* A = new int[m]; 

   
    cout << "Введiть елементи масиву:\n";
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
        if (cin.fail()) {
            cout << "Введено некоректні дані." << endl;
            delete[] A; 
            return 1; 
        }
    }

    sort(A, A + m);
    int abobus = unique(A, A + m) - A;

    cout << "Кiлькiсть рiзних чисел в масивi: " << abobus << endl;

    
    partition(A, A + m, [](int x) { return x >= 0; });

   
    cout << "Вiдсортований масив:\n";
    for (int i = 0; i < m; ++i) {
        cout << A[i] << " ";
    }

    delete[] A; 

    return 0;
}

