#pragma once

#include <iostream>

struct Node {
	int data;
	Node* pNext;
};

class SinglyLinkedList
{
private:
	Node* head;
	int size;
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	bool empty();
	int front();
	void addFront(int data);
	void removeFront();
	int getSize();
	void print();
	Node* getHead() 
	{
		return head;
	}
};