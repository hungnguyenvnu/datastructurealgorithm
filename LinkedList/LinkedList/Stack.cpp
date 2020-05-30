#include "Stack.h"

Stack::Stack() : sLinkedList(), n(0) {}

int Stack::size() const
{
	return n;
}

bool Stack::empty() 
{
	return (n == 0);
}

int Stack::top()
{
	if (!empty())
	{
		return sLinkedList.front();
	}
	else
	{
		return 0;
	}
}

void Stack::push(int iData) 
{
	sLinkedList.insertFront(iData);
	n++;
}

void Stack::pop() 
{
	sLinkedList.removeFront();
	n--;
}