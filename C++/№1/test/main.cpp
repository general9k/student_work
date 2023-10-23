#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void merge(vector<int> &arr, vector<int> &left, int leftSize, vector<int> &right, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int size) {
    if (size <= 1) return;
    int mid = size / 2;
    vector<int> left(mid);
    vector<int> right(size - mid);

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

vector<int> sort_merge(vector<int> array) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    mergeSort(arr_sort, array.size());
    return arr_sort;
}

//возвращает индекс опорного элемента
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; //опорный элемент
    int i = low - 1; //
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);//меняем левый и правый элементы
        }
    }
    swap(arr[i + 1], arr[high]);//помещаем опорный элемент в правильную позицию
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); //индекс опорного элемента
        quickSort(arr, low, pivotIndex - 1);//левый
        quickSort(arr, pivotIndex + 1, high);//правый
    }
}

vector<int> sort_fast(vector<int> array) {
    vector<int> arr_sort(array.size());
    copy(array.begin(), array.end(), arr_sort.begin());
    quickSort(arr_sort, 0, arr_sort.size()-1);
    return arr_sort;
}

int main() {
    vector<int> A;
    vector<int> B;
    vector<int> C;
    srand(time(NULL));
    int end = 10000, start = -10000;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp = rand() % (end - start + 1) - end;
        A.push_back(temp);
    }

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0 && A[i + 1] % 2 == 1) {
            B.push_back(A[i]);
        }
    }

    cout << "Сортировка слиянием:\n";

    C = sort_merge(B);
    reverse(C.begin(), C.end());
    for (int i: C) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Быстрая сортировка:\n";

    C = sort_fast(B);
    reverse(C.begin(), C.end());
    for (int i: C) {
        cout << i << " ";
    }

    cout << endl;

}