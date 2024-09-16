#include <iostream>
#include <vector>
#include "sort_algorithms.h"
#include "benchmark.h"

int main() {
	std::vector<int> arr;
	int size = 1000; // Cambia el tamaño según tus pruebas
	
	// Generar el mejor caso
	generateBestCase(arr, size);
	std::cout << "Mejor caso (BubbleSort): " << measureExecutionTime(bubbleSort, arr.data(), size) << " segundos" << std::endl;
	
	// Generar el peor caso
	generateWorstCase(arr, size);
	std::cout << "Peor caso (BubbleSort): " << measureExecutionTime(bubbleSort, arr.data(), size) << " segundos" << std::endl;
	
	// Generar el caso promedio
	generateAverageCase(arr, size);
	std::cout << "Caso promedio (BubbleSort): " << measureExecutionTime(bubbleSort, arr.data(), size) << " segundos" << std::endl;
	
	return 0;
}
