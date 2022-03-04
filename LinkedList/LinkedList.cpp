// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include "LinkedList.h"


LinkedList::LinkedList() : m_nLength {0}, m_pHead{nullptr}
{
}

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

// Cracking coding interview
// 2.1 - Remove Dups
// Write code to remove duplicated from an unsorted linked list
// Using 2 pointers to traverse list
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
        std::cout << "List empty!";
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
        pCur->pNext = nullptr;
    }
    else
    {
        std::cout << "List empty!";
    }
}

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
