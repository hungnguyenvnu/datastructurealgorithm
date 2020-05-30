#include <iostream>
#include "SinglyLinkedList.h"
#include "Stack.h"
//#include "Queue.h"


int main() {
	Stack* pStack = new Stack();
	pStack->push(10);
	pStack->push(20);
	pStack->push(30);

	std::cout << pStack->size() << std::endl;
	std::cout << pStack->top() << std::endl;
	system("PAUSE");

	return 0;
}