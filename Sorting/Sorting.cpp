// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int partition(int A[], int x, int y)
{
    int pivot = A[x];
    int left = x + 1;
    int right = y;
    while (left <= right)
    {
        while (A[left] < pivot && left <= right)
        {
            left++;
        }
        while (A[right] >= pivot && left <= right)
        {
            right--;
        }
        if (left < right)
        {
            std::swap(A[left], A[right]);
            left++;
            right--;
        }
    }
    std::swap(A[x], A[right]);
    return right;
}

void quickSort(int A[], int x, int y)
{
    if (x < y)
    {
        int r = partition(A, x, y);
        quickSort(A, x, r - 1);
        quickSort(A, r + 1, y);
    }
}

int main()
{
    const int SIZE = 20000;
    int _array[SIZE];
    int k = rand() % SIZE + 1;
    memset(_array, 0, sizeof(_array));

    for (int i = 0; i < SIZE; i++) _array[i] = rand() % 100;
    quickSort(_array, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", _array[i]);
    }
    std::cout << "Hello World!\n";
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
