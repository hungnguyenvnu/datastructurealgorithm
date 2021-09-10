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
	Node (int nData) 
	{
		this->nData = nData;
		this->pNext = nullptr;
	}
		
	int GetData() 
	{
		return nData;
	}
};

class Stack 
{
private:
	Node* pHead = null;
	Node* pTail = null;
	int nSize = 0;
public:
	Stack() {}
	
	int Size() 
	{
		return nSize;
	}
	
	bool IsEmpty() 
	{
		return (nSize == 0);
	}
	
	int First() {
		if (IsEmpty()) 
		{
		    std::cout << "List is empty!\n";
			return 0;
		}
		return pHead->GetData();
	}
	
	int Last() {
		if (IsEmpty()) 
		{
			std::cout << "List is empty!\n";
			return 0;
		}
		return pTail->GetData();
	}
	
	void Push(int nData) {
		Node newest = new Node(e, head);
		if (isEmpty()) {
			head = tail = newest;
		} else {
			Node newNext = newest.getNext(); 
			newNext = head;
			head = newest;
		}
		size++;
		return;
	}
	
	void Pop() {
		if (isEmpty()) {
			return;
		}
		head = head.getNext();
		size--;
		if (size == 0) {
			tail = null;
		}
	}
};

int main()
{
    cout<<"Hello World";

    return 0;
}

#endif // _STACK_H_

```
