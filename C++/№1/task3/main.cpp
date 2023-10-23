#include <iostream>
#include <vector>
#include "Module.h"

int main() {
    vector<int> A;
    vector<int> B;
    vector<int> C;
    srand(time(NULL));
    int end = 10000, start = -10000;
    int n;
    int counter;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = rand() % (end - start + 1) - end;
        A.push_back(temp);
    }
    // Ищем индекс макс элемента
    int maxElem = A[0], indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] > maxElem) {
            maxElem = A[i];
            indexMax = i;
        }
    }

    for (int i = indexMax + 1; i < n; i++) {
        if (i % 2 == 1) B.push_back(A[i]);
    }

    counter = 0;
    cout << "Сортировка слиянием: \n";
    C = Module::sort_merge(B,counter);
    cout << counter << endl;
    for (int elem: C) {
        cout << elem << ' ';
    }

    counter = 0;
    cout << endl << "Сортировка подсчетом: \n";
    C = Module::sort_count(B, start,counter);
    cout << counter << endl;
    for (int elem: C) {
        cout << elem << ' ';
    }

    counter = 0;
    cout << endl << "Сортировка пирамидальная: \n";
    C = Module::sort_piramide(B,counter);
    cout << counter << endl;
    for (int elem: C) {
        cout << elem << ' ';
    }

    return 0;
}
