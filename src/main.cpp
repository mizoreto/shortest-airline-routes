#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"
#include "algorithms.h"
#include "algorithms.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readRawData();
    apts.readCleanData();
    // cout << apts.airports["TRF"]->ID << endl;
    map<string, pair<vector<string>, vector<double> > > routes = read_routes();
    // all the source airports in the map

    BFS("AER");
    findMinDistance("AER", "JFK");
    addDegreeToAirport(apts.airports, routes);
    string IDa = mostCentralAirport(apts.airports);
    return 0;
}