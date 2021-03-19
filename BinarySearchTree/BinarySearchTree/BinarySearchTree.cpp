#include "BinarySearchTree.h"
#include <algorithm>

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

bool BinarySearchTree::Search(int nData, Node* pNode)
{
	if (pNode->m_nData == nData)
	{
		return true;
	}
	else if (nData < pNode->m_nData)
	{
		return Search(nData, pNode->m_pLeft);
	}
	else if (nData > pNode->m_nData)
	{
		return Search(nData, pNode->m_pRight);
	}
}

int	BinarySearchTree::FindMinData(Node* pNode)
{
	if (pNode != nullptr)
	{
		if (pNode->m_pLeft == nullptr)
		{
			return pNode->m_nData;
		}
		else
		{
			return FindMinData(pNode->m_pLeft);
		}
	}
}

int	BinarySearchTree::FindMaxData(Node* pNode)
{
	if (pNode != nullptr)
	{
		if (pNode->m_pRight == nullptr)
		{
			return pNode->m_nData;
		}
		else
		{
			return FindMaxData(pNode->m_pRight);
		}
	}
}

void BinarySearchTree::Delete(Node* pNode, int nData)
{
	if (nData < pNode->m_nData)
	{
		Delete(pNode->m_pLeft, nData);
	}
	if (nData > pNode->m_nData)
	{
		Delete(pNode->m_pRight, nData);
	}
	else
	{
		if (pNode->m_pLeft != nullptr && pNode->m_pRight != nullptr)
		{
			pNode->m_nData = DeleteMin(pNode->m_pRight);
		}
		else
		{
			Node* pTemp = pNode;
			pNode = (pNode->m_pLeft != nullptr) ? pNode->m_pLeft : pNode->m_pRight;
			delete pTemp;
		}
	}
}

int	BinarySearchTree::DeleteMin(Node* pNode)
{
	if (pNode != nullptr)
	{
		if (pNode->m_pLeft != nullptr)
		{
			return DeleteMin(pNode->m_pLeft);
		}
		else
		{
			Node* pTemp = pNode;
			pNode = pNode->m_pRight;
			delete pTemp;
			return pNode->m_nData;
		}
	}
}

int BinarySearchTree::HeightOfTree(Node* pNode)
{
	// The height of tree equals the height of its tallest 
	// subtree plus one
	if (pNode == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + std::max(HeightOfTree(pNode->m_pLeft), HeightOfTree(pNode->m_pLeft));
	}
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

void BinarySearchTree::PrintInOrder(Node* pNode)
{
	if (pNode != nullptr)
	{
		PrintInOrder(pNode->m_pLeft);
		std::cout << pNode->m_nData << " ";
		PrintInOrder(pNode->m_pRight);
	}
}

void BinarySearchTree::PrintPostOrder(Node* pNode)
{
	if (pNode != nullptr)
	{
		PrintPostOrder(pNode->m_pLeft);
		PrintPostOrder(pNode->m_pRight);
		std::cout << pNode->m_nData << " ";
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
	pNode = pBST->Insert(15, pNode);
	pNode = pBST->Insert(7, pNode);

	bool bFound = pBST->Search(10, pNode);
	if(bFound)
	{
		std::cout << "Data is found" << std::endl;
	}
	else
	{
		std::cout << "Data is not found" << std::endl;
	}
	pBST->PrintInOrder(pNode);
	//int nMinData = pBST->FindMinData(pNode);
	//int nMaxData = pBST->FindMaxData(pNode);
	int nHeight = pBST->HeightOfTree(pNode);
	//pBST->Delete(pNode, 10);
	//std::cout << std::endl;
	//pBST->PrintPreOrder(pNode);
	return 0;
}