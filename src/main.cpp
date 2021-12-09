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
    map<string, pair<vector<string>, vector<double> > > test_1 = read_routes();
    BFS("AER");
    return 0;
}