#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include "read_routes.h"
#include "read_airport.h"
#include "read_airport.cpp"

using namespace std;
void BFS(std::string startVertex);

/**
 * prints the results of the dijkstra algorithm: the shortest distance between two airports
 * and the optimal path
 * @param string startVertex starting point of the two airports
 * @param string endVertex end points of the two airports
*/

void findMinDistance(string startVertex, string endVertex);

/**
 * returns the pair where the first element is the distance between two designated airports
 * and the second element is a pair representing the optimal path from the source airport to
 * the destination airport
 * @param string startVertex starting point of the two airports
 * @param string endVertex end points of the two airports
 * @return the distance between startVertex and endVertex 
*/

pair<double, vector<string> > dijkstra(string startVertex, string endVertex);


/**
 * Add degrees to airport objects. Needed fo degree centrality algorithm.
 */
void addDegreeToAirport(map<string, Airports::airport*> airports, map<string, pair<vector<string>, vector<double> > > routes);

/**
 * Finds and returns the ID of the airport with the most number of edges.
 */
string mostCentralAirport(map<string, Airports::airport*> airports);