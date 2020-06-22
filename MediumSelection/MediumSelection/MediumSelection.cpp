// MediumSelection.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
	int i = *a;
	*a = *b;
	*b = i;
}


int partition(int A[], int x, int y)
{
	int pivot = A[x];
	int left = x + 1;
	int right = y;
	while (left < right)
	{
		while (left <= right && A[left] <= pivot)
		{
			left++;
		}
		while (left <= right && A[right] > pivot)
		{
			right--;
		}
		if (left < right)
		{
			std::swap(A[left], A[right]);
		}
	}
	std::swap(A[x], A[right]);
	return right;
}

int quickSelect(int A[], int x, int y, int k)
{
	if (y <= x)
	{
		return A[x];
	}
	else 
	{
		int r = partition(A, x, y);
		if (k < r){
			return quickSelect(A, x, r - 1, k);
		}
		else if (k > r) {
			return quickSelect(A, r + 1, y, k);
		}
		else {
			return A[r];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int SIZE = 10;
	int _array[SIZE] = {1, 10, 5, 4, 6, 3, 9, 8, 7, 2};
	int r = quickSelect(_array, 0, SIZE - 1, 9);
	std::cout << "pos: " << r << "\n";
	return 0;
}

