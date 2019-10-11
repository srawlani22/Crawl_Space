#include <iostream>
#include "object.h"
#include "exit.h"
#include "treasure.h"
#include "location.h"
#include "crawlspace.h"
#include "explorer.h"

int main(){
    Location room ("Room", "You are in a room"); //instance of a location
    Location hallway ("Hallway", "You are in a dim hallway"); //instance of a location
    Location* roomCopy = &room; 
    Location* hallwayCopy = &hallway; 

    Exit door (1, "door", "There is a door"); //instance of the exit being placed in the room
    Exit sewageTunnel (1, "sewage tunnel", "There is a sewage tunnel opening"); //instance of an exit being placed in the hallways
    Exit window (0, "window", "There is a window"); 
    Treasure keys ("keys", "There are keys", 5); //instance of a treasure that will be put in the room
    Treasure coins ("coins", "There are gold coins", 5); //instance of a treasure that will be put in the room
    
    Crawlspace crawlspace; //create an instance of a crawlspace
    crawlspace.addLocation(roomCopy); //add the room to the crawlspace
    crawlspace.addLocation(hallwayCopy); //add the hallway to the crawlspace

    crawlspace.setStart(0); //set the start location to be 0 which is the room

    crawlspace.updateLoc(door, 0); //dig the exit in the room
    crawlspace.updateLoc(sewageTunnel, 0); //dig the exit in the room
    crawlspace.updateLoc(window, 1); //dig a window in hallway

    //put the keys and coins in the room
    crawlspace.updateLoc(keys, 0); 
    crawlspace.updateLoc(coins, 0);

    //print descriptions of the room and hallway to show the creation of the crawlspace
    std::cout << "Description of the crawlspace" << std::endl;
    room.describe();
    std::cout << std::endl;
    hallway.describe();

    std::cout << std::endl<< std::endl;

    Explorer sparsh("Sparsh", crawlspace); //create an instance of an explorer set in the crawlspace

    sparsh.examine("keys", crawlspace); //proving that there is nothing left once the treasure is picked up
    sparsh.examine("door",crawlspace);
    sparsh.getScore();
    sparsh.examine("Room", crawlspace); //look at everthing in the current location
    sparsh.take("keys", crawlspace); //pickup the keys
    sparsh.examine("door", crawlspace); //look at the door
    sparsh.take("door", crawlspace); //try to take the door
    sparsh.move("door", crawlspace); //move through the door

}