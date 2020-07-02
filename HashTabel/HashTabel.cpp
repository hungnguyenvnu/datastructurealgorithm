/*
 * Implementation of hashtable using chaining for collision resolution.
 *
 *  Created on: June 30, 2020
 *  Author: Vincent Nguyen
 */
#include <iostream>
#include "HashTable.h"

HashTable::HashTable()
{
	pHashNode = new Node*[m];
}

HashTable::~HashTable()
{

}

bool HashTable::lookUp(int x) 
{
	int iPos = hash(x);
	Node* pNode = pHashNode[iPos];
	while (pNode != NULL) 
	{
		if (pNode->x == x) 
		{
			printf("%d is at location %d of the table\n", x, hash(x));
			return true;
		}
		pNode = pNode->next;
	}
	printf("%d Not found!\n", x);
	return false;
}

// we use binary multiplicative hash funciton.
int HashTable::hash(int x)
{
	return ((r * x) & ((1 << w) - 1)) >> (w - l);
}

// add an element to the head of a linked list
Node* HashTable::addToList(Node* pHead, int x)
{
	Node* pNode = new Node;
	pNode->x = x;
	pNode->next = pHead;
	pHead = pNode;
	return pHead;
}

void HashTable::putToTable(int x)
{
	int iPos = hash(x);
	pHashNode[iPos] = addToList(pHashNode[iPos], x);
}

// print a linked list given a head pointer;
void HashTable::printList(Node* pHead)
{
	Node* pRunner = pHead;
	while (pRunner != NULL) 
	{
		printf("%d ", pRunner->x);
		pRunner = pRunner->next;
	}
	printf("\n");
}

int main() 
{
	HashTable* pHashTable = new HashTable;
	int* A;	// data to be hashed
	A = new int[n];
	int max = (1 << 31);
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % max;
	}
	// Allocate m slots for hash table
	for (int i = 0; i < n; i++)
	{
		pHashTable->putToTable(A[i]);
	}
	pHashTable->lookUp(A[3]);
	pHashTable->lookUp(10000);
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
