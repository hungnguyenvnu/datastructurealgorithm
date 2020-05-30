#include <iostream>
#include "SinglyLinkedList.h"
#include "Queue.h"


int main() 
{
	Queue* queue = new Queue();
	queue->enqueue(20);
	queue->enqueue(30);
	queue->enqueue(40);
	queue->enqueue(50);
	queue->enqueue(60);
	
	std::cout << queue->size() << std::endl;
	queue->dequeue();
	std::cout << queue->front() << std::endl;
	std::cout << queue->size() << std::endl;

	system("PAUSE");

	return 0;
}