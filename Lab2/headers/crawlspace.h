////////////////////////////////
// title: Crawlspace.h
// descr: Defines a Crawlspace as a vector of locations
//		  Goal is for an Explorer to be able to traverse
//		  a maze of locations collecting treasures.
//
// Author: Matthew Bell and CS273-Fall 2018
// Editied by: Nora Riches and Sparsh Rawlani
// Assisted on some problems by Scott Griffith
// Last updated: 10/18/2018
////////////////////////////////

#include<vector>
#include "location.h"

#ifndef CRAWLSPACE_H_
#define CRAWLSPACE_H_

/* class Crawlspace
has a vector of locations, and a couple of unsigned short variables that store the start position of the crawlspace
Changes from the psuedo code"
	- we had to make maze a vector of pointers from the location class because if it's not a pointer, then the
		value of Location changes when we push back the location in the same vector for different exits and treasure
	-added another getter function that returns the starting position everytime a crawlspace is created
*/
class Crawlspace {
private:
	std::vector<Location*> maze;
	unsigned short start; // The starting location for the maze
	unsigned short size;  // The total number of locations in this maze.
public:
	//When a Crawlspace is first constructed, its starting location is -2 and its size is 0.
	//i.e. there are no locations. 
	Crawlspace();

    //Getter for a location in the vector
    Location* getLocation(int loc);

    //Getter for the start position
    int getStart();

	//Useful functions for designing and creating a Crawlspace:
#pragma region Design
	/*****************************
	* Adds a location to the crawlspace
	* @param l is a reference to a location.
	* Postcondition: a new location is added to the crawlspace
	******************************/
	void addLocation(Location* l);

	/*****************************
	* Adds an exit to an existing location
	* @param e is an exit
	* @param loc is the location to which an exit is being added
	* Postcondition: a new exit is added to the crawlspace
	******************************/
	void updateLoc(Exit& e, int loc);

	/*****************************
	* Drops a treasure into an existing location
	* @param t is an treasure
	* @param loc is the location into which t is being dropped
	* Postcondition: a new treasure is added to the crawlspace
	******************************/
	void updateLoc(Treasure& t, int loc);

	//Sets a new start location. The location must already be in locations, and
	//we must know where it is in the vector.
    //This must be called before an explorer is made or else they will not have a location to begin at
	void setStart(unsigned short startLoc);
#pragma endregion
};

#endif