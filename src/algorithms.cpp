#include "algorithms.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <utility>
#include <climits>

using namespace std;

typedef pair<double, string> pq_pair;
// BFS algorithm
/* reference: https://www.programiz.com/dsa/graph-bfs
              https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-with-ordering-by-first-and-second-element/
*/

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
        //std::cout << "Visited " <<count++<<":"<< currVertex << " " <<endl;;
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

void findMinDistance(string startVertex, string endVertex){
    double min_distance = dijkstra(startVertex, endVertex).first;
    vector<string> path = dijkstra(startVertex, endVertex).second;
    if (min_distance == INT_MAX) {//if min_distance has not been updated, then the endVertex is not reachable
        cout<<"destinatin airport not reachable"<<endl;
        return;
    } else if (min_distance == -1) {
        cout<<"startVertex is invalid"<<endl;
        return;
    } else if (min_distance == -2) {
        cout<<"endVertex is invalid"<<endl;
        return;
    }
    reverse(path.begin(), path.end());

    //print results
    cout<<"The distance between source airport "<<startVertex<<" and "<<
    "destination airport "<<endVertex<<" is: "<<min_distance<<" km"<<endl;
    cout<<"The optimal path from "<<startVertex<<" to "<<endVertex<<" is: ";
    int i = 0;
    for (; i < path.size() - 1; i++) {
        cout<<path[i]<<", ";
    }
    cout<<path[i]<<endl;
}

pair<double, vector<string> > dijkstra(string startVertex, string endVertex) {
    map<string, pair<vector<string>, vector<double> > > routes_data = read_routes();
    map<string, pair<vector<string>, vector<double> > >::iterator it;
    priority_queue<pq_pair, vector<pq_pair>, greater<pq_pair> > pq;
    map<string, bool> visited;
    map<string, double> distance;//maps a airport ID to its distance from the starting vertex
    map<string, string> parent;

    // deal with invalid inputs
    if (routes_data.find(startVertex) == routes_data.end()) {
        return make_pair(-1, vector<string> ());
    }
    if (routes_data.find(endVertex) == routes_data.end()) {
        return make_pair(-2, vector<string> ());
    }

    //initialize the visited, distance, and parent maps
    cout<<"dijkstra initialization started" <<endl;
    for (it = routes_data.begin(); it != routes_data.end(); it++) {
        for (int i = 0; i < it->second.first.size(); i++) {  
            string curr_key = (it->second.first)[i];
            parent[curr_key] = "NULL";
            visited[curr_key] = false;
            distance[curr_key] = INT_MAX;
        }
    }
    cout<<"dijkstra initialization complete"<<endl;

    distance[startVertex] = 0;
    pq.push(make_pair(0.0, startVertex));
    cout<<"pq traversal start"<<endl;
    while(!pq.empty()) {
        string curr_node = pq.top().second;
        double minDist = pq.top().first;
        visited[curr_node] = true;

        for (int i = 0; i < routes_data[curr_node].first.size(); i++) {
            string edge_node = routes_data[curr_node].first[i];
            double edge_length = routes_data[curr_node].second[i];
            
            if (visited[edge_node]) {
                continue;
            }
            double new_distance = distance[curr_node] + edge_length;
            if (new_distance < distance[edge_node]) {
                distance[edge_node] = new_distance;
                parent[edge_node] = curr_node;
                pq.push(make_pair(edge_length, edge_node));
            }
        }
        pq.pop();
    }

    // store the path into a string vector
    string curr_airport = endVertex;
    vector<string> path;
    path.push_back(endVertex);
    while (curr_airport != startVertex) {
        curr_airport = parent[curr_airport];
        path.push_back(curr_airport);
    }
    return make_pair(distance[endVertex], path);
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