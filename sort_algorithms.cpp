#include "sort_algorithms.h"
#include <algorithm>

// Bubble Sort
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Selection Sort
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		std::swap(arr[i], arr[minIdx]);
	}
}


