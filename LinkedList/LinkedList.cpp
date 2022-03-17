// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : m_nLength {0}, m_pHead{nullptr}
{
}

// Destructor
LinkedList::~LinkedList()
{
    Node* pTemp = m_pHead;
    while (pTemp != nullptr)
    {
        Node* pCur = pTemp;
        pTemp = pTemp->pNext;
        delete pCur;
    }
}

bool LinkedList::IsEmpty()
{
    return ((m_nLength == 0) || (m_pHead == nullptr));
}

int LinkedList::GetLength()
{
    return m_nLength;
}

void LinkedList::AppendNode(int nData)
{
    Node* pNewNode = new Node;
    pNewNode->nData = nData;
    pNewNode->pNext = nullptr;

    if (IsEmpty())
    {
        m_pHead = pNewNode;
    }
    else
    {
        pNewNode->pNext = m_pHead;
        m_pHead = pNewNode;
    }
    m_nLength++;
}

void LinkedList::DeleteNodeatAt(int nIdx)
{
}

void LinkedList::DeleteNodesByValue(int nValue)
{
    if (!IsEmpty())
    {
        Node* pCur = m_pHead;

        // Delete first node
        if (m_pHead->nData == nValue)
        {
            Node* pTemp = pCur;
            pCur = pCur->pNext;
            m_pHead = pCur;
            delete pTemp;
            m_nLength--;
        }

        while ((!IsEmpty()) && (pCur->pNext != nullptr))
        {
            if (pCur->pNext->nData == nValue)
            {
                Node* pTemp = pCur->pNext;
                pCur->pNext = pCur->pNext->pNext;;
                delete pTemp;
                m_nLength--;
            }
            pCur = pCur->pNext;
        }
    }
    else
    {
        std::cout << "List empty!";
    }
}

void LinkedList::Print()
{
    Node* pTemp = m_pHead;
    while (pTemp != nullptr)
    {
        std::cout << pTemp->nData << std::endl;
        pTemp = pTemp->pNext;
    }
}

// Cracking Coding Interview
// 2.1 - Remove Duplicates
// Write code to remove duplicated from an unsorted linked list
// No allow buffer: Using 2 pointers to traverse list

void LinkedList::RemoveDuplicate()
{
    if (!IsEmpty())
    {
        Node* pCur = m_pHead;
        while (pCur != nullptr)
        {
            Node* pRun = pCur;
            while (pRun->pNext != nullptr)
            {
                if (pRun->pNext->nData == pCur->nData)
                {
                    Node* pTemp = pRun->pNext;
                    pRun->pNext = pRun->pNext->pNext;
                    delete pTemp;
                    m_nLength--;
                }
                else
                {
                    pRun = pRun->pNext;
                }

            }
            pCur = pCur->pNext;
        }
    }
    else
    {
        std::cout << "List is empty!";
    }
}

void LinkedList::RemoveDuplicateUseBuffer()
{
    if (!IsEmpty())
    {
        std::map<int, int> mapValue;
        {
            Node* pCur = m_pHead;
            while (pCur != nullptr)
            {
                if (mapValue.find(pCur->nData) != mapValue.end())
                {
                    mapValue[pCur->nData] = 1;
                }
                else
                {
                    mapValue[pCur->nData]++;
                }
                pCur = pCur->pNext;
            }

            //int nNumOnlyOneNode = 0;
            //for (auto& elm : mapValue)
            //{
            //    if (elm.second == 1)
            //    {
            //        nNumOnlyOneNode++;
            //    }
            //}
            //m_nLength = nNumOnlyOneNode;

            //if (nNumOnlyOneNode == 0)
            //{
            //    return; // all nodes values are repeated more than once
            //}

            //int nNode = 0;
            
            pCur = m_pHead;
            std::map<int, int>::iterator iter = mapValue.begin();
            while (iter != mapValue.end())
            {
                pCur->nData = iter->first;
                pCur = pCur->pNext;
            }
            pCur->pNext = nullptr;   
        }
    }
    else
    {
        std::cout << "List is empty!";
    }
}

