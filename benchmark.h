#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <functional>

void generateBestCase(std::vector<int>& arr, int size);
void generateWorstCase(std::vector<int>& arr, int size);
void generateAverageCase(std::vector<int>& arr, int size);

double measureExecutionTime(std::function<void(int[], int)> sortFunction, int arr[], int size);

#endif // BENCHMARK_H
