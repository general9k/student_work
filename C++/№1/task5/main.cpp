#include <iostream>
#include "Module.h"

int main() {
    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;
    srand(time(NULL));
    int end = 10000, start = -10000;
    int n;
    int counter;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = rand() % (end - start + 1) - end;
        A.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp = rand() % (end - start + 1) - end;
        B.push_back(temp);
    }

    // Переносим четные и нечетные элементы
    for (int i = 0; i < n; i++) {
        if (abs(A[i]) % 2 == 0) C.push_back(A[i]);
        if (abs(B[i]) % 2 == 1) C.push_back(B[i]);
    }

    counter = 0;
    cout << "Сортировка вставками массива А: \n";
    D = Module::sort_insert(A,counter);
    cout << counter << endl;
    reverse(D.begin(), D.end());
    for (int i: D) {
        cout << i << ' ';
    }

    counter = 0;
    cout << endl << "Сортировка выбором массива B: \n";
    D = Module::sort_choice(B,counter);
    cout << counter << endl;
    reverse(D.begin(), D.end());
    for (int i: D) {
        cout << i << ' ';
    }

    counter = 0;
    cout << endl << "Сортировка пирамидальная массива C: \n";
    D = Module::sort_piramide(C,counter);
    cout << counter << endl;
    reverse(D.begin(), D.end());
    for (int i: D) {
        cout << i << ' ';
    }
    return 0;
}