void LinkedList::RemoveDuplicateSorted()
{
    if (!IsEmpty())
    {
        std::map<int, int> mapValue;
        Node* pCur = m_pHead;
        while (pCur != nullptr) 
        {
            mapValue[pCur->nData]++;
            pCur = pCur->pNext;
        }
        int nNumOnlyOneNode = 0;
        for (auto& elm : mapValue) 
        {
            if (elm.second == 1)
            {
                nNumOnlyOneNode++;
            }
        }
        m_nLength = nNumOnlyOneNode;

        if (nNumOnlyOneNode == 0)
        {
            return; // all nodes values are repeated more than once
        }
            
        int nNode = 0;

        pCur = m_pHead;
        for (auto& elm : mapValue) 
        {
            if (elm.second == 1) 
            {
                pCur->nData = elm.first;
                nNode++;
                if (nNode != nNumOnlyOneNode)
                {
                    pCur = pCur->pNext;
                }
            }
        }
    }
    else
    {
        std::cout << "List empty!";
    }
}
// 2.2 Return Kth to Last
// Implement an algorithm to find the kth to last element of a singly linked list

// Sol 1: Get elements from length - k pos 
// Sol 2: Recursive (less optimal)

Node* LinkedList::ReturnKthToLast(Node* pNode, int k, int& i)
{
    if (m_pHead == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node* pRet = ReturnKthToLast(m_pHead->pNext, k, i);
        i = i + 1;
        if (i == k)
        {
            return m_pHead;
        }
        return pRet;
    }
}



// 2.3 Delete Middle Node
// Implement an algorithm to delete a node in the middle(i.e., any node but
// the first and last node, not necessarily the exact middle) of a singly linked list, 
// given only access to that node.

bool LinkedList::DeleteMiddleNode(Node* pNode)
{
    bool bRet = true;
    if (pNode == nullptr)
    {
        bRet = false;
    }
    else
    {
        pNode->pNext->nData = pNode->nData;
        Node* pTemp = pNode->pNext;
        pNode->pNext = pNode->pNext->pNext;
        delete pTemp;
        m_nLength--;
    }
    return bRet;
}

// 2.5 Sum list
// You have two numbers represented by a linked list, where each node contains a single
// digit.The digits are stored in reverse order, such that the 1 's digit is at the head 
// of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Node* LinkedList::SumList(Node* ptrNode1, Node* ptrNode2, int carry)
{
    Node* pRet = nullptr;

    if (ptrNode1 == nullptr && ptrNode2 == nullptr && carry == 0)
    {
        return nullptr;
    }
    else
    {
        Node* pNewNode = new Node;
        int value = carry;
        if (ptrNode1 != nullptr)
        {
            value += ptrNode1->nData;
        }
        if (ptrNode1 != nullptr)
        {
            value += ptrNode2->nData;
        }
        pNewNode->nData = value % 10;
        

        // Recursive
        if (ptrNode1 != nullptr || ptrNode2 != nullptr)
        {
            pRet = SumList(ptrNode1 == nullptr ? nullptr : ptrNode1->pNext,
                ptrNode2 == nullptr ? nullptr : ptrNode2->pNext,
                value >= 10 ? 1 : 0);
            pNewNode->pNext = pRet;
        }

    }
    return pRet;
}

// 2.6 Palindrome: Implement a function to check if a linked list is a palindrome.
// Sol 1: Using buffer memory: array
bool LinkedList::IsLinkedListPalindrome()
{
    bool bRet = true;
    Node* pTemp = m_pHead;
    std::vector<int> vecData;
    while (pTemp != nullptr)
    {
        vecData.push_back(pTemp->nData);
        pTemp = pTemp->pNext;
    }

    if (!vecData.empty())
    {
        // Check palindrome
        int iSize = vecData.size();
        for (int i = 0; i < iSize/2; i++)
        {
            if (vecData.at(i) != vecData.at(iSize - i - 1))
            {
                bRet = false;
                break;
            }
        }
    }
    else
    {
        bRet = false;
    }
    return bRet;
}

// Sol 2: Using stack:
// push the first half of the elements onto a stack, depending
// on whether or not we know the size of the linked list.


int main()
{
    LinkedList* pLinkedList = new LinkedList;

    //1,2,3,3,4,4,5
    pLinkedList->AppendNode(5);
    pLinkedList->AppendNode(4);
    pLinkedList->AppendNode(4);

    pLinkedList->AppendNode(3);
    pLinkedList->AppendNode(3);
    pLinkedList->AppendNode(2);
    pLinkedList->AppendNode(1);

    //pLinkedList->DeleteNodesByValue(6);
    //pLinkedList->RemoveDuplicate();
    pLinkedList->RemoveDuplicateSorted();

    pLinkedList->Print();

    std::cout << pLinkedList->GetLength();

    return 0;
}
