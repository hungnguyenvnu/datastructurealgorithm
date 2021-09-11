```
#infdef _STACK_H_
#define _STACK_H_

class Node 
{
private:
	int nData;
	Node* pNext;
public:		
	// Constructor
	Node (int nData);
		
	int GetData(); 
	Node* GetNext();
};

// 1st: using 2 pointer: head and tail
class Stack 
{
private:
	Node* pHead = nullptr;
	Node* pTail = nullptr;
	int nSize = 0;
public:
	Stack();
	
	int Size();
	bool IsEmpty();
	int First();
	int Last();
	void Push(int nData);
	void Pop();
};


#endif // _STACK_H_

// 2nd: utilize Linked List implementation with 2 methods: AddFirst and RemoveLast

```
