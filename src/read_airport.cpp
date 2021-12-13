#include "read_airport.h"

#include <iostream>
#include <fstream>
#include <utility> 
#include <stdlib.h>
/**
 * Reads raw data from airports.dat, the file from openflights.org.
 * Then addes the data into the class variable airports, which is a map.
*/
void Airports::readRawData() {readRawData("airports.dat");}
void Airports::readRawData(string URL) {
    ifstream file(URL.c_str()); //setting up variables.
    string lineText;
    int count = 0;
    while (getline(file, lineText)) {//this loop reads all every line of airports.dat
        string parts[14];
        for (int i = 0; i < 8; i++) {//for every segment of the line seperated by commas, splits the string and put them in parts[]
            size_t commaIndex = lineText.find(',');
            size_t specialCommaIndex = lineText.find(", ");
            if (specialCommaIndex != string::npos && specialCommaIndex <= commaIndex) 
                commaIndex = lineText.find(',', specialCommaIndex + 1);
            parts[i] = lineText.substr(0, commaIndex);
            lineText.erase(0, commaIndex + 1);
        }

        airport * newAirport = new airport(); //creating a new airport object and setting up its variables.
        if (parts[4] != "\\N") newAirport->ID = parts[4]; //if airport does not have 3-letter ID, use 4-letter ID instead.
        else newAirport->ID = parts[5];
        newAirport->ID.erase(newAirport->ID.begin());
        newAirport->ID.erase(newAirport->ID.end()-1);
        newAirport->lat = strtod(parts[6].c_str() , NULL);
        newAirport->lon = strtod(parts[7].c_str() , NULL);
        newAirport->degree = -1; //default degree to -1, meaning no degree has been added to this airport, yet.
        airports.insert(pair<string, airport*> (newAirport->ID, newAirport));

        count++;
    }
    file.close();
    //cout << "Task Complete: raw data from " << URL << " is added to class variable airports of type map<string, Airports::airport*>" << endl;
    writeCleanData();
}
void Airports::writeCleanData() {writeCleanData("airports_clean.dat");}
void Airports::writeCleanData(string URL) {
    if (airports.empty()) {//if the map airports is empty, then nothing to write.
        cout << "Error: Airports is empty" << endl;
        return;
    }
    ofstream outFile(URL.c_str());
    for (map<string, airport*>::iterator it = airports.begin(); it != airports.end(); ++it)
        outFile << it->second->ID << "," << it->second->lat << "," << it->second->lon << endl;
    outFile.close();
    //cout << "Task Complete: data from the map airports is written to the file " << URL << endl;
}

void Airports::readCleanData() {readCleanData("airports_clean.dat");}
void Airports::readCleanData(string URL) {
    ifstream file(URL.c_str()); //setting up variables.
    if (file.fail()) {
        cout << "Error: the file " << URL << " is not found" << endl;
        return;
    }
    if (!airports.empty()) airports.clear();
    string lineText;
     while (getline(file, lineText)) {//this loop reads all every line of airports_clean.dat
        string parts[3];
        for (int i = 0; i < 3; i++) {//for every segment of the line seperated by commas, splits the string and put them in parts[]
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
    //cout << "Task Complete: data from " << URL << " is added to class variable airports of type map<string, Airports::airport*>" << endl;
}