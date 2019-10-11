////////////////////////////////
// title: Treasure.h
// descr: Refines pure virtual class Object to define a treasure.
//
// takeme() displays an appropriate message and returns a pointer
// to the treasure to allow it to be put in inventory.
//
// Author: Matthew Bell and CS273-Fall 2018
//Edited by: Nora Riches and Sparsh Rawlani
//Assisted on some problems by Scott Griffith
// Last updated: 10/17/2018
////////////////////////////////

#include "object.h"
#ifndef TREASURE_H_
#define TREASURE_H_

/*
class Treasure- derived from class Object
	has a constructor that overloads the constructor from the base class

Changes from pesudo code:
	-we just created a getPointer method that returns the pointer for the exit from the Object class
		we made this change in order to specify the pointer while using them in findTre and findExit methods in the explorer class
*/
class Treasure : public Object {
public:
	Treasure(std::string name, std::string descr, int value) :
		Object(name, descr, value) {}


	// takeme method-overlods the method from the base class 
	//takes the object(either exit or treasure) and prints the score accordingly
	//Input: NA
	//Output: prints information accordingly
	Object* takeme();

	//getter method for getting the pointer
	//returns the pointer from the base class

    void describeme(); //override fo the virtual function in object

    Object* getPointer();

};

#endif