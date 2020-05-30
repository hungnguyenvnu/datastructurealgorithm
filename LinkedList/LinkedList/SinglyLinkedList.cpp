#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() 
{
	pHead = nullptr;
	uSize = 0;
}

SinglyLinkedList::~SinglyLinkedList() 
{
	while (!empty()) 
	{
		removeFront();
		uSize--;
	}
}

bool SinglyLinkedList::empty() 
{
	return pHead == nullptr;
}

int SinglyLinkedList::front() const
{
	return pHead->iData;
}

Node *SinglyLinkedList::getHead() const
{
	return pHead;
}


int SinglyLinkedList::getSize() const
{
	return uSize;
}

void SinglyLinkedList::insertFront(int iData) 
{
	Node* pNewNode	= new Node;
	pNewNode->iData = iData;
	pNewNode->pNext = pHead;
	pHead			= pNewNode;
	uSize++;
}

void SinglyLinkedList::insertLast(int iData)
{
	Node* pNewNode = new Node;
	pNewNode->iData = iData;
	pNewNode->pNext = nullptr;
	Node *pTemp = pHead;
	if (pHead == nullptr)
	{
		pHead = pNewNode;
	}
	else
	{
		while (pTemp->pNext != nullptr)
		{
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pNewNode;
	}
	uSize++;
}

void SinglyLinkedList::insertAfterNode(Node *pPreNode, int iData)
{
	Node* pNewNode = new Node;
	pNewNode->iData = iData;
	pNewNode->pNext = nullptr;

	if (pPreNode == nullptr)
	{
		return;
	}
	else
	{
		pNewNode->pNext = pPreNode->pNext;
		pPreNode->pNext = pNewNode;
	}
}


void SinglyLinkedList::removeFront() 
{
	Node *pTemp = pHead;
	pHead = pTemp->pNext;
	delete pTemp;
	uSize--;
}

void SinglyLinkedList::print() 
{
	Node* pTemp = pHead;
	while (pTemp != NULL) {
		std::cout << pTemp->iData << " ";
		pTemp = pTemp->pNext;
	}
}