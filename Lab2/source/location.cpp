#include <stdexcept>
#include "location.h"

Location::Location(std::string inputName, std::string inputDescr){
	//assign member variables to be what was input
	name = inputName;
	descr = inputDescr;
} 

std::string Location::getName (){
    return name;// getter function returns the name of the location
}

int Location::exitLocation(std::string name)//retuns the location as an integer
{
	std::list<Exit>::iterator cur = exits.begin();
	while (cur != exits.end()) {// a while loop iterated through the iterator to check if we are not at the same exit in the list
		if (cur->getName() == name) // finds it based on the name of the location
			return cur->getValue();// returns the value of the location
		++cur;// the itearator is then updated in order to check for new locations
	}

	//Otherwise, we didn't find it
	return -1;
}

Object* Location::findExit (std::string name){
	Object* item = nullptr;// a pointer from the object class that is null initially
    std::list<Exit>::iterator cur = exits.begin();//the loop checks if begin!=end 
    while (cur != exits.end()){
        if (cur -> getName() == name){ //if we find the exit
            item = cur -> getPointer();//then the pointer is pointed to that pointer of the location class that is from the object class
            break;
        }
		cur++;// the iterator then gets incremented so that we can get new exits
    }
    if (item == nullptr){// if we don't find an exit or if we find a treasure then this is executed
		std::cout << "That item isn't here!" << std::endl;
    }
    return item;// the pointer is returned
}

Object* Location::findTre(std::string name){
    Object* item = nullptr;// a pointer from the object class that is null initially
    std::list<Treasure>::iterator cur = inventory.begin();
    while (cur != inventory.end()){//the loop checks if begin!=end 
        if (cur -> getName() == name)//if we find the treasure
            item = cur -> getPointer();//then the pointer is pointed to that pointer of the location class that is from the object class
			break;
	    
		cur++;// the iterator then gets incremented so that we can get new exits
	}
    
    if (item == nullptr){//if we don't find a treasure or if we find an exit, then this gets executed
		std::cout << "That item isn't here!" << std::endl;
    }
    return item;//the pointer is returned

}

Object* Location::pickup(std::string name)
{
	Object* item = nullptr;// pointer to the Object class
	std::list<Treasure>::iterator cur = inventory.begin();
	while (cur != inventory.end()) {
		if (cur->getName() == name) { //if we find a treasure then
			item = cur->takeme();// we pick it up by calling the take me method
			inventory.erase(cur); // the treasure then gets erased from the inventory since the explorer picked it up
			break;
		}
	}
	if (item == nullptr){// if the user tries to pick up at a location where there is no treasure/exit
		std::cout << "That item isn't here!" << std::endl;
    }
	return item;// the pointer is returned
}

//Lists exits
void Location::listExits()//this method just goes through the list of exits and prints the name of all exits
{
	std::list<Exit>::iterator it = exits.begin();
	while (it != exits.end()) {
		it->describeme();
		++it;
	}
}

//List treasures in the room inventory
void Location::listTreasures()//this method just goes through the list of treasures and prints the name of all treasures
{
	std::list<Treasure>::iterator it = inventory.begin();
	while (it != inventory.end()) {
		it->describeme();
		++it;
	}
}

//Display the verbose description
void Location::describe()
{
	//Display the short name and overall description of the setting
	std::cout << name << std::endl;
	std::cout << descr << std::endl;

	//Display any exits
	if(!(exits.empty())){
		listExits();
	}

	//Display any treasures
	if(!(inventory.empty())){
		listTreasures();
	}
}
