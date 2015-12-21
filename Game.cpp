/* 
 * File:   Game.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.59
 */

#include "Game.hpp"

Game::Game() {
    //call the constructor with number of player = 4
    Game(4);
}


Game::~Game() {
}

Game::Game(int nPlayer) {
    //save the number of player
    this -> nPlayer = nPlayer;
    //get the map singleton instance
    this -> map = Map::getInstance();
    //instance the view
    this -> view = new ConsoleView();
}

void Game::play() {

}
