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

void Queue::enqueue(int data) 
{
	sLinkedList.addFront(data);
	n++;
}

void Queue::dequeue() {
	// Queue is empty
	if (empty()) 
	{
		std::cout << "Queue is empty" << std::endl;
	}
	else 
	{
		Node* current = sLinkedList.getHead();
		// Queue has 1 element
		if (current->pNext == NULL) 
		{
			Node* temp = current;
			current = NULL;
			delete temp;
		}
		else 
		{
			// Queue has at least 2 elements
			Node* temp = current->pNext;
			while (temp != NULL) 
			{
				if (temp->pNext == NULL) 
				{
					current->pNext = NULL;
					delete temp;
					break;
				}
				current = current->pNext;
				temp = temp->pNext;
			}
		}
		n--;
	}
}