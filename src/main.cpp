#include "read_airport.h"
#include "read_airport.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readRawData();
    apts.readCleanData();
    // cout << apts.airports["TRF"]->ID << endl;
    return 0;
}