#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class ListNode {
public:
	int data;
	ListNode* next;
	
	ListNode(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
	LinkedList() : head(nullptr) {}
	
	void insert(int value);
	bool search(int value);
	void remove(int value);
	
private:
	ListNode* head;
};

#endif // LINKED_LIST_H
