////////////////////////////////
// title: Explorer.h
// descr: Defines an Explorer with a name, score and location
//		  Goal is for an Explorer to be able to traverse
//		  a maze of locations collecting treasures.
//
// Author: Nora Riches and Sparsh Rawlani
// Assisted on some problems Scott Griffith
// Last updated: 10/1/2019
////////////////////////////////

#ifndef EXPLORER_H
#define EXPLORER_H

#include <iostream>
#include "location.h"// included all the required classes
#include "treasure.h"
#include "exit.h"
#include "object.h"
#include "crawlspace.h"


// class Explorer
//has three private members, a constructor and some other publiv methods
//Difference from the pusedo code:
/*  - we had a pointer to the Location class in order to track the current location, it wasn't the best way
        way to keep track of the locatin since the pointer was pointing to different locations and hence 
        we used an intger, although we still used the pointer from Location class in order to examine the Object.
    - we also had a vector of treasurs that we did not use because we realized that the class location already has 
        a list of treasures and exits
    -our getter functions are void which we changed to string/int so that they could return the desired outcome
    -we also did not include examine and take methods in the psuedo code we didin't realize that the user was 
        first suppose to examine and then take the object before moving
    -Lastly, we have renamed setLocation to updateLoc because it was technically updating the location and not 
        setting it.
*/
class Explorer {
    private:
        std::string name; // string variable that stores the name of the explorer
        int score; // an integer to keep track of Explorer's score
        int currentLoc;// an integer to keep track of the user's current location

    public:
        //Constructor
        //this is dependent upon a location variable being names int eh main function that is the same as the start location of the crawlspace
        Explorer(std::string inputName, Crawlspace inputCrawlspace);

        //Getter for name
        std::string getName();

        //Getter for location
        int getLocation();

        //Getter for score
        int getScore();

        //setter for name
        void setName(std::string inputName);

        //Setter for Location
        void updateLoc (int loc);

        //method to move the explorer around the crawlspace thorugh an exit
        //takes in a string of a name of an exit
        //checks if the exit is there
        //Goes through the exits list in the location and returns the value of where_to that the exit holds
        //Updates the current location of the explorer
        void move(std::string name, Crawlspace inputCrawlspace);

        //take in a string of a name of an exit or treasure
        //prints the descriptio of the exit or treasure
        void examine(std::string name, Crawlspace inputCrawlspace);

        //call the takeme function 
        //add the score of the treasure to the score
        void take(std::string name, Crawlspace inputCrawlspace);
        
};

#endif