////////////////////////////////
// title: Location.h
// descr: Defines a location object for a crawlspace.
//		  Locations have a short name and verbose description.
//		  Locations have exits that lead to other locations in
//		  in a crawlspace.
//		  Locations have an inventory of treasures that can be
//		  updated by explorers taking said treasures.
//
// Author: Matthew Bell and CS273-Fall 2018
// Edited by: Nora Riches and Sparsh Rawlani
// Assisted on some problems by Scott Griffith
// Last updated: 10/1/2019
////////////////////////////////

#include <string>
#include <list>
#include "exit.h"
#include "treasure.h"

#ifndef LOCATION_H_
#define LOCATION_H_

/*
class Location
Has two string private members that store the name of the location and its description.
Also has two lists, one to store all the exits and the other to store all the treasures.
//Changes from the psuedo code:
	-we created a getter function to get the name of the location so that we can use that in findExit and findTre names
	-Originally, there was only one find function to find both the exits and the treasures, but we made two separate
		functions since there were two different lists for exits and treasures one method didn't seem the like the 
		correct way to interact with both the lists since there was only one loop
	-we also created a pickup method that picks up a treasure based on the name of the treasure, and then it is also
		called inside the take fucntion in the explorer class where a pointer from the location class points and
		picks up the oebjct using this method
*/
class Location {
private:
	std::string name; //name of the location
	std::string descr; //description to the location
	std::list<Exit> exits; //vector of exits in the current location
	std::list<Treasure> inventory; //vector of treasures in the current location

	friend class Crawlspace; // We want Crawlspace to be able to dig new exits and place treasures
	
	//Digs an exit from this location to another in the crawlspace
	void dig(Exit e) { 
		exits.push_back(e);
	}

	//Drops a treasure in the location
	void drop(Treasure t) { 
		inventory.push_back(t); 
	}

public:
	//Constructor to set name and description
	Location(std::string name, std::string descr);

    //Getter for name
    //////testing
    std::string getName ();

	//Scans for an exit by name and returns the associated location number
	int exitLocation(std::string name);

	//Scans for an exit by name and returns a pointer to the exit
	Object* findExit (std::string name);

	//Scans for 
	Object* findTre(std::string name);

	//Scans for a treasure and hands it over, removing it in the process from the loc
	Object* pickup(std::string name);

	//Display only the name
	void printName() { std::cout << name << std::endl; }

	//Displays the exits and treasures
	void listExits();
	void listTreasures();

	//Display the verbose description
	void describe();

};

#endif