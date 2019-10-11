////////////////////////////////
// title: Explorer.cpp
// descr: Implementation an Explorer header file
//
// Author: Nora Riches and Sparsh Rawlani
// Assisted by Scott Griffith in some problems
// Last updated: 10/1/2019
////////////////////////////////

#include "explorer.h"
#include "treasure.h"
#include "exit.h"
#include "object.h"
#include "location.h"

Explorer::Explorer(std::string inputName, Crawlspace inputCrawlspace){
    name = inputName;
    score = 0;
    currentLoc = inputCrawlspace.getStart(); //set the current location of the explorer to where the crawlspace says to start
}

std::string Explorer::getName(){//getter function returns name
    return name;
}

int Explorer::getLocation(){// getter functions returns location
    return currentLoc;
}

int Explorer::getScore(){//getter function retuns score
    return score;
}

void Explorer::setName(std::string inputName){// setter functions sets the name
    name = inputName;
}

void Explorer::updateLoc (int loc){// update location update the location using the int that we have
    currentLoc = loc;
}

void Explorer::move(std::string name, Crawlspace inputCrawlspace){
    Location* curLoc = inputCrawlspace.getLocation(currentLoc); //look at the location where the explorere currently is
    Object* foundExit = curLoc -> findExit(name); //set a pointer to an exit that is in the location
    updateLoc(foundExit -> getValue()); //update the location of the explorer
    examine("Room", inputCrawlspace); //print out the contents of the new area
}

void Explorer::examine(std::string name, Crawlspace inputCrawlspace){
    Location* curLoc = inputCrawlspace.getLocation(currentLoc); //look at the location where the explorer currently is
    if (name == "Room"){ //print out the contents of the current space if the user commanded that
        curLoc -> describe();
    }
    else if (curLoc -> findTre(name) != nullptr){ //describe the treasure if the name is a treasrue
        Object* examiningTre = curLoc -> findTre(name);
        examiningTre -> describeme();
    }
    else if (curLoc -> findExit(name) != nullptr){ //describe the exit if the name is an exit
        Object* examiningExit = curLoc -> findExit(name);
        examiningExit -> describeme();
        
    }
}

void Explorer::take(std::string name, Crawlspace inputCrawlspace){
    ////////////PICKUP IS INTERACTING CORRECTLY
    Location * curLoc = inputCrawlspace.getLocation(currentLoc);//look at the location where the explorer currently is
    Object* pickingUp = curLoc -> findTre(name); //set a pointer the the treasure we are taking
    score += pickingUp -> getValue(); //add the score of the treasure to the score of the explorer
    curLoc -> pickup(name); //call the pickup fucntion 
}