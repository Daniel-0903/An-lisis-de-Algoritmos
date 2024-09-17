#include "benchmark_structures.h"
#include <chrono>

double measureInsertTime(LinkedList& list, int value) {
	auto start = std::chrono::high_resolution_clock::now();
	list.insert(value);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}

double measureSearchTime(LinkedList& list, int value) {
	auto start = std::chrono::high_resolution_clock::now();
	list.search(value);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}

double measureRemoveTime(LinkedList& list, int value) {
	auto start = std::chrono::high_resolution_clock::now();
	list.remove(value);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}

double measureInsertTime(BinarySearchTree& bst, int value) {
	auto start = std::chrono::high_resolution_clock::now();
	bst.insert(value);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}

double measureSearchTime(BinarySearchTree& bst, int value) {
	auto start = std::chrono::high_resolution_clock::now();
	bst.search(value);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}

double measureRemoveTime(BinarySearchTree& bst, int value) {
	auto start = std::chrono::high_resolution_clock::now();
	bst.remove(value);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	return duration.count();
}
