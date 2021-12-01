#include "read_airport.h"
#include "read_airport.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readRawData();
    map<string, Airports::airport*> test = apts.airports;
    return 0;
}