#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(Item* element, int n)
{
	for (int i = 0; i < n; i++)
	{
		data[i] = element[i];
	}
	last = n - 1;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		ShiftDown(i);
	}
}

Item& PriorityQueue::FindMin()
{
	return data[0];
}

void PriorityQueue::ShiftDown(int i)
{
	Item x = data[i];			// store item 
	int parent = i;				// index of parent node
	int child = 2 * parent + 1; // index of left child
	while (child <= last)
	{
		int right = child + 1; // right child
		if (right <= last && data[right].priority < data[child].priority)
		{
			child = right;
		}
		if (x.priority > data[child].priority)
		{
			data[parent] = data[child];
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
	data[parent] = x;
}

Item& PriorityQueue::DeleteMin()
{
	data[0] = data[last--];
	ShiftDown(0);
}

void PriorityQueue::Insert(Item& object, bool& suc)
{
	if (last == SIZE - 1)
	{
		suc = false;
	}
	else
	{
		suc = true;
		int child = ++last;
		while (child > 0)
		{
			int parent = (child - 1) / 2;
			if (data[parent].priority > object.priority)
			{
				data[child] = data[parent];
				child = parent;
			}
			else
			{
				break;
			}
		}
		data[child] = object;
	}
}
