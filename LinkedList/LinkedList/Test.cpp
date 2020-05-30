#include <iostream>
#include "SinglyLinkedList.h"
//#include "Stack.h"
//#include "Queue.h"


int main() {
	SinglyLinkedList* pSinglyLinkedList = new SinglyLinkedList();
	pSinglyLinkedList->insertFront(10);
	pSinglyLinkedList->insertFront(20);
	pSinglyLinkedList->insertFront(50);
	pSinglyLinkedList->insertLast(30);

	Node *pPreNode = pSinglyLinkedList->getHead();
	pSinglyLinkedList->insertAfterNode(pPreNode, 40);
	pSinglyLinkedList->print();

	pSinglyLinkedList->removeFront();
	pSinglyLinkedList->removeLast();
	std::cout << std::endl;
	pSinglyLinkedList->print();
	/*Stack* stack = new Stack();
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
	std::cout << queue->size() << std::endl;*/

	system("PAUSE");

	return 0;
}