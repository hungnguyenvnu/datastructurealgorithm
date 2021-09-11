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
	Node (int nData) 
	{
		this->nData = nData;
		this->pNext = nullptr;
	}
		
	int GetData() 
	{
		return nData;
	}
	Node* GetNext()
	{
	    return pNext;
	}
};

class Stack 
{
private:
	Node* pHead = nullptr;
	Node* pTail = nullptr;
	int nSize = 0;
public:
	Stack() {}
	
	int Size() 
	{
		return nSize;
	}
	
	bool IsEmpty() 
	{
		return (nSize == 0);
	}
	
	int First() 
	{
		if (IsEmpty()) 
		{
		    std::cout << "List is empty!\n";
			return 0;
		}
		return pHead->GetData();
	}
	
	int Last() 
	{
		if (IsEmpty()) 
		{
			std::cout << "List is empty!\n";
			return 0;
		}
		return pTail->GetData();
	}
	
	void Push(int nData) 
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
	
	void Pop() 
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
};

```
