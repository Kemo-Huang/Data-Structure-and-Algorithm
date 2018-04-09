#pragma warning(disable:4996)
#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void insertion_sort(int arr[], int n) {
	int i, j;
	int temp = 0;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i; j > 0 && temp < arr[j - 1]; j--) {
			if (temp < arr[j - 1]) {
				arr[j] = arr[j - 1];
			}
		}
		arr[j] = temp;
	}
}
void selection_sort(int arr[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
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
	if (arr[mid] > arr[high])
	{
		swap(&arr[mid], &arr[high]);
	}
	if (arr[low] > arr[high])
	{
		swap(&arr[low], &arr[high]);
	}
	if (arr[low] > arr[mid])
	{
		swap(&arr[mid], &arr[low]);
	}
	return arr[mid];
}

void Qsort(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	if (high - low < 10) {
		insertion_sort(arr, high - low + 1);
		return;
	}
	int i, j, pivot;
	i = low;
	j = high;
	pivot = median3(arr, low, high);
	while (true) {
		while (arr[++i] < pivot) {}
		while (arr[--j] > pivot) {}
		if (i < j) {
			swap(&arr[i], &arr[j]);
		}
		else {
			break;
		}
	}
	Qsort(arr, low, i - 1);
	Qsort(arr, i + 1, high);
}

void quick_sort(int arr[], int n) {
	Qsort(arr, 0, n - 1);
}

int main() {
	int n, m;
	int *arr_i, *arr_s, *arr_q;
	printf("Please enter the number of integers.\n");
	scanf("%d", &n);
	arr_i = new int[n];
	arr_q = new int[n];
	arr_s = new int[n];
	printf("Please enter the integers.\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		arr_s[i] = arr_i[i] = arr_q[i] = m;
	}
	//insertion_sort(arr_i, n);
	//printf("Here is the result of insertion sort.\n");
	//for (int i = 0; i < n; i++)
	//	printf("%d ", arr_i[i]);
	//printf("\n");
	//selection_sort(arr_s, n);
	//printf("Here is the result of selection sort.\n");
	//for (int i = 0; i < n; i++)
	//	printf("%d ", arr_s[i]);
	//printf("\n");
	quick_sort(arr_q, n);
	printf("Here is the result of quick sort.\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr_q[i]);
	return 0;
}

