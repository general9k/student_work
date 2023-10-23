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

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0 && abs(A[i + 1]) % 2 == 1)
            B.push_back(A[i]);
    }

    counter = 0;
    cout << "Сортировка cлиянием: \n";
    C = Module::sort_merge(B, counter);
    cout << counter << endl;
    reverse(C.begin(), C.end());
    for (int i: C) {
        cout << i << ' ';
    }

    counter = 0;
    cout << endl;
    cout << "Сортировка быстрая: \n";
    C = Module::sort_fast(B, counter);
    cout << counter << endl;
    reverse(C.begin(), C.end());
    for (int i: C) {
        cout << i << ' ';
    }

    counter = 0;
    cout << endl;
    cout << "Сортировка поразрядная: \n";
    C = Module::sort_digit(B, counter);
    cout << counter << endl;
    reverse(C.begin(), C.end());
    for (int i: C) {
        cout << i << ' ';
    }
    return 0;
}
