#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	m_pRoot = nullptr;
}
BinarySearchTree::~BinarySearchTree()
{
}

Node* BinarySearchTree::Insert(int nData, Node* pNode)
{
	Node* pRet = nullptr;
	Node* pNewNode = new Node(nData);

	if (pNode == nullptr)
	{
		pNode = pNewNode;
	}
	else if (pNode->m_nData > nData)
	{
		pNode->m_pLeft = Insert(nData, pNode->m_pLeft);
	}
	else if (pNode->m_nData < nData)
	{
		pNode->m_pRight = Insert(nData, pNode->m_pRight);
	}
	pRet = pNode;
	return pRet;
}

void BinarySearchTree::PrintPreOrder(Node *pNode)
{
	if (pNode != nullptr)
	{
		std::cout << pNode->m_nData << " ";
		PrintPreOrder(pNode->m_pLeft);
		PrintPreOrder(pNode->m_pRight);
	}
	
}

int main()
{
	BinarySearchTree* pBST = new BinarySearchTree;
	Node* pNode = pBST->GetRootNode();
	pNode = pBST->Insert(10, pNode);
	pNode = pBST->Insert(9, pNode);
	pNode = pBST->Insert(8, pNode);
	pNode = pBST->Insert(11,pNode);
	pNode = pBST->Insert(12, pNode);

	pBST->PrintPreOrder(pNode);
	return 0;
}