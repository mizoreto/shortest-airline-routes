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
        * read_routes() reads routes data from routes.dat and airport longitudes and latitude from
        * read_airport.cpp and returns the source airport, destination airport, and distance of each 
        * route.
        *
        * @return a map where the first element is a string representing the source airport and the second
        * element is a pair. The first element of the pair is a string vector that stores all the destination
        * airport that the source airport could reach, and the second element of the pair is a double vector 
        * that stores all the distance from the source to the corresponding destination.
        */
        void read_routes();

        /**
        * read the data from any given file
        * @return a map where the first element is a string representing the third element in the line and 
        * the second element is a pair. The first element of the pair is a string vector and the second 
        * element of the pair is a double vector
        */
        void read_routes(string file_name);

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
        map<string, pair<vector<string>, vector<double> > > routes_map;     
};