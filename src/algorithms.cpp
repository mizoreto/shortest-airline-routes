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


    std::map<string, pair<vector<string>, vector<double> > > routes_data = read_routes();
    std::pair<vector<string>, vector<double> > airports_pair = routes_data[startVertex];

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
    int count = 0;
    while (!q.empty()) {
        string currVertex = q.front();
        std::cout << "Visited " <<count++<<":"<< currVertex << " " <<endl;;
        q.pop();

        for (int i = 0; i < airports.size(); ++i) {
            
            if (!visited[airports[i]]) {
                visited[airports[i]] = true;
                q.push(airports[i]);
            }
        }

        // update the airports vector, so that it continues to traverse all the other airports.
        airports = routes_data[q.front()].first;

    }
}

void addDegreeToAirport(map<string, Airports::airport*> airports, map<string, pair<vector<string>, vector<double> > > routes) {
    if (airports.empty() || routes.empty()) {
        cout << "airports has size " << airports.size() << ", routes has size " << routes.size() << endl;
        return;
    }
    for (map<string, Airports::airport*>::iterator it = airports.begin(); it != airports.end(); ++it) //add degree to every airport.
        it->second->degree = routes[it->second->ID].first.size();
}

string mostCentralAirport(map<string, Airports::airport*> airports) {
    Airports::airport* currMax = new Airports::airport("Default", -1, -1, -1);
    Airports::airport* currMaxSaver = currMax;
    for (map<string, Airports::airport*>::iterator it = airports.begin(); it != airports.end(); ++it) {//check for max centrality at every airport.
        if (currMax->degree <= it->second->degree) currMax = it->second;
        else continue;
    }
    if (currMax == NULL) {
        cout << "Error: Something went wrong, degree centrality failed." << endl;
        return "";
    }
    //Give results.
    cout << "Task Complete: Degree Centrality completed." << endl;
    cout << "Airport with most flights is " << currMax->ID << ", it has a degree of " << currMax->degree << endl;
    delete currMaxSaver;
    return currMax->ID;
}