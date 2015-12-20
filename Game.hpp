/* 
 * File:   Game.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.59
 */

#ifndef GAME_HPP
#define	GAME_HPP

class Game {
public:
    Game();
    
    virtual ~Game();
    
    /**
     * Runs the game. This method contains the main game loop functionalities.
     * @param nPlayers int: number of players.
     */
    void play(int nPlayers);
private:

};

#endif	/* GAME_HPP */

