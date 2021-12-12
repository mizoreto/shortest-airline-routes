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

pair<map<string, string>, map<string, double> > BFS(std::string startVertex) {
    map<string, pair<vector<string>, vector<double> > > routes_data = read_routes();
    map<string, pair<vector<string>, vector<double> > >::iterator it;
    priority_queue<pq_pair, vector<pq_pair>, greater<pq_pair> > pq;
    map<string, bool> visited;
    map<string, double> distance;//maps a airport ID to its distance from the starting vertex
    map<string, string> parent;
    //initialize the visited, distance, and parent maps
    for (it = routes_data.begin(); it != routes_data.end(); it++) {
        for (int i = 0; i < it->second.first.size(); i++) {  
            string curr_key = (it->second.first)[i];
            parent[curr_key] = "NULL";
            visited[curr_key] = false;
            distance[curr_key] = INT_MAX;
        }
    }
    distance[startVertex] = 0;
    pq.push(make_pair(0.0, startVertex));
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
    return make_pair(parent, distance);
} 

void findMinDistance(string startVertex, string endVertex){
    pair<double, vector<string> > dijkstra_pair = dijkstra(startVertex, endVertex);
    double min_distance = dijkstra_pair.first;
    vector<string> path = dijkstra_pair.second;
    if (min_distance == INT_MAX) {
        //if min_distance has not been updated, then that means the endVertex is not reachable
        cout<<"destinatin airport not reachable"<<endl;
        return;
    } else if (min_distance == -1) {
        cout<<"starting point input is invalid"<<endl;
        return;
    } else if (min_distance == -2) {
        cout<<"end point input is invalid"<<endl;
        return;
    }
    reverse(path.begin(), path.end());

    //print results
    cout<<"The shortest distance between source airport "<<startVertex<<" and "<<
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
    cout<<"Looking for shortest path..."<<endl;
    pair<map<string, string>, map<string, double> > result_pair = BFS(startVertex);
    map<string, double> distance = result_pair.second;
    map<string, string> parent = result_pair.first;

    // deal with invalid inputs
    if (routes_data.find(startVertex) == routes_data.end()) {
        return make_pair(-1, vector<string> ());
    }
    if (routes_data.find(endVertex) == routes_data.end()) {
        return make_pair(-2, vector<string> ());
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