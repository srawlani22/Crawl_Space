////////////////////////////////
// title: Object.cpp
// descr: Implementation of the pure virtual superclass for Exit and Treasure
//
// describeme() displays the object name and verbose description
// pure virtual function takeme() displays an appropriate message
// depending on whether this is an exit or a treasure.
//
// Author: Nora Riches
// Last updated: 10/1/2019
////////////////////////////////

#include <string>
#include <iostream>
#include "object.h"

Object::Object (){
    //assign member variables to be vague or invalid becuase they will be overloaded in the treasure 
	name = "Thingy"; 
	descr = "The thingy is nondescript.";
	value = -1;
}

Object::Object(std::string inputName, std::string inputDescr, int inputValue){
    name = inputName;// constructor overloads and assigns the name, descr, and value
    descr = inputDescr;
    value = inputValue;
}

std::string Object::getDescr (){
    return descr;
}

std::string Object::getName() { //getter function returns the name of the function
    return name; 
}

int Object::getValue() { //getter function returns the value of the value of the object
    return value; 
}