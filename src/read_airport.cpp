#pragma once
#include "read_airport.h"

#include <iostream>
#include <fstream>
#include <utility> 
#include <stdlib.h>
/**
 * Reads raw data from airports.dat, the file from openflights.org.
 * Then addes the data into the class variable airports, which is a map.
*/
void Airports::readRawData() {
    ifstream file("airports.dat"); //setting up variables.
    string lineText;
    int count = 0;
    // cout << "line 13" << endl;
    while (getline(file, lineText)) {//this loop reads all every line of airports.dat
        string parts[14];
        string text = lineText;
        for (int i = 0; i < 8; i++) {
            size_t commaIndex = text.find(',');
            parts[i] = text.substr(0, commaIndex);
            text.erase(0, commaIndex + 1);
        }

        airport * newAirport = new airport(); //creating a new airport object and setting up its variables.
        if (parts[4] != "\\N") newAirport->ID = parts[4];
        else newAirport->ID = parts[5];
        newAirport->ID.erase(newAirport->ID.begin());
        newAirport->ID.erase(newAirport->ID.end()-1);
        newAirport->lat = strtod(parts[6].c_str() , NULL);
        newAirport->lon = strtod(parts[7].c_str() , NULL);
        airports.insert(pair<string, airport*> (newAirport->ID, newAirport));
        
        count++;
    }
    // map<string, Airports::airport*>::iterator it = airports.begin();
    // advance(it, 104);
    // cout << "This airport is " << it->second->ID << endl;// cout << "airports has size " << airports.size() << endl;// cout << "This airport is " << airports["MAG"]->ID << endl;
    file.close();
    cout << "Task Complete: raw data from airports.dat is added to class variable airports of type map<string, Airports::airport*>" << endl;
}

void Airports::writeCleanData(map<string, Airports::airport*> airports) {
    
}

void Airports::readCleanData() {

}