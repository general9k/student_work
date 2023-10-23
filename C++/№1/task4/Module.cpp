//
// Created by general9k on 15.09.2023.
//

#include "Module.h"

vector<int> Module::sort_bubble(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    for (int i = 0; i < arr_sort.size(); i++) {
        for (int j = i + 1; j < arr_sort.size(); j++) {
            if (arr_sort[j] < arr_sort[i]) {
                int temp = arr_sort[j];
                arr_sort[j] = arr_sort[i];
                arr_sort[i] = temp;
                counter ++;
            }
        }
    }
    return arr_sort;
}

void shellSort(vector<int> &arr, int n, int &counter) {
    // Начинаем с большого шага, затем постепенно уменьшаем шаг
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Выполняем сортировку вставками для каждого шага
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
                counter++;
            }
            arr[j] = temp;
            counter++;
        }
        counter++;
    }
}

vector<int> Module::sort_SHELL(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    shellSort(arr_sort, arr_sort.size(),counter);
    return arr_sort;
}

void cocktailSort(vector<int> &arr, int &counter) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;
    while (swapped) {
        swapped = false;
        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
                counter++;
            }
        }
        if (!swapped) {
            break;
        }
        counter++;
        swapped = false;
        --end;
        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
                counter++;
            }
        }
        ++start;
    }
}

vector<int> Module::sort_shaker(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    cocktailSort(arr_sort,counter);
    return arr_sort;
}