# Final Project - Open Flights

## Group Members
- yuhua2
- ziyiw8
- boyangy4
- jiayinm2

## How to Download
Copy the command below to download our program:
```bash
git clone https://github-dev.cs.illinois.edu/cs225-fa21/yuhua2-ziyiw8-boyangy4-jiayinm2
```

## Main Function
Our program utilizes the routes and airports data from Open Flight to find the optimal path between two airports, and the airport that has the most departing flights. The first part, finding the shortest distancs and optimal path between two airports, is primarily accomplished by using Breadth First Search and Dijkstra's algorithm. The second part, finding the airport that has the most departing flights, is accomplished
by using Degree Centrality algorithm.

## How to Compile and Run

All of the code execution and compilation commands must be run in the `src/` directory of the project.

To run this project:

`$ make
$./main`

`g++ -o test main.cpp` -

`./test` -

### Edit Inputs
After the main function is run, it will ask for two inputs: the starting airport and the destinatin airport, each represented by its 3 or 4-letter airport ID (both upper-case or lower case would be acceptable). The terminal would ask for starting airport ID first and then the destination airport ID. Input the desired IDs one at a time, and press "Enter" on the keyboard after each input. The result of the search and calculation will be shown in the terminal after the program received both IDs.

# Directory Structure

`src/` - Contains all relevant source code for the project

`src/read_airport.cpp` - Reads raw data from airports.dat, the file from openflights.org. Linked to `src/read_airport.h`

`src/read_routes.cpp` - Reads routes data from routes.dat. Linked to `src/read_routes.h`

`src/algorithms.cpp` - Contains BFS, Dijkstra's, and the Degree Centrality algorithm. Linked to `src/algorithms.h`

# Test Suite
