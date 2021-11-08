# Final Project Proposal
## 1. Leading Question - What is the shortest, or most preferred route between two airports?
## 2. Dataset Acquisition - We are planning to use the data provided by openflights.org for this project. We will be focusing on the airport portion of the dataset as our leading question is to find the optimal route between two airports. This portion of the dataset contains airport ID, name, city, latitude, longitude, and altitude. Which will be helpful for us to draw a conclusion. We will store the data in .csv format. We will delete or ignore data error, outlier, unwanted data, or missing data before applying the algorithms.
https://openflights.org/data.html
## 3. Graph Algorithms -
We will be using Breadth First Traversal (BFS) for this project to traverse through the graph that we have created using the data set. 
We will be using Dijkstra’s Algorithm. Which has a worst case runtime of Ө(|E| + |V| log|V|), where E is the number of edges, and V is the number of vertices. The Dijkstra’s Algorithm will take two inputs: the graph instance created by the graph constructor and the ID of the airport that we choose to be our starting point of our search. The function will return two vector containers: one of them will store the calculated distance from the starting airport the the other nodes; the other will store the pointers of the node that the traversal has visited on the same path.
The last algorithm that we will be using is A* search algorithm, this algorithm is extended based on Dijkstra’s Algorithm.
## 4. Timeline
```
Nov 7 start and finish the Team Contract, get started on Proposal
Nov 8 finish the project proposal, and submit it.
Nov 9-14  finish constructing the overall structure of the program
Nov 15-18 finish the readFromFile function
Nov 18-21 finish writing the file and comment.
Nov 22-25 finish the graph class
Nov 25-28 Implement the algorithm to find the optimal distance
Nov 29 mid project checkin
Nov 30 - Dec 5 finish writing the test cases for the program and debug
Dec 6-13 Summing conclusions and preparing for the video description of the project.
```
