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

map<string, pair<vector<string>, vector<double> > > read_routes() {
    string routes;
    ifstream inFile;
    Airports raw_data;
    raw_data.readCleanData();
    map<string, Airports::airport*> airport_data = raw_data.airports;
    
    inFile.open("routes.dat");
    if (!inFile) {
        cout<<"Failed to open file"<<endl;
        exit(1); //terminate program
    }
    map<string, pair<vector<string>, vector<double> > > result_routes;
    string line_text;
    while (getline(inFile, line_text)) {
        vector<string> v;
        stringstream ss(line_text);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        cout<<"v[2]: "<<v[2]<<"  "<<"v[4]: "<<v[4]<<endl;
        result_routes[v[2]].first.push_back(v[4]);
        cout<<__LINE__<<endl;
        double src_lat = airport_data[v[2]]->lat;
        cout<<__LINE__<<endl;
        double src_long = airport_data[v[2]]->lon;
        double dest_lat = airport_data[v[4]]->lat;
        double dest_long = airport_data[v[4]]->lon;
        double src_dest_dist = haversine_dist(src_lat, src_long, dest_lat, dest_long);
        result_routes[v[2]].second.push_back(src_dest_dist);
    }
    inFile.close();

    map<string, pair<vector<string>, vector<double> > >::iterator it;
    int count = 0;
    for (it = result_routes.begin(); it != result_routes.end(); it++) {
        cout<<"source: "<< it->first <<endl;
        count++;
        for (unsigned i = 0; i < it->second.first.size(); i ++) {
            cout<<"destination: "<< it->second.first[i] <<endl;
        }
        if (count == 5) {
            break;
        }
    }
    return result_routes;
}

double haversine_dist(double lat_1, double long_1, double lat_2, double long_2) {
    double lat_diff = cvrtToRad(lat_2 - lat_1);
    double lon_diff = cvrtToRad(long_1 - long_2);
    double a = pow(sin(lat_diff / 2), 2) + cos(cvrtToRad(lat_1)) * 
           cos(cvrtToRad(lat_2)) * sin(lon_diff / 2) * sin(lon_diff / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return E_RADIUS * c;
    
}

double cvrtToRad(double degree) {
    return degree * (M_PI / 180);
}