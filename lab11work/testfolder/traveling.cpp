#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE

    //start location
    string start = dests[0];

    //deletes first location from itinerary
    dests.erase(dests.begin());

    //sort list and get first distance check
    sort(dests.begin(),dests.end());
    printRoute(start,dests);
    float distance = computeDistance(me, start, dests);
    float placeholder = 0;

    while(next_permutation(dests.begin(),dests.end())){
      placeholder = computeDistance(me,start,dests);

      if(placeholder < distance){
	distance = placeholder;

	//print out shorter route
	printRoute(start,dests);
      }
    }

					   
    return 0;
}
/**@brief outputs the total distance of the route
 *@param &me this is the land which is used
 *@param start this is the starting and end location
 *@param dests this is the actual route(given as a vector)
 *@return this is the distance of the route given as a float
 */
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    // YOUR CODE HERE
  float distance = me.getDistance(start,dests[0]);

  for(int i = 0; i < dests.size()-1; i++){
    distance = distance + me.getDistance(dests[i], dests[i+1]);
  }

  distance = distance + me.getDistance(dests[dests.size()-1], start);

  return distance;
}

/**@brief this takes in a route and prints it out
 *@param start this is the starting location
 *@param dests this is the vector of the route itself
 */
// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
  cout << start << " -> ";
  for(int i = 0; i < dests.size(); i++){
    cout << dests[i] << " -> ";
  }
  cout << start << endl;
}
