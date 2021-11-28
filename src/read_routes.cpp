#include "read_routes.h"
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

map<string, pair<vector<string>, vector<double> > > read_routes() {
    string routes;
    ifstream inFile;
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
        result_routes[v[2]].first.push_back(v[4]);

        //result_routes[v[2]].second.push_back();
    }
    inFile.close();

    map<string, pair<vector<string>, vector<double> > >::iterator it;
    int count = 0;
    for (it = result_routes.begin(); it != result_routes.end(); it++) {
        cout<<"airport: "<< it->first <<endl;
        count++;
        if (count == 5) {
            break;
        }
    }
    return result_routes;
}