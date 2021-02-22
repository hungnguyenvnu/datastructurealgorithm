#pragma once

template <typename T>
struct Node
{
	T data;
	struct Node* pNext;
};

template <typename T>
class LinkedList
{
private:
	int nLength;
	Node<T>* pHead;
public:
	LinkedList();
	~LinkedList();
	void InsertFirst(int nData);
	bool IsEmpty();
	void DeleteAllNode();
	void DeleteNodeAt(int nIdx);
	void DeleteNodeByValue(T data);
	void RemoveDuplicate();
	void PrintKthToLast(int k);
	
	void PrintList();
};

