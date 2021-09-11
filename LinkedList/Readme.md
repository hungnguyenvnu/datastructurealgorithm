# Single Linked List

* A linked list is a collection of nodes that together form a linear ordering. Each node stores a pointer, called next, to the next node of the list.

![image](https://user-images.githubusercontent.com/37680071/132821727-9370617b-9e51-4943-b1d5-f967fb0ff2de.png)

* Applications of linked list in computer science

  - Implementation of stacks and queues
  - Implementation of graphs : Adjacency list representation of graphs is most popular which is uses linked list to store adjacent vertices.
  - Dynamic memory allocation : We use linked list of free blocks.
  - Performing arithmetic operations on long integers
  - Manipulation of polynomials by storing constants in the node of linked list representing sparse matrices
  
* Applications of linked list in real world

  - Image viewer – Previous and next images are linked, hence can be accessed by next and previous button.
  - Previous and next page in web browser – We can access previous and next url searched in web browser by pressing back and next button since, they are linked as linked list.
  - Music Player – Songs in music player are linked to previous and next song. you can play songs either from starting or ending of the list.
  
* Difference between Linked List and Array

No | Arrays | Linked List
------------ | ------------ | -------------
Memory Allocation | Stored in a contiguous block of memory | Stored at different memory locations
Size | Specified at the time of declaration and cannot be changed afterward | Added or removed from the linked list
Space utilization | Overall less | Required to store pointers next to nodes
Accessing elements | O(1) |  Traversed from the first element up to the required element
Search options | Linear search and Binary search | Linear search only

* References

[1] https://www.geeksforgeeks.org/applications-of-linked-list-data-structure/

[2] Data Structure and Algorithm in C++, Chapter 3

[3] https://www.educative.io/edpresso/what-are-the-differences-between-arrays-and-linked-lists
