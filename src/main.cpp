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
    map<string, pair<vector<string>, vector<double> > > routes = read_routes();
    findMinDistance("AES", "KTW");
    addDegreeToAirport(apts.airports, routes);
    string IDa = mostCentralAirport(apts.airports);
    return 0;
}