#pragma once
class DSANode {
public:
	int iData;
	DSANode* pLeft;
	DSANode* pRight;
	DSANode(int data) : iData(data), pLeft(NULL), pRight(NULL) {}
};

class DSABinaryTree
{
public:
	// Default constructor
	DSABinaryTree() 
	{
		pRoot = NULL;
	}
	// Copy constructor
	DSABinaryTree(const DSABinaryTree& pBinaryTree) 
	{
		pRoot = NULL;
		*this = pBinaryTree;
	}

	// Destructor
	~DSABinaryTree();

	bool IsBSTEmpty() {
		return pRoot == NULL;
	}

	// Insert new data (data) to binary tree
	void Insert(int data);
	
	// Delete node with data
	void Delete();
	
	// Delete min value
	int DeleteMin();

	// Search value: iValue
	bool Search(int data);

	// Min and max value in binary tree
	int Min() const;
	int Max() const;
	void TraversalPreorderBT(DSANode* pNode);
	void TraversalInorderBT(DSANode* pNode);
	DSANode* GetRootNode() 
	{
		return pRoot;
	}
private:
	DSANode* pRoot;

	void MakeBSTEmpty(DSANode* pNode);

	// Insert
	void Insert(int data, DSANode* pNode);

	//// Delete
	//void Delete(int key, DSANode* pNode);

	//int DeleteMin(DSANode* pNode);

	//bool Search(int data, DSANode* pNode);

	//int Min(DSANode* pNode) const;
	//int Max(DSANode* pNode) const;
};

