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
        for (int i = 0; i < 8; i++) {
            size_t commaIndex = lineText.find(',');
            parts[i] = lineText.substr(0, commaIndex);
            lineText.erase(0, commaIndex + 1);
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
    cout << "airports has size " << airports.size() << endl;// cout << "This airport is " << airports["MAG"]->ID << endl;
    file.close();
    cout << "Task Complete: raw data from airports.dat is added to class variable airports of type map<string, Airports::airport*>" << endl;
    writeCleanData();
}

void Airports::writeCleanData() {
    if (airports.empty()) {
        cout << "Airports is empty" << endl;
        return;
    }
    ofstream outFile("airports_clean.dat");
    for (map<string, airport*>::iterator it = airports.begin(); it != airports.end(); ++it) {
        outFile << it->second->ID << "," << it->second->lat << "," << it->second->lon << endl;
    }
    outFile.close();
    cout << "Task Complete: data from the map airports is written to the file airports_clean.dat" << endl;
}

void Airports::readCleanData() {
    ifstream file("airports_clean.dat"); //setting up variables.
    if (file.fail()) {
        cout << "Task Failed: the file airports_clean.dat is not found" << endl;
        return;
    }
    if (!airports.empty()) airports.clear();
    string lineText;
     while (getline(file, lineText)) {//this loop reads all every line of airports_clean.dat
        string parts[3];
        for (int i = 0; i < 3; i++) {
            size_t commaIndex = lineText.find(',');
            parts[i] = lineText.substr(0, commaIndex);
            lineText.erase(0, commaIndex + 1);
        }
        airport * newAirport = new airport(); //creating a new airport object and setting up its variables.
        newAirport->ID = parts[0];
        newAirport->lat = strtod(parts[1].c_str() , NULL);
        newAirport->lon = strtod(parts[2].c_str() , NULL);
        airports.insert(pair<string, airport*> (newAirport->ID, newAirport));
    }
    cout << "airports has size " << airports.size() << endl;
    cout << "Task Complete: data from airports_clean.dat is added to class variable airports of type map<string, Airports::airport*>" << endl;
}