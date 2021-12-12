#include "../algorithms.h"
#include "../read_routes.h"
#include "../read_airport.h"
#include "../read_airport.cpp"
#include "../catch/catch.hpp"

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

TEST_CASE("Test Dijkstra") {
    Airports test_airports;
    routes test_routes;
    Airports::airport ARC("ARC", 40.1013125, -88.2381926, -1);
    Airports::airport UGL("UGL", 40.1046698, -88.2290223, -1);
    Airports::airport WAL("WAL", 40.146127, -88.255618, -1);
    Airports::airport SAN("SAN", 37.2965314, -122.0976163, -1);
    Airports::airport PEK("PEK", 40.0798573, 116.6009234, -1);
    //UGL distance array index 0
    test_routes.routes_map["UGL"].first.push_back("ARC");
    test_routes.routes_map["UGL"].second.push_back(
        test_routes.haversine_dist(40.1046698, -88.2290223, 40.1013125, -88.2381926));
    //UGL distance array index 1
    test_routes.routes_map["UGL"].first.push_back("WAL");
    test_routes.routes_map["UGL"].second.push_back(
        test_routes.haversine_dist(40.1046698, -88.2290223, 40.146127, -88.255618));
    //UGL distance array index 2
    test_routes.routes_map["UGL"].first.push_back("PEK");
    test_routes.routes_map["UGL"].second.push_back(
        test_routes.haversine_dist(40.1046698, -88.2290223, 40.0798573, 116.6009234));
    //PEK distance array index 0
    test_routes.routes_map["PEK"].first.push_back("UGL");
    test_routes.routes_map["PEK"].second.push_back(
        test_routes.haversine_dist(40.0798573, 116.6009234, 40.1046698, -88.2290223));
    //SAN distance array index 0
    test_routes.routes_map["SAN"].first.push_back("PEK");
    test_routes.routes_map["SAN"].second.push_back(
        test_routes.haversine_dist(37.2965314, -122.0976163, 40.0798573, 116.6009234));
    REQUIRE(test_routes.routes_map["UGL"].second[0] < test_routes.routes_map["UGL"].second[2]);
    REQUIRE(test_routes.routes_map["UGL"].second[1] < test_routes.routes_map["UGL"].second[2]);
}



TEST_CASE("Test Read Airport") {
    Airport test_airports;
    routes test_routes;
    test_airports.readCleanData("test_latlon.dat");
    test_routes.read_routes("test_routes.dat");
    REQUIRE(test_airports.airports["UGL"].lat == 40.1046698);
    REQUIRE(test_airports.airports["UGL"].lon == -88.2290223);
}

TEST_CASE("Test Read Routes", )