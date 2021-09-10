```
/*
* An implementation of linked list
*
*  Created on: Feb 20th, 2021
*      Author: Vincent Nguyen
*/
#include <iostream>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	this->nLength = 0;
	this->pHead = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	DeleteAllNode();
}

template <typename T>
bool LinkedList<T>::IsEmpty()
{
	return nLength == 0;
}

template <typename T>
void LinkedList<T>::InsertFirst(int nData)
{
	Node<T>* pNewNode = new Node<T>;
	pNewNode->data = nData;
	pNewNode->pNext = pHead;
	pHead = pNewNode;
	nLength++;
}

template <typename T>
void LinkedList<T>::DeleteAllNode()
{
	if (IsEmpty())
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		// Delete all node
		Node<T>* pNode = pHead;
		while (pNode != nullptr)
		{
			Node<T>* pCurr = pNode;
			pNode = pNode->pNext;
			delete pCurr;
			nLength--;
		}
	}
}

// Delete node at K position
template <typename T>
void LinkedList<T>::DeleteNodeAt(int nIdx)
{
	if (nIdx < 0 || nIdx >= nLength)
	{
		std::cout << "Exceed length of linked list";
	}
	else
	{
		Node<T>* pCurrNode = pHead;
		if (nIdx == 0)
		{
			pHead = pHead->pNext;
			delete pCurrNode;
		}
		else
		{
			for (int i = 0; i < nIdx; i++)
			{
				pCurrNode = pCurrNode->pNext;
			}
			Node<T>* pTemp = pCurrNode->pNext;
			pCurrNode->pNext = pCurrNode->pNext->pNext;
			delete pTemp;
		}
		nLength--;
	}
}

// Delete node has value T
template <typename T>
void LinkedList<T>::DeleteNodeByValue(T data)
{
	if (IsEmpty())
	{
		std::cout << "List is empty";
	}
	else
	{
		Node<T>* pCurrNode = pHead;
		Node<T>* pTemp = nullptr;
		// Delete the first node
		if (!IsEmpty() && pCurrNode->data == data)
		{
			pTemp = pCurrNode;
			pHead = pCurrNode->pNext;
			pCurrNode = pCurrNode->pNext;
			delete pTemp;
			nLength--;
		}
		// Traverse linked list to delete node
		while (!IsEmpty() && pCurrNode->pNext != nullptr)
		{
			if (pCurrNode->pNext->data == data)
			{
				pTemp = pCurrNode->pNext;
				pCurrNode->pNext = pCurrNode->pNext->pNext;
				delete pTemp;
				nLength--;
			}
			pCurrNode = pCurrNode->pNext;
		}
	}
}

// Remove duplicates from an unsorted linked list
template <typename T>
void LinkedList<T>::RemoveDuplicate()
{
	// Using temporary map

	// Temporary buffer is not allowed
	// Using 2 pointer: pCurrNode which iterates through the linked list
	//					pRunnerNode which check all subsequent nodes for dupplicate

	Node<T>* pCurrNode = pHead;
	while (pCurrNode != nullptr)
	{
		// Remove all future node that have same value
		Node<T>* pRunnerNode = pCurrNode;
		while (pRunnerNode->pNext != nullptr)
		{
			if (pRunnerNode->pNext->data == pCurrNode->data)
			{
				Node<T>* pTemp = pRunnerNode->pNext;
				pRunnerNode->pNext = pRunnerNode->pNext->pNext;
				delete pTemp;
				nLength--;
			}
			else
			{
				pRunnerNode = pRunnerNode->pNext;
			}
		}
		pCurrNode = pCurrNode->pNext;
	}
}

// Find the kth to last element of singly linked list 
// Get node value from tail
template <typename T>
void LinkedList<T>::PrintKthToLast(int k)
{
	// Solution #1: If size of linked list is know, print element at (length - k)
	// Solution #2: Recursive
}

// Reverse a linked list
template <typename T>
Node<T>* LinkedList<T>::ReverseLinkedList()
{
	Node<T>* pCurrNode = pHead;
	Node<T>* pPrevNode = nullptr;
	Node<T>* pNextNode = nullptr;

	while (pCurrNode != nullptr)
	{
		pNextNode = pCurrNode->pNext;
		pCurrNode->pNext = pPrevNode;
		pPrevNode = pCurrNode;
		pCurrNode = pNextNode;
	}
	pHead = pPrevNode;
	return pHead;
}

template <typename T>
void LinkedList<T>::PrintList()
{
	if (IsEmpty())
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		Node<T>* pNode = pHead;
		while (pNode != nullptr)
		{
			std::cout << pNode->data << " ";
			pNode = pNode->pNext;
		}
	}
}

int main()
{
	LinkedList<int>* pList = new LinkedList<int>;

	for (int i = 9; i >= 0; i--)
	{
		pList->InsertFirst(i);
	}
	//pList->InsertFirst(3);
	//pList->PrintList();
	//std::cout << std::endl;
	//pList->RemoveDuplicate();
	
	//pList->DeleteNodeAt(3);
	//pList->DeleteNodeByValue(8);
	pList->PrintList();
	Node<int>* pHead = pList->GetHeadNode();
	pHead  = pList->ReverseLinkedList();
	pList->PrintList();
	return 0;
}
```
