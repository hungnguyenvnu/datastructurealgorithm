#include <iostream>
#include "DSABinaryTree.h"


int main() {
	DSABinaryTree* pBinaryTree = new DSABinaryTree;
	pBinaryTree->Insert(50);
	pBinaryTree->Insert(20);
	pBinaryTree->Insert(60);
	pBinaryTree->Insert(70);
	pBinaryTree->Insert(10);

	pBinaryTree->TraversalInorderBT(pBinaryTree->GetRootNode());

	return 0;
}