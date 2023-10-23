#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "Module.h"

using namespace std;

int main() {
    vector<int> A;
    vector<int> B;
    srand(time(NULL));
    int end = 10000, start = -10000;
    int n;
    int count_if, count_as;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = rand() % (end - start + 1) - end;
        A.push_back(temp);
    }

    count_if = 0;
    count_as = 0;
    cout << "Пирамидальная сортировка массива: \n";
    clock_t time1 = clock();
    B = Module::sort_piramide(A, count_if, count_as);
    clock_t time2 = clock();
    double time_taken = double(time2 - time1) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6) << time_taken << " секунд" << endl;
    for (int i: B) {
        cout << i << ' ';
    }
    cout << endl << "Количество сравнений: " << count_if << endl << "Количество присвоений: " << count_as << endl
         << endl;

    count_if = 0;
    count_as = 0;
    cout << "Четная - нечетная сортировка массива: \n";
    clock_t time3 = clock();
    B = Module::sort_even_odd(A, count_if, count_as);
    clock_t time4 = clock();
    time_taken = double(time4 - time3) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6) << time_taken << " секунд" << endl;
    for (int i: B) {
        cout << i << ' ';
    }
    cout << endl << "Количество сравнений: " << count_if << endl << "Количество присвоений: " << count_as << endl;


    return 0;
}
