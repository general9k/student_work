//
// Created by general9k on 15.09.2023.
//

#include "Module.h"

void merge(vector<int> &arr, vector<int> &left, int leftSize, vector<int> &right, int rightSize,int &counter) {
    int i = 0, j = 0, k = 0;
    // Заполняем общий массив arr до того момента, пока один из массивов
    // не закончится
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
            counter++;
        } else {
            arr[k] = right[j];
            j++;
            counter++;
        }
        k++;
        counter++;
    }
    // Если в каком-то из массивов есть еще елементы - берем и засовываем их в общий (в конец)
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
        counter++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
        counter++;
    }
}

void mergeSort(vector<int> &arr, int size,int &counter) {
    // Если размер единичка, то сортировать не нужно
    if (size <= 1) return;
    // Определеяем половинки
    int mid = size / 2;
    vector<int> left(mid);
    vector<int> right(size - mid);
    // Заполняем левый и правый массивы
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
        counter++;
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
        counter++;
    }
    // Рекурсивный спуск
    mergeSort(left, mid, counter);
    mergeSort(right, size - mid, counter);
    // Сработает когда выше функции достигнут size <= 1 и выйдут из них
    merge(arr, left, mid, right, size - mid, counter);
}

vector<int> Module::sort_merge(vector<int> array,int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    mergeSort(arr_sort, array.size(), counter);
    return arr_sort;
}

void countingSort(vector<int> &arr, int start,int &counter) {
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    vector<int> count(range, 0);
    vector<int> output(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min]++;
        counter++;
    }

    // Преф суммы, которые показывают позиции чисел
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
        counter++;
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        // Кол-во данного числа - мин число показывает позицию в отсорт. списке
        output[count[arr[i] - min] - 1] = arr[i];
        // Если у нас в списке несколько одинаковых чисел
        // то оно будет класть слева(все остальные такие же) от первого
        count[arr[i] - min]--;
        counter++;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
        counter++;
    }
}

vector<int> Module::sort_count(vector<int> array, int start,int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    countingSort(arr_sort, start, counter);
    return arr_sort;
}

// Функция для создания кучи
void heapify(vector<int> &arr, int n, int i,int &counter) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest]){
        largest = left;
        counter++;
    }

    // Если правый потомок больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        counter++;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        counter++;
        // Рекурсивно применяем процедуру heapify к измененной позиции
        heapify(arr, n, largest, counter);
        counter++;

    }
}

// Основная функция пирамидальной сортировки
void heapSort(vector<int> &arr, int n,int &counter) {
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--){
        counter++;
        heapify(arr, n, i, counter);
    }

    // Извлечение элементов из кучи по одному
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);
        counter++;

        // Вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, counter);
    }
}

vector<int> Module::sort_piramide(vector<int> array,int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    heapSort(arr_sort, array.size(), counter);
    return arr_sort;
}