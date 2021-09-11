```
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

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
	void PrintKthToLast(int kPos);
	Node<T>* GetHeadNode() 
	{
		return pHead;
	}
	
	Node<T>* ReverseLinkedList();
	
	void PrintList();
};

#endif // _LINKED_LIST_H_
```
