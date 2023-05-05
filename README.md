# lemme_in

<h2>Introduction</h2>

**Lemme In** is an university project which goal is to find the quickest way through an anthill. To do so,each single ant need to take the shortest rout(and not necessarily the easiest), whithout walking on its peers, and avoiding traffic jams.  

At the beginning of the game all the ants are in the entrance.  
The goal is to lead them to the exit room, in a minimum amount of laps.  
Each room could contain a single ant at a time (except ##start and ##end which can contain as many as needed).

<h2>Parsing and data structure</h2>
We represent the anthills rooms and relations using an undirected graph represented in an adjacency matrix which is a binary symmetric matrix of size n * n.  

Assuming the graph has $n$ vertices, the time complexity to build such a matrix is $O(n^2)$. The space complexity is also $O(n^2)$. Given a graph, to build the adjacency matrix, we need to create a square $n \times n$ matrix and fill its values with 0 and 1. It costs us $O(n^2)$ space.

To fill every value of the matrix we need to check if there is an edge between every pair $(v_{i}, v_{j})$ of vertices. The amount of such pairs of $n$ given vertices is $\binom{n}{2} = \frac{n \times (n - 1)}{2}$. That is why the time complexity of building the matrix is $O(n^2)$.

The advantage of such representation is that we can check in $O(1)$ time if there exists an edge $e_{ij} = (v_{i}, v_{j})$ by simply checking the value at the $i^{th}$ row and $j^{th}$ column of our matrix, otherwise, using a linkedlist, the query is much computationally expensive.


<h2>Algorithm</h2>

Our approach to solve this project includs a Breadth First Search algorithm over all the rooms in order to know which paths lead from start to end, we then select the shortest one, remove that paths's rooms and query for the next shorter route.  
What follows up is moving each ant for the multiple number of routes we find out, but not before checking the efficiency of doing so due to the number of ants we have to move and the opportunity cost of the lenght of some routes over the shortest ones, even if the traffic is higher, what we prioritize is using the minimum amount of laps.

<h2>Example</h2>

Green for the start, red for the end:  
![image](https://user-images.githubusercontent.com/108436798/236271775-bd5810db-ab0a-4c1d-8a98-4d6cd764f861.png)


With each lap, you can move each ant only once by following a tunnel (if the receiving room is clear).

Input example:  
![image](https://user-images.githubusercontent.com/108436798/236271134-02e12015-218b-481a-b43c-9fd5ed7368ea.png)

Output example out of the map:  
![image](https://user-images.githubusercontent.com/108436798/236270689-4e2db208-b51e-4511-80b6-40522a7310a1.png)
