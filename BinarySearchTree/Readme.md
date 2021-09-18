
# Trees

## Binary Trees

* A binary tree is an ordered tree in which every node has at most two children.
    1. Every node has at most two children.
    2. Each child node is labeled as being either a left child or a right child.
    3. A left child precedes a right child in the ordering of children of a node.

* Example: 
  * Decision trees

![image](https://user-images.githubusercontent.com/37680071/133870681-af31508b-c351-46e9-8a27-f3824fc05615.png)

  * Arithmetic expression
  
![image](https://user-images.githubusercontent.com/37680071/133870704-55b6a416-9b7f-4b7a-930f-71b12f46f708.png)


## Binary Search Trees

* A binary search tree for S is a proper binary tree T such that:
  - Each internal node p of T stores an element of S, denoted with x(p)
  - For each internal node p of T , the elements stored in the left subtree of p are less than or equal to x(p) and the elements stored in the right subtree of p are greater than or equal to x(p)
  - The external nodes of T do not store any element

![image](https://user-images.githubusercontent.com/37680071/133870970-73336fe4-cefe-49e7-b041-7c87bac7a9b7.png)

* Application of BST

  * BSTs are used for indexing and multi-level indexing.
  * They are also helpful to implement various searching algorithms.
  * It is helpful in maintaining a sorted stream of data.
  * TreeMap and TreeSet data structures are internally implemented using self-balancing BSTs

## References

[1] DSA in C++, Chapter 7

[2] https://afteracademy.com/blog/binary-search-tree-introduction-operations-and-applications
