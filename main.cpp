#include <iostream>
#include <vector>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "graph_area.h"
#include "sort_algorithms.h"
#include "benchmark.h"
#include "linked_list.h"
#include "binary_search_tree.h"
#include "benchmark_structures.h"
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
void runBenchmarkStructures() {
	LinkedList list;
	BinarySearchTree bst;
	
	int size = 100000;  // Tamaño de datos para las estructuras de datos
	
	// Benchmark para LinkedList
	std::cout << "---- Benchmark para LinkedList ----" << std::endl;
	double timeInsertList = 0, timeSearchList = 0, timeRemoveList = 0;
	for (int i = 0; i < size; ++i) {
		timeInsertList += measureInsertTime(list, i);
		timeSearchList += measureSearchTime(list, i);
		timeRemoveList += measureRemoveTime(list, i);
	}
	std::cout << "Tiempo promedio de insercion (LinkedList): " << timeInsertList / size << " segundos" << std::endl;
	std::cout << "Tiempo promedio de busqueda (LinkedList): " << timeSearchList / size << " segundos" << std::endl;
	std::cout << "Tiempo promedio de eliminacion (LinkedList): " << timeRemoveList / size << " segundos" << std::endl;
	
	// Benchmark para BinarySearchTree
	std::cout << "---- Benchmark para BinarySearchTree ----" << std::endl;
	double timeInsertBST = 0, timeSearchBST = 0, timeRemoveBST = 0;
	for (int i = 0; i < size; ++i) {
		timeInsertBST += measureInsertTime(bst, i);
		timeSearchBST += measureSearchTime(bst, i);
		timeRemoveBST += measureRemoveTime(bst, i);
	}
	std::cout << "Tiempo promedio de insercion (BinarySearchTree): " << timeInsertBST / size << " segundos" << std::endl;
	std::cout << "Tiempo promedio de busqueda (BinarySearchTree): " << timeSearchBST / size << " segundos" << std::endl;
	std::cout << "Tiempo promedio de eliminacion (BinarySearchTree): " << timeRemoveBST / size << " segundos" << std::endl;
}
int main() {
	int size = 10000; 
	int iterations = 10;  // Número de iteraciones para calcular tiempos promedio
	
	// Benchmark para BubbleSort
	std::cout << "---- Benchmark para BubbleSort ----" << std::endl;
	runBenchmark("BubbleSort", bubbleSort, size);
	
	// Benchmark para SelectionSort
	std::cout << "---- Benchmark para SelectionSort ----" << std::endl;
	runBenchmark("SelectionSort", selectionSort, size);
	
	// Benchmark para MergeSort
	std::cout << "---- Benchmark para MergeSort ----" << std::endl;
	runBenchmark("MergeSort", mergeSortWrapper, size);
	runBenchmarkStructures();
	
	// Inicializar la aplicación GTK
	auto app = Gtk::Application::create(argc, argv, "com.example.graph");
	
	// Crear ventanas para cada gráfico
	Gtk::Window bubbleWindow;
	bubbleWindow.set_default_size(600, 400);
	GraphArea bubbleGraph(bubbleSortTimes, "BubbleSort - Tiempo vs N");
	bubbleWindow.add(bubbleGraph);
	bubbleWindow.show_all();
	
	Gtk::Window selectionWindow;
	selectionWindow.set_default_size(600, 400);
	GraphArea selectionGraph(selectionSortTimes, "SelectionSort - Tiempo vs N");
	selectionWindow.add(selectionGraph);
	
	Gtk::Window mergeWindow;
	mergeWindow.set_default_size(600, 400);
	GraphArea mergeGraph(mergeSortTimes, "MergeSort - Tiempo vs N");
	mergeWindow.add(mergeGraph);
	
	// Lanzar las ventanas en secuencia
	app->run(bubbleWindow);
	app->run(selectionWindow);
	app->run(mergeWindow);
	
	return 0;
}
