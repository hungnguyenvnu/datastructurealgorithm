/*
 * Some example of using bitwise
 *
 *  Created on: July 01, 2020
 *  Author: Hung Le
 */

typedef unsigned long long int LLU;

#include <iostream>

/*
 * Checking x is power of 2 or not
 */

bool isPowerOf2(LLU x)
{
    bool bRet = false;   // Return value
    LLU y = 1;          // Initial value
    for (int nIdx = 0; nIdx <= 63; ++nIdx)
    {
        if (y == x)
        {
            bRet = true;
            break;
        }
        y = 2 * y;
    }
    return bRet;
}

// Check by using bitwise
bool isPowerOf2B(LLU x) 
{
    bool bRet = true;
    if ((x & (x - 1)) == 0) 
    {
        bRet = true;
    }
    else 
    {
        bRet = false;
    }
    return bRet;
}

int main()
{
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
