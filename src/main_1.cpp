#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"

int main() {
    
    map<string, pair<vector<string>, vector<double> > > test_1 = read_routes();
    return 0;
}