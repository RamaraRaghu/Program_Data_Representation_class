#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
  //We have the count of cities, and the size of the mpa
    int num_city_names, xsize, ysize;
    //2 vectors describing position of hte cities
    vector<float> xpos, ypos;
    //name of the cities
    vector<string> cities;
    //distances between the cities?
    float *distances;
    map<string, int> indices;

public:
    //class descriptor taking in seed, x and y scale and number of cities
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    ~MiddleEarth();
    void print();
    void printTable();
    //gets the distance between 2 cities.
    float getDistance (string city1, string city2);
    //gets the list of cities to visit?
    vector<string> getItinerary(unsigned int length);
};

#endif
