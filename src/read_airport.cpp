#pragma once
#include "read_airport.h"

#include <iostream>
#include <fstream>
#include <utility> 
#include <stdlib.h>

map<string, Airports::airport*> Airports::readRawData() {
    // map<string, airport> airports;
    ifstream file("airports.dat");
    string lineText;
    int count = 0;
    cout << "line 13" << endl;
    while (getline(file, lineText)) {
        // cout << lineText << endl;
        string parts[14];
        string text = lineText;
        for (int i = 0; i < 14; i++) {
            size_t commaIndex = text.find(',');
            parts[i] = text.substr(0, commaIndex);
            text.erase(0, commaIndex + 1);
        }
        cout << "line 22" << endl;
        // cout << "Airport name: "<< parts[1] << endl;
        // cout << "Airport ID: "<< parts[4] << endl;
        
        airport * newAirport = new airport();
        cout << "line 28" << endl;
        if (parts[4] != "\\N") newAirport->ID = parts[4];
        else newAirport->ID = parts[5];
        newAirport->ID.erase(newAirport->ID.begin());
        newAirport->ID.erase(newAirport->ID.end()-1);
        cout << "line 31" << endl;
        //cout << "newAirport ID: "<< newAirport.ID << endl;
        newAirport->lat = strtod(parts[6].c_str() , NULL);
        newAirport->lon = strtod(parts[7].c_str() , NULL);
        // cout << "Airport lati: "<< newAirport.lat << endl;
        // cout << "Airport long: "<< newAirport.lon << endl;
        cout << "line 37" << endl;
        airports.insert(pair<string, airport*> (newAirport->ID, newAirport));
        cout << "line 39" << endl;
        
        count++;
    }
    cout << "line 43" << endl;
    map<string, Airports::airport*>::iterator it = airports.begin();
    advance(it, 104);
    cout << "This airport is " << it->second->ID << endl;
    cout << "airports has size " << airports.size() << endl;
    cout << "This airport is " << airports["MAG"]->ID << endl;
    return airports;
}

void Airports::writeCleanData(map<string, Airports::airport*> airports) {
    
}

map<string, Airports::airport*> Airports::readCleanData() {
    map<string, Airports::airport*> airports;

    return airports;
}