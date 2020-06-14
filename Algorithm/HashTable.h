#pragma once

#define NUM_CHAR 128

class HashTable
{
public:
	HashTable();
	~HashTable();
	int hashFunction(char c);
	void insert(char c);
	char firstNonRepeat();
private:
	int* pHashTable;
};

