#include "exit.h"

Object * Exit::takeme()
{
	std::cout << "What a concept!" << std::endl;// if a user tries to pick up an exit, then the method prints a message
	return this;//nullptr;
}

void Exit::describeme(){
    std::cout << getDescr() << " that leads to position " << getValue() << "." << std::endl;
}

Object* Exit::getPointer(){
    return this; // getter function returns the pointer
}