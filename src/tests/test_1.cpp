#include "../algorithms.h"
#include "../algorithms.cpp"
#include "../read_routes.h"
#include "../read_routes.cpp"
#include "../read_airport.h"
#include "../read_airport.cpp"
#include "../catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ARC, 40.1013125, -88.2381926
// UGL, 40.1046698, -88.2290223
// WAL, 40.146127, -88.255618
// SAN, 37.2965314, -122.0976163
// PEK, 40.0798573, 116.6009234

// ,,UGL,,ARC,,,,
// ,,UGL,,PEK,,,,
// ,,UGL,,WAL,,,,
// ,,PEK,,UGL,,,,
// ,,SAN,,PEK,,,,

// pair<double, vector<string> > dijkstra(string startVertex, 
//             string endVertex, map<string, pair<vector<string>, vector<double> > > routes_data);


TEST_CASE("Test Dijkstra") {
    Airports test_airports;
    routes test_routes;
    test_routes.routes_map["A"].first.push_back("B");
    test_routes.routes_map["A"].second.push_back(1);

    test_routes.routes_map["A"].first.push_back("C");
    test_routes.routes_map["A"].second.push_back(3);

    test_routes.routes_map["B"].first.push_back("A");
    test_routes.routes_map["B"].second.push_back(1);

    test_routes.routes_map["B"].first.push_back("C");
    test_routes.routes_map["B"].second.push_back(5);

    test_routes.routes_map["B"].first.push_back("D");
    test_routes.routes_map["B"].second.push_back(4);

    test_routes.routes_map["C"].first.push_back("D");
    test_routes.routes_map["C"].second.push_back(4);

    test_routes.routes_map["C"].first.push_back("B");
    test_routes.routes_map["C"].second.push_back(5);

    test_routes.routes_map["C"].first.push_back("A");
    test_routes.routes_map["C"].second.push_back(3);

    test_routes.routes_map["D"].first.push_back("C");
    test_routes.routes_map["D"].second.push_back(4);

    test_routes.routes_map["D"].first.push_back("B");
    test_routes.routes_map["D"].second.push_back(4);

    REQUIRE(dijkstra("A", "C", test_routes.routes_map).first == 3.0);
    REQUIRE(dijkstra("B", "C", test_routes.routes_map).first == 4.0);
}

TEST_CASE("Test Read Airport") {
    Airports test_airports;
    routes test_routes;
    test_airports.readCleanData("test_latlon.dat");
    test_routes.routes::read_routes("test_routes.dat");
    REQUIRE(test_airports.airports["UGL"]->lat == 40.1046698);
    REQUIRE(test_airports.airports["UGL"]->lon == -88.2290223);
}

//TEST_CASE("Test Read Routes")