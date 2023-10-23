#include <iostream>
#include <vector>
#include "Module.h"

using namespace std;


int main() {
    vector<int> A;
    vector<int> B;
    vector<int> C;
    srand(time(NULL));
    int end = 10000, start = -10000;
    int n;
    int counter_assignment;
    int counter_if;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = rand() % (end - start + 1) - end;
        A.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && A[i] % 2 == 0) {
            B.push_back(A[i]);
        }
    }

    counter_assignment = 0;
    counter_if = 0;
    cout << "Сортировка выбора: \n";
    C = Module::sort_choice(B,counter_assignment, counter_if);
    cout << counter_assignment << ' ' << counter_if << endl;
    reverse(C.begin(),C.end());
    for (int i: C) {
        cout << i << ' ';
    }

    counter_assignment = 0;
    counter_if = 0;
    cout << endl;
    cout << "Сортировка пузырек: \n";
    C = Module::sort_bubble(B,counter_assignment, counter_if);
    cout << counter_assignment << ' ' << counter_if << endl;
    reverse(C.begin(),C.end());
    for (int i: C) {
        cout << i << ' ';
    }

    counter_assignment = 0;
    counter_if = 0;
    cout << endl;
    cout << "Сортировка вставками: \n";
    C = Module::sort_insert(B,counter_assignment, counter_if);
    cout << counter_assignment << ' ' << counter_if << endl;
    reverse(C.begin(),C.end());
    for (int i: C) {
        cout << i << ' ';
    }

    return 0;
}

