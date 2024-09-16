#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class Node {
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
	BinarySearchTree() : root(nullptr) {}
	
	void insert(int value);
	bool search(int value);
	void remove(int value);
	
private:
	Node* root;
	
	Node* insert(Node* node, int value);
	Node* search(Node* node, int value);
	Node* remove(Node* node, int value);
	Node* findMin(Node* node);
};

#endif // BINARY_SEARCH_TREE_H
