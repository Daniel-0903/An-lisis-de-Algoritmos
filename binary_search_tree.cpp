#include "binary_search_tree.h"

// Insertar un nodo en el árbol
Node* BinarySearchTree::insert(Node* node, int value) {
	if (node == nullptr) {
		return new Node(value);
	}
	
	if (value < node->data) {
		node->left = insert(node->left, value);
	} else if (value > node->data) {
		node->right = insert(node->right, value);
	}
	return node;
}

void BinarySearchTree::insert(int value) {
	root = insert(root, value);
}

// Buscar un valor en el árbol
Node* BinarySearchTree::search(Node* node, int value) {
	if (node == nullptr || node->data == value) {
		return node;
	}
	
	if (value < node->data) {
		return search(node->left, value);
	} else {
		return search(node->right, value);
	}
}

bool BinarySearchTree::search(int value) {
	return search(root, value) != nullptr;
}

// Eliminar un nodo del árbol
Node* BinarySearchTree::remove(Node* node, int value) {
	if (node == nullptr) return node;
	
	if (value < node->data) {
		node->left = remove(node->left, value);
	} else if (value > node->data) {
		node->right = remove(node->right, value);
	} else {
		if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		} else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}
		
		Node* temp = findMin(node->right);
		node->data = temp->data;
		node->right = remove(node->right, temp->data);
	}
	return node;
}

Node* BinarySearchTree::findMin(Node* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

void BinarySearchTree::remove(int value) {
	root = remove(root, value);
}
