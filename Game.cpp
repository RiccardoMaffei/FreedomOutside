/* 
 * File:   Game.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.59
 */

#include "Game.hpp"
#include "ConsoleView.hpp"

Game::Game() {
    //call the constructor with number of player = 4
    Game(4);
}


Game::~Game() {
    //destruct the map
    delete (this -> map);
    //delete the view
    delete (this -> view);
    //for the list size
    for (int i = 0; i < (this -> playerList -> getSize()); i++) {
        //delete the player
        delete (this -> playerList -> get(i));
    }
    //delete the list
    delete (this -> playerList);
}

Game::Game(int nPlayer) {
    //if nPlayer is less than 2
    if(nPlayer < 2){
        //set as 2
        nPlayer = 2;
    }
    //save the number of player
    this -> nPlayer = nPlayer;
    //get the map singleton instance
    this -> map = Map::getInstance();
    //instance the view
    this -> view = new ConsoleView();
}

void Game::play() {
    
}
