#include <iostream>
#include <vector>
#include "sort_algorithms.h"
#include "benchmark.h"

// Wrapper para MergeSort
void mergeSortWrapper(int arr[], int size) {
	mergeSort(arr, 0, size - 1);
}
double getAverageTime(std::function<void(int[], int)> sortFunction, int size, int iterations) {
	std::vector<int> arr;
	double totalTime = 0;
	for (int i = 0; i < iterations; ++i) {
		generateAverageCase(arr, size);  // Generar nuevos datos cada vez
		totalTime += measureExecutionTime(sortFunction, arr.data(), size);
	}
	return totalTime / iterations;
}
void runBenchmark(const std::string& algorithmName, std::function<void(int[], int)> sortFunction, int size) {
	std::vector<int> arr;
	
	// Mejor caso
	generateBestCase(arr, size);
	double bestCaseTime = measureExecutionTime(sortFunction, arr.data(), size);
	std::cout << "Mejor caso (" << algorithmName << "): " << bestCaseTime << " segundos" << std::endl;
	
	// Peor caso
	generateWorstCase(arr, size);
	double worstCaseTime = measureExecutionTime(sortFunction, arr.data(), size);
	std::cout << "Peor caso (" << algorithmName << "): " << worstCaseTime << " segundos" << std::endl;
	
	// Caso promedio
	generateAverageCase(arr, size);
	double avgCaseTime = measureExecutionTime(sortFunction, arr.data(), size);
	std::cout << "Caso promedio (" << algorithmName << "): " << avgCaseTime << " segundos" << std::endl;
}

int main() {
	int size = 10000; 
	
	// Benchmark para BubbleSort
	std::cout << "---- Benchmark para BubbleSort ----" << std::endl;
	runBenchmark("BubbleSort", bubbleSort, size);
	
	// Benchmark para SelectionSort
	std::cout << "---- Benchmark para SelectionSort ----" << std::endl;
	runBenchmark("SelectionSort", selectionSort, size);
	
	// Benchmark para MergeSort
	std::cout << "---- Benchmark para MergeSort ----" << std::endl;
	runBenchmark("MergeSort", mergeSortWrapper, size);
	
	return 0;
}
