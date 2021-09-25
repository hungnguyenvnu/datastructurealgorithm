```
#include <iostream>

// Binary search
bool BinarySearch(int* A, int nLow, int nHigh, int nTarget)
{
    int nMid = (low + nHigh) / 2;
    
    if (A[nMid] == nTarget)
    {
        return true;
    }
    else if (nTarget > A[Mid])
    {
        return BinarySearch(A, nMid + 1, nHigh, nTarget);
    }
    else if (nTarget < A[Mid])
    {
        return BinarySearch(A, 0, nMid, nTarget);
    }
    else
    {
        return false;
    }
}

int main()
{
  return 0;
}
```
