// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

// 1.1 - Is Unique
// Implement an algorithm to determine if a string has all unique chareacter.
// What if you can not use additional data structures?

bool IsUnique(std::string& strInput)
{
    bool bRet = true;

    // The below solution use a data structure which is map <key, value>
    // Key: character in string input
    // Value: the number of apprearance of each character in string input
    std::map<char, int> mapInput;

    for (int nIdx = 0; nIdx < strInput.length(); ++nIdx)
    {
        if (mapInput.find(strInput[nIdx]) == mapInput.end())
        {
            mapInput.insert(std::make_pair(strInput[nIdx], 1));
        }
        else
        {
            mapInput[strInput[nIdx]]++;
        }
    }

    // If value > 1 => character is not unique
    for (auto elm : mapInput)
    {
        if (elm.second != 1)
        {
            bRet = false;
            break;
        }
    }

    // If we can not use additional data structure, we can do:
    // 1: Compare every character of the string (O (n^2))
    // 2: Sorting first and then check 2 character neighboring

    return bRet;
}

// One solution is to create an array of boolean values, where the flag at index i 
// indicates whether character i in the alphabet is contained in the string.
// The second time you see this character you can immediately return false.
// We can also immediately return false if the string length exceeds the number of 
// unique characters in the alphabet.
// 
// After all, you can't form a string of 280 unique characters out of a 128-character alphabet.
// I It's also okay to assume 256 characters. This would be the case in extended ASCII. You should
// clarify your assumptions with your interviewer.

// We can reduce our space usage by a factor of eight by using a bit vector

bool IsUniqueChars(const std::string& strInput)
{
    int iLength = strInput.length();
    bool bRet = true;

    if (iLength <= 128)
    {
        std::vector<bool> vecChar(128, false);
        for (int i = 0; i < iLength; i++)
        {
            if (vecChar.at(strInput[i]))
            {
                bRet = false;
                break;
            }
            vecChar.at(strInput[i]) = true;
        }
    }
    else
    {
        bRet = false;
    }
    return bRet;
}



// 1.2 - Check Permutation
//  Given 2 strings, write a method to decide if one is a permutation of the other
// #1: Sort string
// #2: Check if the two strings have identical character counts.

// #2
// Definition of a permutation - two words with the same character counts.
// Iterate through this code, counting how many times each character appears.
// Then, afterwards, compare the two arrays.

bool IsPermutation(std::string& strInput1, std::string& strInput2)
{
    bool bRet = true;
    int nLength1 = strInput1.length();
    int nLength2 = strInput2.length();
    if (nLength1 == nLength2)
    {
        std::vector<int> vecChar(128, 0);

        for (int nIdx = 0; nIdx < nLength1; ++nIdx)
        {
            vecChar[strInput1[nIdx]]++;
        }

        for (int nIdx = 0; nIdx < nLength2; ++nIdx)
        {
            int nCount = vecChar[strInput2[nIdx]]--;
            if (nCount < 0)
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

// Palindrome Permutation : Given a string, write a function to check if it is a permutation of
// a palindrome.A palindrome is a word or phrase that is the same forwards and backwards.A
// permutation is a rearrangement of letters.The palindrome does not need to be limited to just
// dictionary words.
// EXAMPLE
// Input : Tact Coa
// Output : True(permutations : "taco cat'; "atc o eta·; etc.)

// 1.5 - One Away
// There are three types of edits that can be performed on strings: insert, remove 
// and replace a character. Given 2 strings, write a function to check if they are
// one edit away

// # Solution 1: brute force algorithm: check all possible strings that are one edit 
// away by testing the removal, replacement, insertiion of aech character.
// => not efficent

// # Solution 2: compare each character and ensure that the strings are only different one.

bool OneEditAway(std::string& strInput1, std::string& strInput2)
{
    bool bRet = false;
    int nLength1 = strInput1.length();
    int nLength2 = strInput2.length();

    // The length difference between 2 strings not be more than 1
    // The string is same, number of different char <= 1
    // The string is different (insert, remove), the number different <= 1

    if (std::abs(nLength1 - nLength2) <= 1)
    {
        int nIdx1 = 0; // Start index for strInput1
        int nIdx2 = 0; // Start index for strInput2
        int nDiffChar = 0; // The number of char different between 2 strings

        while ((nIdx1 < nLength1) && (nIdx2 < nLength2))
        {
            if (strInput1.at(nIdx1) != strInput1.at(nIdx2))
            {
                nDiffChar++;
                if (nLength1 == nLength2)
                {
                    nIdx1++;
                    nIdx2++;
                }
                else if (nLength1 > nLength2)
                {
                    nIdx1++;
                }
                else if (nLength1 < nLength2)
                {
                    nIdx2++;
                }
                else
                {
                    // do nothing
                }
            }
            else
            {
                nIdx1++;
                nIdx2++;
            }
        }
        if (nDiffChar <= 1)
        {
            bRet = true;
        }
        else
        {
            bRet = false;
        }
    }
    else
    {
        // do nothing
    }
    return bRet;
}

// 1.7 Rotate Matrix
// Given an image represented NxN matrix, where each pixel in the image
// is 4 bytes, write a method to rotate the image by 90 degress. Can you do this in place?

// Example:
// 1 2 3      7 4 1
// 4 5 6 = >  8 5 2
// 7 8 9      9 6 3

// #Solution1:O(n^2)
// Row => Column and Column => Row
void RotateMatrix(int** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[j][n - 1 - i] = arr[i][j];
        }
    }
}

// #Solution2:O(n^2)
// Transpose matrix
//void RotateMatrix(int** arr, int n)
//{
//    // Transpose
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            int nTemp = arr[i][j];
//            arr[i][j] = arr[j][i];
//            arr[j][i] = nTemp;
//        }
//    }
//
//    // Reverse
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n/2; j++)
//        {
//            int nTemp = arr[i][j];
//            arr[i][j] = arr[i][n - 1 - j];
//            arr[i][n - 1 - j] = nTemp;
//        }
//    }
//}


