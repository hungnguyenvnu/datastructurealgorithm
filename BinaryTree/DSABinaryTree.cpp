#include <iostream>
#include "DSABinaryTree.h"

// Insert new element into binary tree
void DSABinaryTree::Insert(int data) 
{
	Insert(data, pRoot);
}


//int DSABinaryTree::DeleteMin() {
//	return DeleteMin(pRoot);
//}
//
//bool DSABinaryTree::Search(int iValue) {
//	return Search(iValue, pRoot);
//}
//
//int DSABinaryTree::Min() const {
//	return Min(pRoot);
//}
//
//int DSABinaryTree::Max() const {
//	return Max(pRoot);
//}



void DSABinaryTree::Insert(int data, DSANode* pNode) 
{
	if (pNode == NULL) 
	{
		pNode = new DSANode (data);
	}
	else if (data < pNode->iData) 
	{
		Insert(data, pNode->pLeft);
	}
	else if (data > pNode->iData) 
	{
		Insert(data, pNode->pRight);
	}
}

//void DSABinaryTree::Delete(int key) 
//{
//	Delete(key, pRoot);
//}
//
//
//int DSABinaryTree::DeleteMin(DSANode* pNode) 
//{
//	if (pNode->pLeft != NULL) 
//	{
//		return DeleteMin(pNode->pLeft);
//	}
//	else 
//	{
//		int iData = pNode->iData;
//		DSANode* pTemp = pNode;
//		pNode = pNode->pRight;
//		delete pTemp;
//		return iData;
//	}
//}
//
//void DSABinaryTree::Delete(int key, DSANode* pNode) 
//{
//	if (pNode != NULL)
//	{
//		if (key < pNode->iKey) 
//		{
//			Delete(key, pNode->pLeft);
//		}
//		else if (key > pNode->iKey) 
//		{
//			Delete(key, pNode->pRight);
//		}
//		else 
//		{
//			// Node has 2 child ones
//			if (pNode->pLeft != NULL && pNode->pRight != NULL) {
//				pNode->iData = DeleteMin(pNode->pRight);
//			}
//			else 
//			{
//				DSANode* pTemp = pNode;
//				if (pNode->pLeft != NULL) 
//				{
//					pNode = pNode->pLeft;
//				}
//				else 
//				{
//					pNode = pNode->pRight;
//				}
//				delete pTemp;
//			}
//		}
//
//	}
//}
//
//bool DSABinaryTree::Search(int key, DSANode* pNode) 
//{
//	if (pNode != NULL) {
//		if (key == pNode->iKey) {
//			return true;
//		}
//		else if (key < pNode->iKey) {
//			return Search(key, pNode->pLeft);
//		}
//		else {
//			return Search(key, pNode->pRight);
//		}
//	}
//	else {
//		return false;
//	}
//}
//
//int DSABinaryTree::Min(DSANode *pNode) const
//{
//	if (pNode != NULL)
//	{ 
//		if (pNode->pLeft != NULL)
//		{
//			return Min(pNode->pLeft);
//		}
//		else
//		{
//			return pNode->iData;
//		}
//	}
//}
//
//int DSABinaryTree::Max(DSANode* pNode) const
//{
//	if (pNode != NULL)
//	{
//		if (pNode->pRight != NULL)
//		{
//			return Max(pNode->pRight);
//		}
//		else
//		{
//			return pNode->iData;
//		}
//	}
//}


void DSABinaryTree::TraversalPreorderBT(DSANode* pNode) 
{
	if (pNode != NULL) 
	{
		TraversalInorderBT(pNode->pLeft);
		std::cout << pNode->iData;
		TraversalInorderBT(pNode->pRight);
	}
}

void DSABinaryTree::TraversalInorderBT(DSANode* pNode)
{
	if (pNode != NULL) 
	{
		std::cout << pNode->iData;
		TraversalInorderBT(pNode->pLeft);
		TraversalInorderBT(pNode->pRight);
	}
}


// Destructor
//DSABinaryTree::~DSABinaryTree() 
//{
//	MakeBSTEmpty(pRoot);
//}