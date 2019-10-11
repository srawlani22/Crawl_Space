#include "treasure.h"

Object * Treasure::takeme()// takeme method from the base class is overloaded, prints the score of the treasure
{
	std::cout << "You got " << this->getValue() << " points!" << std::endl;
	return this;
}


Object* Treasure::getPointer(){
	return this;
}// retruns a pointer from the base class

void Treasure::describeme(){
    std::cout << getDescr() << " that is worth " << getValue() << " points." << std::endl;
}

