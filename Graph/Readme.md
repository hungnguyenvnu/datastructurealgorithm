
# Graph

* A graph is a way of representing relationships that exist between pairs of objects.
    - A graph is a set of objects, called vertices, together with a collection of pairwise connections between them. 
    
    - Graphs have applications in a host of different domains, including mapping, transportation, electrical engineering, and computer networks.

* A graph G is simply a set V of vertices and a collection E of pairs of vertices from V , called edges.

    * A graph is a way of representing connections or relationships between pairs of objects from some set V.
    
    * "vertices" and “edges.” Edges in a graph are either directed or undirected. 
        * An edge (u, v) is said to be **directed** from u to v if the pair (u, v) is ordered, with u preceding v. 
        * An edge (u, v) is said to be **undirected** if the pair (u, v) is not ordered. (u, v), noting that in the undirected case (u, v) is the same as (v , u). 
        * Example:
            * Visualize collaborations among the researchers of a certain discipline by constructing a graph 

![image](https://user-images.githubusercontent.com/37680071/133873562-69af7b07-3981-47d1-9838-1d996b9d6f65.png)


 * If all the edges in a graph are undirected, then we say the graph is an undirected graph. A directed graph, also called a digraph, is a graph whose edges are all directed

# Data Structure for Graph

## Edge list structures

* A vertex v of G storing an element x is explicitly represented by a vertex object. 
   
* Vertex Objects
    - element
    - reference to position in vertex sequence

* Edge object
    * element
    * origin vertex object
    * destination vertex object
    * reference to position in dge sequence
    
* Vertex sequence
    * sequence of vertex objects
    
* Edge sequence
    * sequence of edge objects

![image](https://user-images.githubusercontent.com/37680071/133877779-b9600392-a835-4e8f-afe2-d180062ef106.png)


## Adjacency list structures

* Adjacency list structure for a graph G adds extra information to the edge list structure that supports direct access to the incident edges (and thus to the adjacent vertices) of each vertex.
    
* Adjacency list structure includes all the structural components of the edge list structure plus the following:

    * A vertex object v holds a reference to a collection I (v), called the incidence collection of v, whose elements store references to the edges incident on v.
    * The edge object for an edge e with end vertices v and w holds references to the positions (or entries) associated with edge e in the incidence collections I (v) and I (w)

![image](https://user-images.githubusercontent.com/37680071/133879879-69e03db4-b122-4610-b92a-635f8777724a.png)


## Adjacency matrix structures

* The adjacency matrix structure of a graph also extends the edge list structure with an additional component. 
    * The edge list with a matrix (a two-dimensional array) A that allows us to determine adjacencies between pairs of vertices in constant time. 
    * In the adjacency matrix representation, we think of the vertices as being the integers in the set {0, 1,..., n − 1} and the edges as being pairs of such integers.
    * Adjacency matrix representation extends the edge list structure as follows :
        * A vertex object v stores a distinct integer i in the range 0, 1,..., n − 1, called the index of v.
        * We keep a two-dimensional n × n array A such that the cell A[i, j] holds a reference to the edge (v , w), if it exists, where v is the vertex with index i and w is the vertex with index j. If there is no such edge, then A[i, j] = null.

# Graph Traversals

##  Depth-First Search

* Using Stack

## Breadth First Search

* Using Queue

![image](https://user-images.githubusercontent.com/37680071/133880506-f96a005c-020c-45bb-bf65-7108dc3c4402.png)


# References

[1]  https://uet.vnu.edu.vn/~chauttm/dsa2012w/slides/Lec08_Graph.pdf
