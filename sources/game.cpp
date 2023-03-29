//
// Created by malaklinux on 3/27/23.
//
#include "game.hpp"
#include <string>

using namespace std;


namespace ariel {
    Game::Game() : player1(*new Player()), player2(*new Player()) {
        player1.setName("Player1");
        player2.setName("Player2");
    }

    Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2) {
        this->player1 = player1;
        this->player2 = player2;
    }

    void Game::playAll() { return; }

    void Game::playTurn() { return; }

    void Game::printLastTurn() { return; }

    void Game::printLog() { return; }

    void Game::printStats() { return; }

    void Game::printWiner() { return; }
}