#pragma once
#include "SinglyLinkedList.h"

class Stack
{
private:
	SinglyLinkedList sLinkedList;
	int n;
public: 
	Stack();
	int size();
	bool empty();
	// Return the first element
	int top(); 
	void push(int data);
	void pop();
};