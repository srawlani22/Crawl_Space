////////////////////////////////
// title: Crawlspace.cpp
// descr: Defines a Crawlspace as a vector of locations
//		  Goal is for an Explorer to be able to traverse
//		  a maze of locations collecting treasures.
//
// Author: Nora Riches and Sparsh Rawlani
// Assisted by Scott Griffith in some problems
// Last updated: 10/1/2019
////////////////////////////////

#include "crawlspace.h"

Crawlspace::Crawlspace(){
    //set the crawspace variables to show that there are no locations in the crawlspace yet
    start = -2;
    size = 0;
}

//getter function to get the current location within the crawlspace
Location* Crawlspace::getLocation(int loc){
    return maze.at(loc);
}

// getter method that returns the starting position
int Crawlspace::getStart(){
    return start;
}

//add location method
//pushes the location in the vector of locations
//updates the size of the crawlspace everytime a location is added.
void Crawlspace::addLocation(Location* l){
	maze.push_back(l); //push back the location into the vector of crawlspaces
	size++; //increment of the size every time a new location is created
} 

//method to update the location of Exits
// looks for the exit in the vector of locations digs an exit at that location
void Crawlspace::updateLoc(Exit& e, int loc){
    (maze.at(loc)) -> dig(e); //dig an exit at a location
}

//method to update the location of Treasures
// looks for the treasure in the vector of locations drops a treasure at that location
void Crawlspace::updateLoc(Treasure& t, int loc){
    (maze.at(loc)) -> drop(t); //drop a treasure at a location
}

//setStart- a setter fucntion that sets the strating location
void Crawlspace::setStart(unsigned short startLoc) { 
    start = startLoc; //set a start location to whatever is input
}
