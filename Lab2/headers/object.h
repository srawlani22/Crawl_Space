////////////////////////////////
// title: Object.h
// descr: Pure virtual superclass for Exit and Treasure
//
// describeme() displays the object name and verbose description
// pure virtual function takeme() displays an appropriate message
// depending on whether this is an exit or a treasure.
//
// Author: Matthew Bell and CS273-Fall 2018
// Edited by: Nora Riches
// Last updated: 10/1/2019
////////////////////////////////

#include <string>
#include <iostream>
#ifndef OBJECT_H_
#define OBJECT_H_


//class Object
//Is the base class for Exit and Treasure
//has two strings, one for capturing the name and the other for capturing the decription. Also has an integer, 
	//that stores the value of the exits becaus the exits take the explorer to a new location and value stores that
	//location as an integer
//no changes from the psuedo code
class Object {
private:
	std::string name;
	std::string descr;
	int value; //For exits, this will be where it takes you. For treasures, it's point value.
public:
	//Default constructor that sets the name to be thingy, descr to be vague, and the value to be -1 to know that it is not valid
	Object ();

    //Constructor that takes in inputs and sets variables
    Object(std::string inputName, std::string inputDescr, int inputValue);

	//Prints the description 
	virtual void describeme() = 0;

    //Getter for description
    std::string getDescr (); 

	//Getter for the name of the object
	std::string getName();

	//Getter for the value (either point or location) for the object
	int getValue();

	//Virtual method that will be overloaed in the treasure exit classes
	virtual Object* takeme() = 0;
};

#endif 