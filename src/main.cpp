#include "read_airport.h"
#include "read_airport.cpp"

int main() {
    Airports apts;
    map<string, Airports::airport*> test = apts.readRawData();
    return 0;
}