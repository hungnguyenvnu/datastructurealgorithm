#include "Stack.h"

Stack::Stack() : sLinkedList(), n(0) {}

int Stack::size() 
{
	return n;
}

bool Stack::empty() 
{
	return n == 0;
}

int Stack::top() 
{
	if (!empty())
		return sLinkedList.front();
	return NULL;
}

//void Stack::push(int data) 
//{
//	sLinkedList.addFront(data);
//	n++;
//}

void Stack::pop() 
{
	sLinkedList.removeFront();
	n--;
}