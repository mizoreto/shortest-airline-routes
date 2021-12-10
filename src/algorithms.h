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
 * Add degrees to airport objects. Needed fo degree centrality algorithm.
 */
void addDegreeToAirport(map<string, Airports::airport*> airports, map<string, pair<vector<string>, vector<double> > > routes);

/**
 * Finds and returns the ID of the airport with the most number of edges.
 */
string mostCentralAirport(map<string, Airports::airport*> airports);