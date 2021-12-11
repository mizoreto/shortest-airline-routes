#include "read_airport.h"
#include "read_airport.cpp"
#include "read_routes.h"
#include "read_routes.cpp"
#include "algorithms.h"
#include "algorithms.cpp"

#include <vector>

int main() {
    Airports apts;
    apts.readRawData();
    apts.readCleanData();
    // cout << apts.airports["TRF"]->ID << endl;
    map<string, pair<vector<string>, vector<double> > > test_1 = read_routes();
    // all the source airports in the map
    map<string, pair<vector<string>, vector<double> > >::iterator it;
    int count = 1;
    int len_zero = 0;
    for(it = test_1.begin(); it != test_1.end(); it++) {
        cout<<"airport number "<< count <<": "<<it->first <<endl;
        count++;
        if ((it->second).first.size() == 0) {
            len_zero++;
        }
    }
    cout<<len_zero<<endl;

    BFS("AER");
    addDegreeToAirport(apts.airports, test_1);
    cout<<dijkstra("AER", "AER")<<endl;
    string IDa = mostCentralAirport(apts.airports);
    return 0;
}