#include<stdio.h>

int binaryWhile(int arr[], int left, int right, int key) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (key < arr[mid]) 
			right = mid - 1;
		else if (key > arr[mid]) 
			left = mid + 1;
		else 
			return mid;
	}
	return -1;
}

int binaryRecur(int arr[], int left, int right, int key) {
	if (left > right) 
		return -1;
	int mid = left + (right - left) / 2;
	if (key < arr[mid])
		return binaryRecur(arr, left, mid - 1, key);
	if (key > arr[mid]) 
		return binaryRecur(arr, mid + 1, right, key);
	else
		return mid;
}

int main() {
	int arr[] = { 1,2,3,4,5 };
	printf("%d", binaryRecur(arr, 0, 4, 2));
	return 0;
}