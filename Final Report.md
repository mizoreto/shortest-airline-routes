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
  ![image](https://media.github-dev.cs.illinois.edu/user/11774/files/825d1d4e-4c19-4c3a-ab19-0921a9458ad7)

  - Departing Airport: SHE. Arriving Airport: LHR
  Minimum Distance Path Taken: SHE --> FRA --> LHR. Distance Traveled: 8674.09 km.
  ![image](https://media.github-dev.cs.illinois.edu/user/11774/files/ecfdf85c-1a91-4bda-96d7-2269245a6398)

  - Departing Airport: AER. Arriving Airport: ORD
  Minimum Distance Path Taken: AER --> KIV --> DUB --> ORD. Distance Traveled: 9420.12 km.
  - Departing Airport: HAR. Arriving Airport: SEA
  Minimum Distance Path Taken: Departing airport has no flights. Distance Traveled: -1 km.
 
As shown by these sample outputs, when there is a direct flight between two airports, the minimum distance path will be that direct flight. If there are no direct flights (Edges) connecting two airports (Vertices), our algorithm will still find the shortest path that involves changing flights at other airports. If there is not a single path between the departing and arriving airports, then as shown by the HAR and SEA airports, the algorithm will tell the user that the there is no flights, and that the is no distance traveled.

For degree centrality, we counted the out degrees of all airports, in this case, the number of departing flights from each airport. Our result was that, according to our flight data, the airport ATL, which is the Hartsfield-Jackson Atlanta International Airport, has the most amount of departing flights, which is 915, and therefore its out degree is 915, and it is the most central/busiest airport.

In our test suite, we tested the main components of our algorithm, from both the data readers for airports and routes, to dijkstra's algorithm, to degree centrality. We created the test cases and made sure the outcomes of the algorithms match with the expected outcomes. Therefore, we conclude that our algorithms work as intended.

Some interesting discoveries we found were that many airports had no flights connecting them with other airports. This could be due to the fact that even rooftoop helipads are counted as airports, and the fact that some special airports, like Air Force Bases, were also included in the database of airports. Also, we noticed that most commercial airports located in cities have both a 3-letter IATA code and a 4-letter ICAO code assigned to them, while small airports, or special airports like air force bases, rarely have an IATA code assigned. In extremely rare cases, an airport may have neither IATA nor ICAO code assigned to it, an example is the Sun Island Resort and SPA (airport).
