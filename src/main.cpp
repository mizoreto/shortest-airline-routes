#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"
#include "algorithms.h"
#include "algorithms.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readCleanData();
    map<string, pair<vector<string>, vector<double> > > routes = read_routes();
    string departing, destination;
    bool inputInvalid = true;
    cout << "Consult airport.dat for the airports' information." << endl;
    while (inputInvalid) {
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

    findMinDistance(departing, destination);
    addDegreeToAirport(apts.airports, routes);
    mostCentralAirport(apts.airports);
    return 0;
}