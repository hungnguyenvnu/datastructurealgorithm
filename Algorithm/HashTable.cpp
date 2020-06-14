#include "HashTable.h"

HashTable::HashTable()
{
	pHashTable = new int[NUM_CHAR];
	for (int i = 0; i < NUM_CHAR; i++)
	{
		pHashTable[i] = 0;
	}
}

HashTable::~HashTable()
{
	delete [] pHashTable;
}

int HashTable::hashFunction(char c)
{
	int iRet = (int) c;
	return iRet;
}

void HashTable::insert(char c)
{
	int value = hashFunction(c);
	pHashTable[value]++;
}

char HashTable::firstNonRepeat()
{
	char cRet;
	for (int i = 0; i < NUM_CHAR; i++)
	{
		if (pHashTable[i] == 1)
		{
			cRet = static_cast<char>(i);
			break;
		}
	}
	return cRet;
}