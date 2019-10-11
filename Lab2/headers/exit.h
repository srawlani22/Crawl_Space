////////////////////////////////
// title: Exit.h
// descr: Refines pure virtual class Object to define an exit from a room
//		  by pairing a name with a room number to which this exit will take
//		  the explorer. This class works best if Crawlspace contains a vector
//		  of Location objects, where the index in the vector corresponds to the
//		  room number.
//
// takeme() displays an appropriate message
// depending on whether this is an exit or a treasure.
//
// Author: Matthew Bell and CS273-Fall 2018
// Edited by: Nora Riches and Sparsh Rawlani
// Assisted on some problems by Scott Griffith
// Last updated: 10/10/2019
////////////////////////////////

#include "object.h"// included the object class

#ifndef EXIT_H_
#define EXIT_H_


//class Exit
//Derived from the Object Class
//Has a constructor that takes in the name and description and an integer that points to the exit
//Changes from the psuedo code:
	//we just added another getter method to get the pointer of the exit object
class Exit : public Object {
public:
	Exit(int where_to, std::string name, std::string descr)
		: Object(name, descr, where_to) {}

	//takeme method derived from the base class
	//Input: NA
	//Output: override of the virtual function in object, picks up the exit if called
	Object* takeme(); 

    void describeme(); //override fo the virtual function in object

	//getter for a pointer of the exit object
	//Input: NA
	//Output: override of the virtual function in object, picks up the exit if called
    Object* getPointer();
};

#endif