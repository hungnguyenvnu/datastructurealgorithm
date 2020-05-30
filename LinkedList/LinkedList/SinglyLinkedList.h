#pragma once

#include <iostream>

struct Node {
	int iData;
	Node* pNext;
};

class SinglyLinkedList
{
private:
	Node*			pHead; // Head points to first element of linked list
	unsigned int	uSize; // Number element of linked list
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	bool	empty();
	int		front() const;
	int		getSize() const;
	Node*	getHead() const;

	// Insert node
	void	insertFront(int iData);						// Insert new node in front of list
	void	insertLast(int iData);						// Insert new node at the end of list
	void	insertAfterNode(Node *pPreNode, int iData);	// Insert new node after a node

	// Delete node
	void	removeFront();	// Delete first node in linked list
	void	removeLast();	// Delete last node in linked list

	void	print();

	
};