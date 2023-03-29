//
// Created by malaklinux on 3/27/23.
//
#include <string>
#include "player.hpp"

using namespace std;
namespace ariel {
    Player::Player() {
        this->name = "Unknown" + std::to_string(std::rand() % 10 + 1);  //Giving the player name: Unknown+random number
        this->left_cards = 26;
        this->won_cards = 0;
        this->win_rate = 0;
    }

    Player::Player(string name) {
        this->name = name;
        this->left_cards = 26;
        this->won_cards = 0;
        this->win_rate = 0;
    }

    void Player::setName(string name) {
        this->name = name;
    }

    void Player::setRate(double rate) {
        this->win_rate = rate;
    }

    string Player::getName() {
        return this->name;
    }

    int Player::stacksize() {
        return this->left_cards;
    }

    int Player::cardesTaken() {
        return this->won_cards;
    }

    double Player::getRate() {
        return this->win_rate;
    }
}