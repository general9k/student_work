//
// Created by general9k on 15.09.2023.
//

#include "Module.h"

vector<int> Module::sort_insert(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    int n = arr_sort.size();
    for (int i = 1; i < n; ++i) {
        int key = arr_sort[i];
        int j = i - 1;
        counter++;
        while (j >= 0 && arr_sort[j] > key) {
            arr_sort[j + 1] = arr_sort[j];
            j--;
            counter++;
            counter++;
        }
        arr_sort[j + 1] = key;
    }
    return arr_sort;
}

vector<int> Module::sort_choice(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    for (int i = 0; i < arr_sort.size(); i++) {
        int minIndex = i;
        counter++;
        for (int j = i + 1; j < arr_sort.size(); j++) {
            if (arr_sort[j] < arr_sort[minIndex]) {
                minIndex = j;
            }
            counter++;
        }
        int temp = arr_sort[minIndex];
        arr_sort[minIndex] = arr_sort[i];
        arr_sort[i] = temp;
    }
    return arr_sort;
}

// Функция для обмена значениями
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Функция для создания кучи
void heapify(vector<int> &arr, int n, int i, int &counter) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest]){
        largest = left;
        counter++;
    }

    // Если правый потомок больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] > arr[largest]){
        largest = right;
        counter++;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        counter++;

        // Рекурсивно применяем процедуру heapify к измененной позиции
        heapify(arr, n, largest, counter);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(vector<int> &arr, int n, int &counter) {
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i, counter);
        counter++;
    }

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);
        counter++;

        // Вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, counter);
    }
}

vector<int> Module::sort_piramide(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    heapSort(arr_sort, array.size(), counter);
    return arr_sort;
}

