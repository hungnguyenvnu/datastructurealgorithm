// Revise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "Passenger.h"

void printArray(int** A, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/* Vector */
bool checkNumberDistinct(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (vec.at(j) == vec.at(i)) {
                return false;
            }
        }
    }
    return true;
}

void print(const int &i, const int j = 5) { std::cout << i << " " << j << std::endl; }
void merge(int A[], int a, int c, int b)
{
    int i = a;
    int j = c + 1;
    int k = 0;
    int n = b - a + 1;
    int* pB = new int[n];

    while ((i < c + 1) && (j < b + 1))
    {
        if (A[i] < A[j])
        {
            pB[k] = A[i];
            k++; i++;
        }
        else
        {
            pB[k] = A[j];
            k++; j++;
        }
    }
    while (i < c + 1)
    {
        pB[k] = A[i];
        k++; i++;
    }
    while (j < b + 1)
    {
        pB[k] = A[j];
        k++; j++;
    }
    i = a;
    for (k = 0; k < n; k++)
    {
        A[i] = pB[k];
        i++;
    }
    delete[] pB;
}

void mergeSort(int A[], int a, int b)
{
    if (a < b)
    {
        int c = (a + b) / 2;
        mergeSort(A, a, c);
        mergeSort(A, c + 1, b);
        merge(A, a, c, b);
    }
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void partition(int A[], int a, int b, int& k)
{
    int pivot = A[a];
    int left = a + 1;
    int right = b;
    do
    {
        while ((left <= right) && (A[left] <= pivot))
        {
            left++;
        }
        while ((left <= right) && (A[right] > pivot))
        {
            right--;
        }
        if (left < right)
        {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    } while (left <= right);
    swap(A[a], A[right]);
    k = right;
}

void quickSort(int A[], int a, int b)
{
    if (a < b)
    {
        int k;
        partition(A, a, b, k);
        if (a <= k - 1)
        {
            quickSort(A, a, k - 1);
        }
        if (k + 1 <= b)
        {
            quickSort(A, k + 1, b);
        }
    }
}

int main()
{
    // Merge Sort
    int A[] = { 1, 7, 6, 5, 9, 3, 2, 10 };
    //mergeSort(A, 0, 7);
    quickSort(A, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        std::cout << A[i] << std::endl;
    }
    /*double* p[10];
    for (int i = 0; i < 10; i++) {
        p[i] = new double;
        *p[i] = 0.0;
    }
    for (int i = 0; i < 10; i++) {
        std::cout <<  *p[i] << std::endl;
    }*/
    /*int m;
    int n;
    m = n = 3;
    int **A = new int*[m];
    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
    }*/
    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }
    printArray(A, m, n);
    for (int i = 0; i < n; ++i) {
        delete A[i];
    }
    delete[] A;*/
    /*std::vector<int> vec{ 9, 7, 5, 3, 3 };
    bool a = checkNumberDistinct(vec);
    std::vector<std::vector<int>> v{ { 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 } };
    std::cout << "Hello World! " << a << std::endl; */

   // Passenger p1;
    //p1.print();
    //Passenger p2("John Smith", VEGETARIAN, "293145");
    //p2.print();
    //Passenger p3("Pocahontas", REGULAR);
    //p3.print();
    print(3, 20);

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
