#pragma once
#include "SinglyLinkedList.h"

class Stack
{
private:
	SinglyLinkedList sLinkedList;
	int n;
public: 
	Stack();
	int size() const;
	bool empty();

	int top(); // Return the first element
	void push(int iData);
	void pop();
};