#include "read_airport.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

map<string, airport> readRawData() {
    map<string, airport> airports;
    ifstream file("airports.dat");
    string lineText;
    int count = 0;
    while (getline(file, lineText)) {
        if (count == 22) {
            cout << lineText << endl;
            string parts[14];
            string text = lineText;
            for (int i = 0; i < 14; i++) {
                size_t commaIndex = text.find(',');
                parts[i] = text.substr(0, commaIndex);
                text.erase(0, commaIndex + 1);
            }
            cout << "Airport name: "<< parts[1] << endl;
            cout << "Airport ID: "<< parts[4] << endl;

            airport newAirport;
            if (parts[4] != "\\N") newAirport.ID = parts[4];
            else newAirport.ID = parts[5];
            cout << "newAirport ID: "<< newAirport.ID << endl;
            newAirport.lat = strtod(parts[6].c_str() , NULL);
            cout << "Airport lati: "<< parts[6] << endl;
            cout << "Airport lati: "<< newAirport.lat << endl;

        }
        count++;
    }

    return airports;
}

void writeCleanData(map<string, airport> airports) {
    
}

map<string, airport> readCleanData() {
    map<string, airport> airports;

    return airports;
}