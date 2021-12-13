# Final Project Report
## Group Members
- yuhua2
- ziyiw8
- boyangy4
- jiayinm2

## Results
The process of reading airport data from .dat files is made roughly two times faster by processing the raw data from openflights.org with readRawData() and saving it to a cleaner format without unused information. Using the newly saved airports_clean.dat and readCleanData(), we were able to reduce the time of reading airport data by roughly half.

Our algorithm to find the shortest path between two airports, which used Dijkstra's algorithm, gives satisfactory results. Some examples of the results given by our algorithms:
  - Departing Airport: JFK. Arriving Airport: ORD
  Minimum Distance Path Taken: JFK --> ORD. Distance Traveled: 1187.84 km.
  ![image](https://media.github-dev.cs.illinois.edu/user/11774/files/74867e3e-2f81-4ee8-b62b-da3f4762db89)

  - Departing Airport: LHR. Arriving Airport: OAK
  Minimum Distance Path Taken: LHR --> JFK --> OAK. Distance Traveled: 9674.79 km.
  - Departing Airport: SHE. Arriving Airport: LHR
  Minimum Distance Path Taken: SHE --> FRA --> LHR. Distance Traveled: 8674.09 km.
  - Departing Airport: AER. Arriving Airport: ORD
  Minimum Distance Path Taken: AER --> KIV --> DUB --> ORD. Distance Traveled: 9420.12 km.
  - Departing Airport: HAR. Arriving Airport: SEA
  Minimum Distance Path Taken: Departing airport has no flights. Distance Traveled: -1 km.
As shown by these sample outputs, when there is a direct flight between two airports, the minimum distance path will be that direct flight. If there are no direct flights (Edges) connecting two airports (Vertices), our algorithm will still find the shortest path that involves changing flights at other airports. If there is not a single path between the departing and arriving airports, then as shown by the HAR and SEA airports, the algorithm will tell the user that the there is no flights, and that the is no distance traveled.

For degree centrality, we counted the out degrees of all airports, in this case, the number of departing flights from each airport. Our result was that, according to our flight data, the airport ATL, which is the Hartsfield-Jackson Atlanta International Airport, has the most amount of departing flights, which is 915, and therefore its out degree is 915, and it is the most central/busiest airport.
