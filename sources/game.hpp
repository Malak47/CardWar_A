//
// Created by malaklinux on 3/27/23.
//

#ifndef S_S_B_2A_GAME_H
#define S_S_B_2A_GAME_H

#include "player.hpp"
#include <string>

using namespace std;

namespace ariel {
    class Game {
    private:
        Player &player1, &player2;

    public:
        Game();

        Game(Player &player1, Player &player2);

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();
    };
}
#endif //S_S_B_2A_GAME_H