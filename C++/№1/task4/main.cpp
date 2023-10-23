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

    int minB = *min_element(B.begin(), B.end());
    int maxA = *max_element(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        if (A[i] > minB) C.push_back(A[i]);
        if (B[i] > maxA) C.push_back(B[i]);
    }

    counter = 0;
    cout << "Сортировка пузырек массива A: \n";
    D = Module::sort_bubble(A, counter);
    cout << counter << endl;
    for (int i: D) {
        cout << i << ' ';
    }

    counter = 0;
    cout << endl << "Сортировка Шелла массива B: \n";
    D = Module::sort_SHELL(B, counter);
    cout << counter << endl;
    for (int i: D) {
        cout << i << ' ';
    }

    counter = 0;
    cout << endl << "Сортировка шейкер массива C: \n";
    D = Module::sort_shaker(C, counter);
    cout << counter << endl;
    for (int i: D) {
        cout << i << ' ';
    }

    return 0;
}
