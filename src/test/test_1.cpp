#include "../algorithms.h"
#include "../read_routes.h"
#include "../read_airport.h"

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

//TEST_CASE("test the beijing has greater distance than arc", "[weight=1][part=1]") {
void test_case_1() {
    Airport test_airports;
    routes test_routes;
    airport ARC(ARC, 40.1013125, -88.2381926, -1);
    airport UGL(UGL, 40.1046698, -88.2290223, -1);
    airport WAL(WAL, 40.146127, -88.255618, -1);
    airport SAN(SAN, 37.2965314, -122.0976163, -1);
    airport PEK(PEK, 40.0798573, 116.6009234, -1);
    //UGL distance array index 0
    test_routes.routes_map[UGL].first.push_back("ARC");
    test_routes.routes_map[UGL].second.push_back(
        test_routes.haversine(40.1046698, -88.2290223, 40.1013125, -88.2381926));
    //UGL distance array index 1
    test_routes.routes_map[UGL].first.push_back("WAL");
    test_routes.routes_map[UGL].second.push_back(
        test_routes.haversine(40.1046698, -88.2290223, 40.146127, -88.255618));
    //UGL distance array index 2
    test_routes.routes_map[UGL].first.push_back("PEK");
    test_routes.routes_map[UGL].second.push_back(
        test_routes.haversine(40.1046698, -88.2290223, 40.0798573, 116.6009234));
    //PEK distance array index 0
    test_routes.routes_map[PEK].first.push_back("UGL");
    test_routes.routes_map[PEK].second.push_back(
        test_routes.haversine(40.0798573, 116.6009234, 40.1046698, -88.2290223));
    //SAN distance array index 0
    test_routes.routes_map[SAN].first.push_back("PEK");
    test_routes.routes_map[SAN].second.push_back(
        test_routes.haversine(37.2965314, -122.0976163, 40.0798573, 116.6009234));
    if (dijkstra("UGL", "ARC", test_routes.routes_map).first
        < dijkstra("UGL", "PEK", test_routes.routes_map).first) {
            cout<<"pass_1"<<endl;
    } else {
        cout<<"fail_1"<<" : "<<dijkstra("UGL", "ARC", test_routes.routes_map).first<<endl;
    }
    if (dijkstra("UGL", "ARC", test_routes.routes_map).second == {"UGL", "ARC"}) {
        cout<<"pass_2"<<endl;
    }
    //REQUIRE(test_routes.routes_map[UGL].second[0] < test_routes.routes_map[UGL].second[2]);
    //REQUIRE(test_routes.routes_map[UGL].second[1] < test_routes.routes_map[UGL].second[2]);
}

TEST_CASE("test the beijing has greater distance than arc", "[weight=1][part=1]") {
    Airport test_airports;
    routes test_routes;
    airport ARC(ARC, 40.1013125, -88.2381926, -1);
    airport UGL(UGL, 40.1046698, -88.2290223, -1);
    airport WAL(WAL, 40.146127, -88.255618, -1);
    airport SAN(SAN, 37.2965314, -122.0976163, -1);
    airport PEK(PEK, 40.0798573, 116.6009234, -1);
    //UGL distance array index 0
    test_routes.routes_map[UGL].first.push_back("ARC");
    test_routes.routes_map[UGL].second.push_back(
        test_routes.haversine(40.1046698, -88.2290223, 40.1013125, -88.2381926));
    //UGL distance array index 1
    test_routes.routes_map[UGL].first.push_back("WAL");
    test_routes.routes_map[UGL].second.push_back(
        test_routes.haversine(40.1046698, -88.2290223, 40.146127, -88.255618));
    //UGL distance array index 2
    test_routes.routes_map[UGL].first.push_back("PEK");
    test_routes.routes_map[UGL].second.push_back(
        test_routes.haversine(40.1046698, -88.2290223, 40.0798573, 116.6009234));
    //PEK distance array index 0
    test_routes.routes_map[PEK].first.push_back("UGL");
    test_routes.routes_map[PEK].second.push_back(
        test_routes.haversine(40.0798573, 116.6009234, 40.1046698, -88.2290223));
    //SAN distance array index 0
    test_routes.routes_map[SAN].first.push_back("PEK");
    test_routes.routes_map[SAN].second.push_back(
        test_routes.haversine(37.2965314, -122.0976163, 40.0798573, 116.6009234));
    test_routes.routes_map[WAL].first.push_back("PEK");
    test_routes.routes_map[WAL].second.push_back(
        test_routes.haversine(40.146127, -88.255618, 40.0798573, 116.6009234));
    REQUIRE();
    REQUIRE(test_routes.routes_map[UGL].second[1] < test_routes.routes_map[UGL].second[2]);
}

