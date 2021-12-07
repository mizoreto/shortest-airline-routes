#include "read_airport.h"
#include "read_airport.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readRawData();
    apts.readCleanData();
    return 0;
}