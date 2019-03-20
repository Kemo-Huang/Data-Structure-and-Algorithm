#pragma warning(disable:4996)
#include<stdio.h>

int data[2000000];
int temp[2000000];

long long Merge(int startIndex, int midIndex, int endIndex)
{
	if (data[midIndex] > data[midIndex + 1]) {
		int i = startIndex, j = midIndex + 1, k = startIndex;
		long long r = 0;
		while (i != midIndex + 1 && j != endIndex + 1)
		{
			if (data[i] > data[j]) {
				temp[k++] = data[j++];
				r += (midIndex - i + 1);
			}
			else
				temp[k++] = data[i++];
		}
		while (i != midIndex + 1)
			temp[k++] = data[i++];
		while (j != endIndex + 1)
			temp[k++] = data[j++];
		for (i = startIndex; i <= endIndex; i++)
			data[i] = temp[i];
		return r;
	}
	else {
		return 0;
	}
}

long long MergeSort(int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;
		return MergeSort(startIndex, midIndex) +
			MergeSort(midIndex + 1, endIndex) +
			Merge(startIndex, midIndex, endIndex);
	}
	else
		return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &(data[i]));
	}
	long long result = MergeSort(0, n - 1) % 1000000007;
	printf("%lld", result);
}
