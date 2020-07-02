// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HashTable.h"

void FindMaxMin(int A[], int i, int j, int& max, int& min)
{
    if (i = j)
    {
        max = min = A[i];
    }
    else if (i == j - 1)
    {
        if (A[i] < A[j])
        {
            max = A[j];
            min = A[i];
        }
        else
        {
            max = A[i];
            min = A[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1, max2;
        int min1, min2;
        FindMaxMin(A, i, mid, max1, min1);
        FindMaxMin(A, mid + 1, j, max2, min2);
        max = (max2 > max1) ? max2 : max1;
        min = (min2 < min1) ? min2 : min1;
    }
}

int main()
{
    //int max, min;
    //int A[6] = { 1, 2, 3, 4, 5, 6 };
    //FindMaxMin(A, 0, 5, max, min);
    //std::cout << "Hello World!\n" << max << std::endl;
    //std::cout << "Hello World!\n" << min << std::endl;

    // Find the first non repeated character
    std::string str = "Nguyen Van Hung";
    HashTable hashTable;
    for (int i = 0; i < str.length(); i++)
    {
        hashTable.insert(str[i]);
    }
    char c = hashTable.firstNonRepeat();
    std::cout << "Hello World!\n" << c << std::endl;
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
