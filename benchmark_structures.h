#ifndef BENCHMARK_STRUCTURES_H
#define BENCHMARK_STRUCTURES_H

#include "linked_list.h"
#include "binary_search_tree.h"

double measureInsertTime(LinkedList& list, int value);
double measureSearchTime(LinkedList& list, int value);
double measureRemoveTime(LinkedList& list, int value);

double measureInsertTime(BinarySearchTree& bst, int value);
double measureSearchTime(BinarySearchTree& bst, int value);
double measureRemoveTime(BinarySearchTree& bst, int value);

#endif // BENCHMARK_STRUCTURES_H
