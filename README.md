# Graph problems, shortest paths

In this assignment, we will implement two distinct algorithms for computing the shortest paths between all possible pairs of nodes in a graph

All the information you need regarding these two data structures can be found in your textbook (Algorithm Analysis and Design, Chapter 14).

### Step 1 - Implementing the graph

We will implement the graph by simply using an adjacency matrix. In the file Graph.h you are already provided with a structure for the class Graph and the actual implementation of the Matrix (a simple vector of vectors).

The constructor of the Graph takes in input two integers indicating the number of nodes and number of arcs.
The construct randomly generates a representation for the weighted graph.

You have to implement the other functions listed in Graph.h

Keep your code simple.
There is no need for additional files so you can implement everything inline. You should be able to compile your code using the following `g++ Time.cpp main.cpp -o main`.
You are not allowed to reuse code from other classes. Integrate your code into the current structure.

### Step 2 - Implementing the Dijkstra’s Algorithm

The algorithmic description of Dijkstra’s Algorithm can be found in your textbook. A few tips:

- Use `MAX` to represent the maximum distance between two nodes instead of infinite (I have already defined MAX for you).
- You can use the priority queue provided by the standard. Use the following code for defining the queue.

  `priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> >> q;`

  With this, you are declaring a priority queue of pairs of integers. Practically, each element in the queue will be a pair of integers (`pair<int,int>,`) and you are creating a vector of pairs (`vector<pair<int,int> >,`). Moreover, the elements will be sorted in ascending order (`greater<pair<int,int> >`).

- By default, if you provide a pair to the priority queue, the first element of the pair will be used for ordering the elements. If you look at Dijkstra’s Algorithm, we want the elements in the queue to be sorted according to their distance from the source. This means that, for each pair, the first element has to encode the distance of the node from the source while the second element has to store the index of such node in the graph.


### Step 3 - Implementing the computeAllPairsShortestPath function

Once the Dijkstra’s Algorithm is implemented this step will be easy. You just have to call the Dijkstra’s Algorithm using the source each possible node in your graph. Save your results in a Matrix such that, for each pair of indices (i,j), Matrix(i,j) will store the length of the shortest between those two nodes.


### Step 4 BONUS - Implementing the Dynamic Programming Algorithm

Implement the dynamic programming solution for computing all pairs of shortest pairs (Chapter 14.5.1).

Once the algorithms are implemented, evaluate their performances. Test your implementation with different graphs.

- use a simple graph with 10 nodes and 20 arcs
- increment the number of nodes to be lower than the number of arcs (1000, 500)
- increment the number of arcs (1000, 40000)

Open this README file with a normal text editor and report the timings obtained discussing the reason why you obtained each result.

### use a simple graph with 10 nodes and 20 arcs
```
Result: 
    Graph generated 
    Time with Dijkstra's algorithm: 0.000727
    Time with Dynamic programming: 5.1e-05
    They are the same
```
Dynamic programming is over 14 times (7.27e-4/5.1e-05) faster than Dijkstra's algorithm. Dynamic programming is faster in general because it doesn't have to compute the distance for each node everytime like Dijkstra's does. However, Dijkstra's significantly slower given (10, 20) because the more edges there are, the more frequent a vertex is being updated.

### increment the number of nodes to be lower than the number of arcs (1000, 500)
```
Result:
    Graph generated 
    Time with Dijkstra's algorithm: 29.28
    Time with Dynamic programming: 17.6824
    They are the same
```
Dynamic programming is about 1.6 times (29.28/17.6824) faster than Dijkstra's algorithm. This time Dynamic programming didn't get a significant lead because

### increment the number of arcs (1000, 40000)
```
Result:
    Graph generated 
    Time with Dijkstra's algorithm: 198.539
    Time with Dynamic programming: 17.5887
    They are the same
```
Dynamic programming is about 11 times faster than Dijkstra's algorithm.

