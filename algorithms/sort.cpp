#include <stdio.h>
#define CUTOFF 8

void swap(int* a, int* b) {
    if (a != b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
void Isort(int arr[], int start, int end) {
    int i, j;
    int temp = 0;
    for (i = 1; i <= end; i++) {
        temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; j--) {
            if (temp < arr[j - 1]) {
                arr[j] = arr[j - 1];
            }
        }
        arr[j] = temp;
    }
}
void Ssort(int arr[], int start, int end) {
    int i, j, min;
    for (i = 0; i < end; i++) {
        min = i;
        for (j = i + 1; j <= end; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&arr[i], &arr[min]);
        }
    }
}
int median3(int arr[], int low, int high) {
    int mid = (high + low) >> 1;
    if (arr[mid] > arr[high]) {
        swap(&arr[mid], &arr[high]);
    }
    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }
    if (arr[low] > arr[mid]) {
        swap(&arr[mid], &arr[low]);
    }
    // 后值置换
    swap(&arr[mid], &arr[high - 1]);
    return arr[mid];
}

void Qsort(int arr[], int low, int high) {
    if (high - low <= CUTOFF) {
        Isort(arr, low, high);
        return;
    }
    int pivot = median3(arr, low, high);
    // 遍历数组
    int i = low;
    int j = high - 1;
    while (true) {
        // 先找大值， 与后值置换对应
        while (arr[++i] < pivot) {
        }
        while (j > i && arr[--j] > pivot) {
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else
            break;
    }
    // 大值后置
    if (i < high - 1) {
        swap(&arr[i], &arr[high - 1]);
    }
    Qsort(arr, low, i - 1);
    Qsort(arr, i + 1, high);
}

void insertion_sort(int arr[], int n) { Isort(arr, 0, n - 1); }

void selection_sort(int arr[], int n) { Ssort(arr, 0, n - 1); }

void quick_sort(int arr[], int n) { Qsort(arr, 0, n - 1); }

int main() {
    int n, m;
    int* arr;
    printf("Please enter the number of integers.\n");
    scanf("%d", &n);
    arr = new int[n];
    printf("Please enter the integers.\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        arr[i] = m;
    }
    quick_sort(arr, n);
    printf("Here is the result of quick sort.\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
