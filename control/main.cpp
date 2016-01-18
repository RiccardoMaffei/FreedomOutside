/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   main.cpp
 * Author: Danilo Branca
 * Author: Riccardo Maffei
 * Author: Federico Bertani
 *
 * Created on 15 dicembre 2015, 09.00
 */

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "../control/Game.hpp"

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
        //set the should start as true
        shouldStart = true;
    }
    //if the number of args is equal to 3 (argc > 3)
    else if(argc == 3){
        //if user types "-n" or "--number-of-players" parameter correctly
        if(strcmp(argv[1], "-n")==0 || strcmp(argv[1], "--number-of-players")==0){
            //if user types a number after the "-n" or "--number-of-players" parameter (123abc is accepted as 123))
            if(isdigit(argv[2][0])){
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
        //when here the game is ended so delete game
        delete g;
    }
    //if user made some mistakes during invocation
    else{
        //print an error and show usage
        cout << "Usage: " << argv[0] << "[(-n | --number-of-players) <number of player (greater than 1)>] \n";
    }
    return 0;
}

