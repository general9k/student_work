//
// Created by general9k on 15.09.2023.
//

#include "Module.h"


// Функция для обмена значениями
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для создания кучи
void heapify(vector<int> &arr, int n, int i, int &count_if, int &count_as) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок
    count_as += 3;

    // Если левый потомок больше корня
    count_if++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        count_as++;
    }

    // Если правый потомок больше, чем самый большой элемент на данный момент
    count_if++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        count_as++;
    }

    // Если самый большой элемент не корень
    count_if++;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        count_as++;

        // Рекурсивно применяем процедуру heapify к измененной позиции
        heapify(arr, n, largest, count_if, count_as);
    }
}

// Основная функция пирамидальной сортировки
void heapSort(vector<int> &arr, int n, int &count_if, int &count_as) {
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        count_if++;
        heapify(arr, n, i, count_if, count_as);
    }

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        count_if++;
        swap(&arr[0], &arr[i]);
        count_as += 3;

        // Вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, count_if, count_as);
    }
}

vector<int> Module::sort_piramide(vector<int> array, int &count_if, int &count_as) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    heapSort(arr_sort, array.size(), count_if, count_as);
    return arr_sort;
}

void evenOddSort(vector<int> &arr, int n, int &count_if, int &count_as) {
    int temp;
    bool isSorted = false;
    count_as++;
    while (!isSorted) {
        count_if++;
        isSorted = true;
        count_as++;
        for (int i = 1; i < n - 1; i += 2) {
            count_if++;
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = false;
                count_as += 4;
            }
        }
        for (int i = 0; i < n - 1; i += 2) {
            count_if++;
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = false;
                count_as += 4;
            }
        }
    }
}

vector<int> Module::sort_even_odd(vector<int> array, int &count_if, int &count_as) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    evenOddSort(arr_sort, array.size(), count_if, count_as);
    return arr_sort;
}
