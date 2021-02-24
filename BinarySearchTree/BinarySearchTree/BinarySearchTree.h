#pragma once

#include <iostream>

struct Node
{
	int m_nData;
	struct Node* m_pLeft;
	struct Node* m_pRight;
	Node(int nData): m_nData(nData), m_pLeft(nullptr), m_pRight(nullptr) {}
};

class BinarySearchTree
{
private:
	Node* m_pRoot;
public:
	BinarySearchTree();
	~BinarySearchTree();
	Node* GetRootNode() 
	{
		return m_pRoot;
	}
	Node* Insert(int nData, Node *pNode);
	void PrintPreOrder(Node *pNode);
};

