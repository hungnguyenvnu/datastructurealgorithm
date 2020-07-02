// DynamicProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX 1000
int F[MAX];


// Fibonacci sequence
int fibonacci(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Improvement 1
int memorized_fib(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        if (F[n] == 0)
        {
            F[n] = memorized_fib(n - 1) + memorized_fib(n - 2);
        }
        return F[n];
    }
}

// Dynamic programming
int dynamic_fib(int n)
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

int save_mem_fib(int n)
{
    int prev = 0;
    int cur = 1;
    int next;
    for (int i = 2; i <= n; i++)
    {
        next = prev + cur;
        prev = cur;
        cur = next;
    }
    return next;
}


int main()
{
    memset(F, 0, sizeof(F));
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
