#pragma once

#include <iostream>

class Node
{
public:
	int		nData = 0;
	Node*	pNext = nullptr;
};

class LinkedList
{

public:
	LinkedList();
	~LinkedList();

	bool	IsEmpty					();
	int		GetLength				();
	void	AppendNode				(int nData);
	void	DeleteNodeatAt			(int nIdx);
	void	DeleteNodesByValue		(int nValue);
	void	Print					();
	void	RemoveDuplicate			(); 
	void	RemoveDuplicateUseBuffer();
	void	RemoveDuplicateSorted	();
	Node*	ReturnKthToLast			(Node* pNode, int k, int& i);
	bool	DeleteMiddleNode		(Node* pNode);
	Node*	SumList					(Node* ptrNode1, Node* ptrNode2, int carry);
	bool	IsLinkedListPalindrome	();
private:
	int		m_nLength	= 0;		// Length of linked list
	Node*	m_pHead		= nullptr;	// Pointer points to the first node
};

