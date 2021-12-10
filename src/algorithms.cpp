#include "algorithms.h"
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <iterator>

//#define INF INT_MAX

using namespace std;
// BFS algorithm
// reference: https://www.programiz.com/dsa/graph-bfs

void BFS(std::string startVertex) {
    // using the map to get all airports
    // that are within the same connected component as the starting airport
    std::map<string, pair<vector<string>, vector<double> > > routes_data = read_routes();
    std::pair<vector<string>, vector<double> > airports_pair = routes_data[startVertex];
    vector<string> airports = airports_pair.first;
    // used to keep track of whether an airport is visited
    std::map<string, bool> visited;
    std::queue<string> q;
    visited[startVertex] = true;
    q.push(startVertex);
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

// int minDistance(string currAirport, double currDistance,map<string, double> distance, map<string, string> parent) {
//     string parentAirport = parent[currAirport];
    
// }

// void dijkstra(string startVertex, string endVertex) {
//     map<string, pair<vector<string>, vector<double> > > routes_data = read_routes();
//     map<string, pair<vector<string>, vector<double> > >::iterator routes_it;
//     map<string, bool> visited;
//     map<string, double> distance;
//     map<string, string> parent;
//     queue<string> queue;
//     //initialize the visited, distance, and parent maps
//     for (routes_it = routes_data.begin(); routes_it != routes_data.end(); routes_it++) {
//         string curr_key = routes_it->first;
//         visited[curr_key] = false;
//         distance[curr_key] = INF;
//         parent[curr_key] = "NULL";
//     }
//     visited[startVertex] = true;
//     distance[startVertex] = 0;
//     parent[startVertex] = "/";
//     queue.push(startVertex);
//     for(routes_it = routes_data.begin(); routes_it != routes_data.end(); routes_it++) {
//         string curr_key = queue.front();
//         visited[curr_key] = true;
//         vector<double> currDistSet = routes_data[curr_key]->second;
//         vector<string> currDestSet = routes_data[curr_key]->first;
//         vector<double> temp_distance;
//         for (int i = 0; i < currDestSet.size(); i++) {
//             string curr_dest = currDestSet[i];
//             double curr_dist = currDistSet[i];
//             if (!visited[curr_dest]) {

//             }
//         }
//             visited[curr_key] = true;
        
//     }
// }   