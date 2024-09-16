#include "linked_list.h"

// Insertar un nuevo nodo
void LinkedList::insert(int value) {
	ListNode* newNode = new ListNode(value);
	newNode->next = head;
	head = newNode;
}

// Buscar un valor en la lista
bool LinkedList::search(int value) {
	ListNode* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}

// Eliminar un nodo con un valor específico
void LinkedList::remove(int value) {
	ListNode* current = head;
	ListNode* prev = nullptr;
	
	while (current != nullptr && current->data != value) {
		prev = current;
		current = current->next;
	}
	
	if (current == nullptr) return;  // No encontrado
	
	if (prev == nullptr) {
		head = head->next;
	} else {
		prev->next = current->next;
	}
	
	delete current;
}
