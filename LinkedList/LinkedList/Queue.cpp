#include <iostream>
#include "Queue.h"

Queue::Queue() : sLinkedList(), n(0) {}

int Queue::size() 
{
	return n;
}

bool Queue::empty() 
{
	return n == 0;
}

int Queue::front() {
	return sLinkedList.front();
}

void Queue::enqueue(int iData)
{
	sLinkedList.insertFront(iData);
	n++;
}

void Queue::dequeue() 
{
	sLinkedList.removeLast();
	n--;
}