#pragma once
#define _USE_MATH_DEFINES
#define E_RADIUS 6371

#include "read_routes.h"
#include "read_airport.h"
#include "read_airport.cpp"
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void routes::read_routes() {read_routes("routes.dat");}

void routes::read_routes(string file_name) {
    string routes;
    ifstream inFile;
    Airports raw_data;
    raw_data.readCleanData();
    map<string, Airports::airport*> airport_data = raw_data.airports;//initialize airport data
    
    inFile.open(file_name.c_str());
    if (!inFile) {
        cout<<"Failed to open file"<<endl;
        exit(1); //terminate program
    }
    //file opened succesfully
    string line_text;
    //traverse by line in the given file
    while (getline(inFile, line_text)) {
        vector<string> v;
        stringstream ss(line_text);
        //store every element on the current line into a string vector
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        //skip to the next line if the airports in the current
        //line doesn't exist in airports.dat
        if (airport_data.find(v[2]) == airport_data.end() 
            || airport_data.find(v[4]) == airport_data.end()) {
                continue;
        }
        //add the destination airport to the vector that stores all
        //the destinations of the corresponding source airport
        routes_map[v[2]].first.push_back(v[4]);
        
        //get the latitutdes and longitudes of the source and destination
        //airport and calculate distance in between
        double src_lat = airport_data[v[2]]->lat;
        double src_long = airport_data[v[2]]->lon;
        double dest_lat = airport_data[v[4]]->lat;
        double dest_long = airport_data[v[4]]->lon;
        double src_dest_dist = haversine_dist(src_lat, src_long, dest_lat, dest_long);
        //store the distance into the corresponding vector
        routes_map[v[2]].second.push_back(src_dest_dist);
    }
    inFile.close();
}

double routes::haversine_dist(double lat_1, double long_1, double lat_2, double long_2) {
    double lat_diff = cvrtToRad(lat_2 - lat_1);
    double lon_diff = cvrtToRad(long_1 - long_2);
    double a = pow(sin(lat_diff / 2), 2) + cos(cvrtToRad(lat_1)) * 
           cos(cvrtToRad(lat_2)) * sin(lon_diff / 2) * sin(lon_diff / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return E_RADIUS * c;   
}

double routes::cvrtToRad(double degree) {
    return degree * (M_PI / 180);
}