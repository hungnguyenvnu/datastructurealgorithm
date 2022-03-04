#pragma once

#include <iostream>

struct Node
{
	int		nData = 0;
	Node* pNext = nullptr;
};

class LinkedList
{
private:
	int		m_nLength	= 0;		// Length of linked list
	Node*	m_pHead		= nullptr;	// Pointer points to the first node
public:
	LinkedList();
	~LinkedList();

	bool	IsEmpty		();
	int		GetLength	();
	void	AppendNode(int nData);
	void DeleteNodeatAt(int nIdx);
	void DeleteNodesByValue(int nValue);
	void Print();
	void RemoveDuplicate();
	void RemoveDuplicateSorted();

};

