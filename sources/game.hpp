//
// Created by malaklinux on 3/27/23.
//

#ifndef S_S_B_2A_GAME_H
#define S_S_B_2A_GAME_H
#include "player.hpp"
class game{
private:
    player& p1, p2;


public:
    game(){};
    game(p1,p2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};

#endif //S_S_B_2A_GAME_H
