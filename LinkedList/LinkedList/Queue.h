#pragma once
#include <iostream>
#include "SinglyLinkedList.h"

class Queue
{
private:
    SinglyLinkedList sLinkedList;
    int n;
public:
    Queue();
    int size();
    bool empty();
    int front();
    void enqueue(int e);
    void dequeue();
};

