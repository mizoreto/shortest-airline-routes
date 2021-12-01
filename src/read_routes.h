#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//class Routes {
    std::map<string, pair<vector<string>, vector<double> > > read_routes();
    double haversine_dist(double lat_1, double long_1, double lat_2, double long_2);
    double cvrtToRad(double degree);
//};