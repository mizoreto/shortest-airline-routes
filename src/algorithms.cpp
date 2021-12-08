#include "algorithms.h"


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



void BFS(string startVertex) {
    // using the map to get all airports
    // that are within the same connected component as the starting airport

    pair<vector<string>, vector<double>> airports_pair = result_routes.get(startVertex);

    vector<string> airports = airports_pair.first;


    // bool[] visited = new bool[airports.size()];
    // for (int i = 0; i < airports.size(); i++)
    //     visited[i] = false;

    queue<string> queue;

    queue.push_back(startVertex);

    for (int i = 0; i < airports.size(); ++i) {
            
        queue.push_back(airports[i]);
    }


    // while (!queue.empty()) {
    //     int currVertex = queue.front();
    //     cout << "Visited " << currVertex << " ";
    //     queue.pop_front();

    //     for (int i = 0; i < airports.size(); ++i) {
            
    //         if (!visited[i]) {
    //             visited[i] = true;
    //             queue.push_back(airports[i]);
    //         }
    //     }
    // }
}