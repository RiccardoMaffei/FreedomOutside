/* 
 * File:   main.cpp
 * Author: Danilo Branca
 * Author: Riccardo Maffei
 * Author: Federico Bertani
 *
 * Created on 15 dicembre 2015, 09.00
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "Game.hpp"

using namespace std;

/**
 * This is the launch function main. It takes care of the console args and starts the game.
 */

int main(int argc, char* argv[]) {
    //set the number of players to 4 as default
    int nPlayer = 4;
    //flag that determinate if the game should start or not
    bool shouldStart = false;
    //if there is only one argument, i.e. user wants the game to run with the default number of players.
    if(argc == 1){
        //game runs with the default number of players
        //set the shouls start as true
        shouldStart = true;
    }
    //if the number of args is equal to 3 (argc > 3)
    else if(argc == 3){
        //if user types "-n" or "--number-of-players" parameter correctly
        if(strcmp(argv[1], "-n")==0 || strcmp(argv[1], "--number-of-players")==0){
            //if user types a number after the "-n" or "--number-of-players" parameter
            if(isdigit(argv[2])){
                //if user types a valid number
                if(atoi(argv[2])>1){
                    //set the should start as true
                    shouldStart = true;
                    //set the number of player given in console
                    nPlayer = atoi(argv[2]);
                }
            }   
        }   
    }
    //if user invokes the game correctly
    if(shouldStart){
        //instance a game with the number of player
        Game* g = new Game(nPlayer);
        //play the game
        g->play();
    }
    //if user made some mistakes during invocation
    else{
        //print an error and show usage
        cout << "Usage: " << argv[0] << "[(-n | --number-of-players) <number of player (greater than 1)>] \n";
    }
    return 0;
}

