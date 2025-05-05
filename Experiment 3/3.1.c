// Write a program to sort (Ascending order) the given elements using merge sort technique.

// MergeSortMain.C
#include <stdio.h>
#include "MergeSortFunctions.c"
void main() {
	int arr[15], i, n;
	printf("Enter array size : ");
	scanf("%d", &n);
	printf("Enter %d elements : ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Before sorting the elements are : ");
	display(arr, n);
	splitAndMerge(arr, 0, n - 1);
	printf("After sorting the elements are : ");
	display(arr, n);
}

// MergeSortFunctions.c
void display(int arr[15], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int arr[15], int low, int mid, int high) {
	int i = low, h = low, j = mid + 1, k, temp[15];
	while (h <= mid && j <= high) {
		if(arr[h] <= arr[j]) {
			temp[i] = arr[h];
			h++;
		} else {
			temp[i] = arr[j];
			j++;
		}
		i++;
	}

	if (h <= mid) {
		for (k = h; k <= mid; k++) {
			temp[i] = arr[k];
			i++;
		}
	} else {
		for (k = j; k <= high; k++) {
			temp[i] = arr[k];
			i++;
		}
	}

	for (k = 0; k <= high; k++) {
		arr[k] = temp[k];
	}
}

void splitAndMerge(int arr[15], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		splitAndMerge(arr, low, mid);
		splitAndMerge(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
