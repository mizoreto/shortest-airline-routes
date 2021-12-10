#pragma once

#include <string>
#include <map>

using namespace std;

class Airports {
    public:
    struct airport {
        string ID; //ID stores 3 or 4 airport letter ID.
        double lat, lon; //latitude and longitude
        int degree; //the degree, or # of edges an airport has.

        airport(string nID, double nlat, double nlon, int ndegree) {
            ID = nID;
            lat = nlat;
            lon = nlon;
            degree = ndegree;
        };
        airport() {};
    };
    /*
        readRawData() reads data from airports.dat, which is the file obtained directly from openflights.org,
        and it inserts the airport data into the map airports.
        It will also call writeCleanData().
    */
    void readRawData();
    /*
        writeCleanData() writes the data into airports_clean.dat, storing only the needed information.
        It should be used with readCleanData() to improve data clarity and reduce reading time.
    */
    void writeCleanData();
    /*
        readCleanData() reads data from airports_clean.dat, and inserts the airport data into the map airports.
        only works when airports_clean.dat is present and contains airport data.
    */
    void readCleanData();
    /*
        A map containing information for all airports, it acts as a collection of all vertices (airports).
        The keys are strings, which are 3 or 4-charcter IDs of the airports.
        The values are airport structs, which contain the ID, latitude, longitude of an airport.
    */
    map<string, airport*> airports;
};

