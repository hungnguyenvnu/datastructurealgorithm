#pragma once

#define SIZE 20
struct Item
{
	int data;
	int priority
};
class PriorityQueue
{
public:
	// Default Constructor
	PriorityQueue()
	{
		last = -1;
	}

	PriorityQueue(Item* element, int n);

	bool Empty()
	{
		return last < 0;
	}
	Item& FindMin();

	void Insert(Item &object, bool& suc);

	// Delete item which has minimum priority
	Item& DeleteMin();
private:
	Item data[SIZE];
	int last;
	void ShiftDown(int i); // Move data to suitable position
};

