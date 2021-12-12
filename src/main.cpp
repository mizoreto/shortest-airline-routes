#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"
#include "algorithms.h"
#include "algorithms.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readCleanData(); //reads data from "airport_clean.dat"
    map<string, pair<vector<string>, vector<double> > > routes = read_routes();
    string departing, destination; //strings that store departing and arriving airport IDs.
    bool inputInvalid = true;
    cout << "Consult airport.dat for the airports' information." << endl;
    while (inputInvalid) { //reads user input, and loop stops when both airport IDs are valid.
        cout << "Please type in the 3 or 4-letter ID of the departing Airport:" << endl;
        cin >> departing;
        for (int i = 0; i < departing.length(); i++) departing[i] = toupper(departing[i]);
        cout << "Please type in the 3 or 4-letter ID of the arriving Airport." << endl;
        cin >> destination;
        for (int i = 0; i < destination.length(); i++) destination[i] =toupper(destination[i]);
        if (apts.airports.count(departing) > 0 && apts.airports.count(destination) > 0) inputInvalid = false;
        else {
            if (apts.airports.count(departing) == 0) cout << "The departing airport ID " << departing << " is Invalid;";
            if (apts.airports.count(destination) == 0) cout << "The arriving airport ID " << destination << " is Invalid;";
            cout << "Please try again and enter valid airport IDs." << endl;
        }
    }
    findMinDistance(departing, destination); //runs and prints the result dijkstra's algorithm.
    addDegreeToAirport(apts.airports, routes); //prepares the airport objects for degree centrality algorithm.
    mostCentralAirport(apts.airports); //runs and prints the result of degree centrality algorithm.

    return 0;
}