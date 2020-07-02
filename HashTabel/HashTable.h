/*
 * Implementation of hashtable using chaining for collision resolution.
 *
 *  Created on: June 30, 2020
 *  Author: Vincent Nguyen
 */
#pragma once

const int l = 10;
const int w = 20;
const int n = 1 << 9; // the number of items to be stored in the table is 2^9; the load factor is 50%
const int m = 1 << l;
const int r = 1;


struct Node
{
    int x;
    struct Node* next;
};

class HashTable
{
private:
    Node** pHashNode;    
public:
    HashTable();
    ~HashTable();
    int hash(int x);
    void putToTable(int x);
    bool lookUp(int x);
    // Linked list
    Node* addToList(Node* pHead, int x);
    void printList(Node* pHead);
};