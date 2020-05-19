#include <iostream>
#include "SinglyLinkedList.h"
#include "Stack.h"
#include "Queue.h"


int main() {
	SinglyLinkedList* singlyLinkedList = new SinglyLinkedList();
	singlyLinkedList->addFront(10);
	singlyLinkedList->addFront(20);
	singlyLinkedList->addFront(30);
	singlyLinkedList->print();

	Stack* stack = new Stack();
	stack->push(10);
	stack->push(20);
	stack->push(30);

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

	return 0;
}