//
// Created by general9k on 15.09.2023.
//

#include "Module.h"

void merge(vector<int> &arr, vector<int> &left, int leftSize, vector<int> &right, int rightSize, int &counter) {
    int i = 0, j = 0, k = 0;
    // Заполняем общий массив arr до того момента, пока один из массивов
    // не закончится
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        counter ++;
        k++;
    }
    // Если в каком-то из массивов есть еще елементы - берем и засовываем их в общий (в конец)
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
        counter ++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
        counter++;
    }
}

void mergeSort(vector<int> &arr, int size, int &counter) {
    // Если размер единичка, то сортировать не нужно
    if (size <= 1) return;
    // Определеяем половинки
    int mid = size / 2;
    vector<int> left(mid);
    vector<int> right(size - mid);
    // Заполняем левый и правый массивы
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    // Рекурсивный спуск
    mergeSort(left, mid, counter);
    mergeSort(right, size - mid, counter);
    // Сработает когда выше функции достигнут size <= 1 и выйдут из них
    merge(arr, left, mid, right, size - mid, counter);
}

vector<int> Module::sort_merge(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    mergeSort(arr_sort, array.size(), counter);
    return arr_sort;
}

// Возвращает индекс опорного элемента
int partition(vector<int> &arr, int low, int high, int &counter) {
    int pivot = arr[high]; // опорный элемент
    int i = low - 1; // индекс меньшего элемента
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // меняем левый и правый элементы
            counter++;
        }
    }
    swap(arr[i + 1], arr[high]); // помещаем опорный элемент в правильную позицию
    counter++;
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high, int &counter) {
    if (low < high) {
        counter++;
        int pivotIndex = partition(arr, low, high, counter); // индекс опорного элемента
        counter++;
        quickSort(arr, low, pivotIndex - 1, counter); // левый
        counter++;
        quickSort(arr, pivotIndex + 1, high, counter); // правый
    }
}

vector<int> Module::sort_fast(vector<int> array, int &counter) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    quickSort(arr_sort, 0, arr_sort.size() - 1, counter);
    return arr_sort;
}


void countingSort(vector<int> &arr, int exp, int &counter) {
    int n = arr.size();
    vector<int> output(n); // массив отсортированных чисел
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        counter ++;
    }
    for (int i = 1; i < 10; i++) {// префиксная сумма
        count[i] += count[i - 1];
        counter ++;
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        counter++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i]; // копирование массива
        counter++;
    }
}

void radixSort(vector<int> &arr, int &counter) {
    // Получаем максимальный элемент
    int maxElement = *max_element(arr.begin(), arr.end()); // Определяем макс. кол-во разрядов
    for (int exp = 1; maxElement / exp > 0; exp *= 10) { // Работаем по разрядам
        counter++;
        countingSort(arr, exp, counter);
    }
}

vector<int> Module::sort_digit(vector<int> array, int &counter) {
    vector<int> arrPos; // массив положительных чисел
    vector<int> arrNeg; // массив отриц. чисел
    for (int elem: array) {
        if (elem >= 0) arrPos.push_back(elem);
        else arrNeg.push_back(abs(elem));
    }
    radixSort(arrPos, counter);
    radixSort(arrNeg, counter);
    std::reverse(arrNeg.begin(), arrNeg.end());
    for (int i = 0; i < arrNeg.size(); i++) {
        arrNeg[i] = -arrNeg[i];
    }
    arrNeg.insert(arrNeg.end(), arrPos.begin(), arrPos.end());
    return arrNeg;
}

