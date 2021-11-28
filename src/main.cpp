#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"
#include <vector>

int main() {
<<<<<<< HEAD
    map<string, airport> test = readRawData();
    map<string, pair<vector<string>, vector<double> > > test_1 = read_routes();
=======
    Airports apts;
    map<string, Airports::airport*> test = apts.readRawData();
>>>>>>> f175e37f4450d5006617cd73e0141ac3b013cf93
    return 0;
}