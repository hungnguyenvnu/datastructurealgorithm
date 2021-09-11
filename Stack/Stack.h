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

```
