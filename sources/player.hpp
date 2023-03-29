//
// Created by malaklinux on 3/27/23.
//

#ifndef S_S_B_2A_PLAYER_H
#define S_S_B_2A_PLAYER_H

#include <string>

using namespace std;

namespace ariel {
    class Player {
    private:
        string name;
        int left_cards;
        int won_cards;
        double win_rate;
    public:
        Player();

        Player(string name);

        void setName(string name);

        int stacksize();

        int cardesTaken();

        string getName();

        void setRate(double rate);

        double getRate();
    };
}
#endif //S_S_B_2A_PLAYER_H