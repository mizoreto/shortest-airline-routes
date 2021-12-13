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

TEST_CASE("Test Read Airport") {
    Airports test_airports;
    test_airports.readCleanData("tests/test_airports.dat");
    REQUIRE(test_airports.airports["UGL"]->lat == 40.1046698);
    REQUIRE(test_airports.airports["UGL"]->lon == -88.2290223);
}

TEST_CASE("Test Read Routes") {
    Airports test_airports;
    routes test_routes;
    test_routes.routes::read_routes("tests/test_routes.dat", "tests/test_airports.dat");
    map<string, pair<vector<string>, vector<double> > >::iterator it;
    for (it = test_routes.routes_map.begin(); it != test_routes.routes_map.end(); it++) {
        cout<<"key: "<<it->first<<"; dest: "<< it->second.first[0]<<endl;
    }
    REQUIRE(test_routes.routes_map["SAN"].first[0] == "PEK");
    REQUIRE(test_routes.routes_map["SAN"].second[0] ==
            test_routes.haversine_dist(1, 2, 3, 4));
}

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
    REQUIRE(dijkstra("D", "A", test_routes.routes_map).first == 5.0);
}