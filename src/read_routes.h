#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class routes {
    public:
        /**
        * read the data from any given file
        * @param string file_name_routes, the file name of routes raw data
        * @param string file_name_airports, the filename of airports raw data
        */
        void read_routes();
        void read_routes(string file_name_routes, string file_name_airports);

        /**
        * returns the haversine distance of two coordinates
        *
        * @param double lat_1 latitude of the first coordinate
        * @param double long_1 longitude f the first coordinate
        * @param double lat_2 latitude of the second coordinate
        * @param double long_2 longitude of the second coordinate
        * @return haversine distance
        */
        double haversine_dist(double lat_1, double long_1, double lat_2, double long_2);

        /**
        * convert degree to radian
        * @param double degree
        * @return double radian
        */
        double cvrtToRad(double degree);

        /**
        * a map container that stores the result of the reads. The first element of the map is a string 
        * representing the source airport and the second element is a pair. The first element of the pair 
        * is a string vector that stores all the destination airport that the source airport could reach,
        * and the second element of the pair is a double vector that stores all the distance from the source 
        * to the corresponding destination.
        */
        map<string, pair<vector<string>, vector<double> > > routes_map;     
};