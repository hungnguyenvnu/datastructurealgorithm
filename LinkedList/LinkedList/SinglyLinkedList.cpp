#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() 
{
	head = NULL;
	size = 0;
}

SinglyLinkedList::~SinglyLinkedList() 
{
	while (!empty()) 
	{
		removeFront();
		size--;
	}
}

bool SinglyLinkedList::empty() 
{
	return head == NULL;
}

int SinglyLinkedList::front() {
	return head->data;
}

void SinglyLinkedList::addFront(int data) 
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->pNext = head;
	head = newNode;
	size++;
	return;
}

void SinglyLinkedList::removeFront() 
{
	Node *temp = head;
	head = temp->pNext;
	delete temp;
	size--;
}

int SinglyLinkedList::getSize() 
{
	return size;
}

void SinglyLinkedList::print() 
{
	Node* temp = head;
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->pNext;
	}
}