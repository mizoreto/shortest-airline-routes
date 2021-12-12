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
    /**
     * readRawData() reads data from airports.dat, which is the file obtained directly from openflights.org,
     * and it inserts the airport data into the map airports.
     * It will also call writeCleanData().
     * @param URL url of the input data file. If no URL is given, then the default is "airports.dat"
    */
    void readRawData();
    void readRawData(string URL);
    /**
     * writeCleanData() writes the data into a .dat with a clean format, storing only the needed information.
     * It is used with readCleanData() to improve data clarity and reduce reading time.
     * @param URL url of the output data file. If no URL is given, then the default is "airports_clean.dat"
    */
    void writeCleanData();
    void writeCleanData(string URL);
    /**
     * readCleanData() reads data from a data file with the clean format, and inserts the airport data into the map airports.
     * only works when input file is present and contains airport data in the clean format.
     * @param URL url of the input data file. If no URL is given, then the default is "airports_clean.dat"
    */
    void readCleanData();
    void readCleanData(string URL);
    /*
        A map containing information for all airports, it acts as a collection of all vertices (airports).
        The keys are strings, which are 3 or 4-charcter IDs of the airports.
        The values are airport structs, which contain the ID, latitude, longitude, and degree of an airport.
    */
    map<string, airport*> airports;
};

