```
#include <iostream>
#include "Stack.h"

class Node 
{
private:
	int nData;
	Node* pNext;
public:		
		// Constructor
	
};
Node::Node (int nData) 
{
	this->nData = nData;
	this->pNext = nullptr;
}
		
int Node::GetData() 
{
	return nData;
}
Node* Node::GetNext()
{
    return pNext;
}

// Default constructor
Stack::Stack() 
{
	//
}
	
int Stack::Size() 
{
	return nSize;
}

bool Stack::IsEmpty() 
{
	return (nSize == 0);
}

int Stack::First() 
{
	if (IsEmpty()) 
	{
	    std::cout << "List is empty!\n";
		return 0;
	}
	return pHead->GetData();
}

int Stack::Last() 
{
	if (IsEmpty()) 
	{
		std::cout << "List is empty!\n";
		return 0;
	}
	return pTail->GetData();
}

void Stack::Push(int nData) 
{
	Node* pNewNode = new Node(nData);
	if (IsEmpty()) 
	{
		pHead = pTail = pNewNode;
	} 
	else 
	{
	    Node* pNextNode = pNewNode->GetNext();
		pNextNode = pHead;
		pHead = pNewNode;
	}
	nSize++;
	return;
}

void Stack::Pop() 
{
	if (IsEmpty()) 
	{
		return;
	}
	pHead = pHead->GetNext();
	nSize--;
	if (nSize == 0) 
	{
		pTail = nullptr;
	}
}

```