// Dynamic programming

int LongestCommonSubsequent(std::string strInput1, std::string strInput2)
{
    int iIdx = 0;
    int jIdx = 0;

    int arrLCS[13][11];

    for (int iIdx = 0; iIdx <= 12; iIdx++)
    {
        arrLCS[iIdx][0] = 0;
    }

    for (int jIdx = 0; jIdx <= 10; jIdx++)
    {
        arrLCS[0][jIdx] = 0;
    }

    for (int iIdx = 1; iIdx <= 12; iIdx++)
    {
        for (int jIdx = 1; jIdx <= 10; jIdx++)
        {
            if (strInput1[iIdx - 1] == strInput2[jIdx - 1])
            {
                arrLCS[iIdx][jIdx] = 1 + arrLCS[iIdx - 1][jIdx - 1];
            }
            else
            {
                arrLCS[iIdx][jIdx] = std::max(arrLCS[iIdx - 1][jIdx], arrLCS[iIdx][jIdx - 1]);
            }
        }
    }
    
    return arrLCS[12][10];
}


int BruteForceMatch(const std::string& strT, const std::string& strP)
{
    int n = strT.size();
    int m = strP.size();

    for (int i = 0; i <= (n - m); i++)
    {
        int j = 0;
        while (j < m && strT[i + j] == strP[j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return 0;
}


int Fibonaci(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return Fibonaci(n - 1) + Fibonaci(n - 2);
    }
}

//// Dynamic Programming : Top-down with Memoization
//std::vector<int> vecMemoize(10, 0);
//
//int Fibonaci(int n)
//{
//    if (n < 2)
//    {
//        return n;
//    }
//    else
//    {
//        if (vecMemoize[n] != 0)
//        {
//            return vecMemoize[n];
//        }
//        vecMemoize[n] = Fibonaci(n - 1) + Fibonaci(n - 2);
//        return vecMemoize[n];
//    }
//}

// Bottom - up with Tabulation
//// Avoid recursion
//int Fibonaci(int n)
//{
//    std::vector<int> dp(n + 1);
//    dp[0] = 0;
//    dp[1] = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        dp[i] = dp[i - 1] + dp[i - 2];
//
//    }
//}





// Given the weights and profits of ‘N’ items, we are asked to put these items 
// in a knapsack that has a capacity ‘C’.
// The goal is to get the maximum profit from the items in the knapsack.




int main()
{
    std::string strTest1 = "hung";
    std::string strTest2 = "aaaa";
    //bool bCheck = IsUnique(strTest);
    //bool bCheck = IsPermutation(strTest1, strTest2);
    std::vector<int> vec = { 1,2,3, 4, 5, 6 };
    bool bCheck = IsUniqueChars(strTest2);
    std::cout << bCheck;

    return 0;
}