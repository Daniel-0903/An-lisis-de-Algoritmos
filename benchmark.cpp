#include "benchmark.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

void generateBestCase(std::vector<int>& arr, int size) {
	arr.clear();
	for (int i = 0; i < size; i++) {
		arr.push_back(i);
	}
}

void generateWorstCase(std::vector<int>& arr, int size) {
	arr.clear();
	for (int i = size; i > 0; i--) {
		arr.push_back(i);
	}
}

void generateAverageCase(std::vector<int>& arr, int size) {
	arr.clear();
	std::srand(std::time(0));
	for (int i = 0; i < size; i++) {
		arr.push_back(std::rand() % 1000);
	}
}

double measureExecutionTime(std::function<void(int[], int)> sortFunction, int arr[], int size) {
	auto start = std::chrono::high_resolution_clock::now();
	
	sortFunction(arr, size);
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	
	return duration.count();
}

