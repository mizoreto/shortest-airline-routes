#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"
#include "algorithms.h"
#include "algorithms.cpp"

#include <vector>

//helper function that saves the results into an output file.
void saveOutput(string departing, string arriving, pair<double, vector<string> > dijkstraResult, pair<string, double> degreeCentralityResult, string URL) {
    ofstream outFile(URL.c_str());
    outFile << "==================== Basic Information ====================" << endl;
    outFile << "Departing Airport: " << departing << endl;
    outFile << "Arriving Airport: " << arriving << endl << endl;
    outFile << "==================== Dijkstra's Algorithm ====================" << endl;
    outFile << "Minimum Distance Path Taken: " << endl << "    ";
    for (int i = dijkstraResult.second.size() - 1; i > 0; i--) outFile << dijkstraResult.second[i] << " --> ";
    outFile << dijkstraResult.second.front() << endl;
    outFile << "Distance Traveled: " << dijkstraResult.first << " km." << endl << endl;
    outFile << "==================== Degree Centrality ====================" << endl;
    outFile << "Airport with most departing flights: " << degreeCentralityResult.first << endl;
    outFile << degreeCentralityResult.first << "'s degree: " << degreeCentralityResult.second << endl;
}

int main() {
    Airports apts;
    apts.readCleanData(); //reads data from "airport_clean.dat"
    routes rts;
    rts.read_routes();
    map<string, pair<vector<string>, vector<double> > > routes = rts.routes_map;
    string departing, destination; //strings that store departing and arriving airport IDs.
    bool inputInvalid = true;

    cout << "Consult airport.dat for the airports' information." << endl;
    while (inputInvalid) { //reads user input, and loop stops when both airport IDs are valid.
        cout << "Please type in the 3 or 4-letter ID of the departing Airport:" << endl;
        cin >> departing;
        for (size_t i = 0; i < departing.length(); i++) departing[i] = toupper(departing[i]); //convert to UPPERCASE.
        cout << "Please type in the 3 or 4-letter ID of the arriving Airport." << endl;
        cin >> destination;
        for (size_t i = 0; i < destination.length(); i++) destination[i] = toupper(destination[i]); //convert to UPPERCASE.

        if (apts.airports.count(departing) > 0 && apts.airports.count(destination) > 0) inputInvalid = false; //check if airports IDs exist.
        else { //tell user which id input is invalid.
            if (apts.airports.count(departing) == 0) cout << "The departing airport ID " << departing << " is Invalid; ";
            if (apts.airports.count(destination) == 0) cout << "The arriving airport ID " << destination << " is Invalid; ";
            cout << "Please try again and enter valid airport IDs." << endl;
        }
    }

    pair<double, vector<string> > dijkstraResult = findMinDistance(departing, destination, rts.routes_map); //runs and prints the result dijkstra's algorithm.
    addDegreeToAirport(apts.airports, rts.routes_map); //prepares the airport objects for degree centrality algorithm.
    pair<string, double> degreeCentralityResult =  mostCentralAirport(apts.airports); //runs and prints the result of degree centrality algorithm.

    //saving results to file.
    saveOutput(departing, destination, dijkstraResult, degreeCentralityResult, "result.txt");
    cout << "Results are saved in the file result.txt" << endl;
    return 0;
}