# Recursion

* Recursive algorithm have two case: base cases and recursive cases

![image](https://user-images.githubusercontent.com/37680071/134756989-4c350626-8357-455d-9cae-8df99c2a5d22.png)

## Linear Recursion

* A function is defined so that it makes at most one recursuive call each time it is invoked.
* Useful when we view an algorithmic problem in terms of a first or last element plus a remaining set that has the same structure as the original set

* Example:

```
int LinearSum(int A*, int n)
{
    if (n == 1)
    {
        return A[0];
    }
    else
    {
        return LinearSum(A, n - 1) + A[n - 1];
    }
}
```

```
void ReverseArray(int* A, int i, int j)
{
    if (i < j)
    {
        std::swap(A[i], A[j]);
        ReverseArray(A, i + 1, j - 1);
    }
}
```

* **Defining Problems in Ways that Facilitate Recursion**

  * We can subdivide this problem to define problems that have the same general structure as the original problem

## Binary Recursion

* When an algorithm makes two recursive calls.

![image](https://user-images.githubusercontent.com/37680071/134758032-49ccfcd7-edd2-488d-9319-bb87e950a214.png)

```
int BinarySum(int* A, int i, int n)
{
    if (n == 1)
    {
        return A[i];
    }
    else
    {
        return BinarySum(A, i, n/2) + BinarySum(A, i + n/2, n/2);
    }
}
```
