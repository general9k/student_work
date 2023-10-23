//
// Created by general9k on 15.09.2023.
//

#include "Module.h"

vector<int> Module::sort_choice(vector<int> array, int &counter_assignment, int &counter_if) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    for (int i = 0; i < arr_sort.size(); i++) {
        int minIndex = i;
        counter_assignment++;
        for (int j = i + 1; j < arr_sort.size(); j++) {
            counter_if++;
            if (arr_sort[j] < arr_sort[minIndex]) {
                minIndex = j;
                counter_assignment++;
            }

        }
        int temp = arr_sort[minIndex];
        arr_sort[minIndex] = arr_sort[i];
        arr_sort[i] = temp;
        counter_assignment += 3;
    }
    return arr_sort;
}

vector<int> Module::sort_bubble(vector<int> array, int &counter_assignment, int &counter_if) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    for (int i = 0; i < arr_sort.size(); i++) {
        for (int j = i + 1; j < arr_sort.size(); j++) {
            counter_if++;
            if (arr_sort[j] < arr_sort[i]) {
                int temp = arr_sort[j];
                arr_sort[j] = arr_sort[i];
                arr_sort[i] = temp;
                counter_assignment += 3;
            }
        }
    }
    return arr_sort;
}

vector<int> Module::sort_insert(vector<int> array, int &counter_assignment, int &counter_if) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    int n = arr_sort.size();
    counter_assignment += 1;
    for (int i = 1; i < n; i++) {
        int key = arr_sort[i];
        int j = i - 1;
        counter_assignment += 2;
        while (j >= 0 && arr_sort[j] > key) {
            counter_if += 1;
            arr_sort[j + 1] = arr_sort[j];
            j--;
            counter_assignment += 2;
        }
        arr_sort[j + 1] = key;
        counter_assignment ++;
    }
    return arr_sort;
}
