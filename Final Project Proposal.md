# Final Project Proposal
## I. Leading Question - 
### What is the shortest, or most preferred route between two airports?
## II. Dataset Acquisition - 
We are planning to use the data provided by openflights.org for this project. We will be focusing on the airport portion of the dataset as our leading question is to find the optimal route between two airports. This portion of the dataset contains airport ID, name, city, latitude, longitude, and altitude. Which will be helpful for us to draw a conclusion. We will store the data in .csv format, and we may need to convert the data’s format. We will delete or ignore data error, outlier, unwanted data, or missing data before applying the algorithms. We will treat each airport as a vertex on the graph, and each flight as an edge connecting two airports. 

https://openflights.org/data.html
## III. Graph Algorithms -
  1. We will be using Breadth First Traversal (BFS) for this project to traverse through the graph that we have created using the data set. Given a starting location, we would use BFS to traverse all airports that are within the same connected component as the starting airport, with commercial flights connecting them.
  2. The first algorithm we will be using is Dijkstra’s Algorithm. Which has a worst case runtime of Ө(|E| + |V| log|V|), where E is the number of edges, and V is the number of vertices. The Dijkstra’s Algorithm will take two inputs: the graph instance created by the graph constructor and the ID of the airport that we choose to be our starting point of our search. The function will return two vector containers: one of them will store the calculated distance from the starting airport the the other nodes; the other will store the pointers of the node that the traversal has visited on the same path.
  3. The second algorithm that we will be using is the Degree Centrality algorithm. This algorithm counts the number of incoming and outgoing relationships at a node, and in our case, it can be used to find the most popular/ busiest airports in the world. The runtime for Degree Centrality to be performed on all nodes in a graph is Ө(V^2), where V is the number of vertices. This algorithm will receive all airports and flights as its input, and return the sum of flights available at every inputted airport. We can then make use of this result to determine which airport(s) are most connected and therfore most popular.

## IV. Timeline -

  * Nov 7 start and finish the Team Contract, get started on Proposal
  * Nov 8 finish the project proposal, and submit it.
  * Nov 9-14  finish constructing the overall structure of the program
  * Nov 15-18 finish the readFromFile function
  * Nov 18-21 finish writing the file and comment.
  * Nov 22-25 finish the graph class
  * Nov 25-28 Implement the algorithm to find the optimal distance
  * Nov 29 mid project checkin
  * Nov 30 - Dec 5 finish writing the test cases for the program and debug
  * Dec 6-13 Summing conclusions and preparing for the video description of the project.

