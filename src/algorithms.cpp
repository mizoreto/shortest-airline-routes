#include "algorithms.h"

#include <iostream>
#include <queue>
#include <string>
#include <map>


// BFS algorithm


// reference: https://www.programiz.com/dsa/graph-bfs


// void Graph::BFS(int startVertex) {
//   visited = new bool[numVertices];
//   for (int i = 0; i < numVertices; i++)
//     visited[i] = false;

//   list<int> queue;

//   visited[startVertex] = true;
//   queue.push_back(startVertex);

//   list<int>::iterator i;

//   while (!queue.empty()) {
//     int currVertex = queue.front();
//     cout << "Visited " << currVertex << " ";
//     queue.pop_front();

//     for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
//       int adjVertex = *i;
//       if (!visited[adjVertex]) {
//         visited[adjVertex] = true;
//         queue.push_back(adjVertex);
//       }
//     }
//   }
// }



void BFS(std::string startVertex) {
    // using the map to get all airports
    // that are within the same connected component as the starting airport

    std::pair<vector<string>, vector<double>> airports_pair = result_routes[startVertex];

    vector<string> airports = airports_pair.first;


    // bool[] visited = new bool[airports.size()];
    // for (int i = 0; i < airports.size(); i++)
    //     visited[i] = false;


    // used to keep track of whether an airport is visited
    std::map<string, bool> visited;

    for (int i = 0; i < airports.size(); i++) {
        visited[airports[i]] = false;
    }

    std::queue<string> q;

    visited[startVertex] = true;
    q.push(startVertex);

    // for (int i = 0; i < airports.size(); ++i) {
            
    //     queue.push_back(airports[i]);
    // }


    // std::map<std::string, bool>::iterator it;

    while (!q.empty()) {
        string currVertex = q.front();
        std::cout << "Visited " << currVertex << " ";
        q.pop();

        for (int i = 0; i < airports.size(); ++i) {
            
            if (!visited[airports[i]]) {
                visited[airports[i]] = true;
                q.push(airports[i]);
            }
        }

    }
}