//
// Created by malaklinux on 3/27/23.
//

#ifndef S_S_B_2A_PLAYER_H
#define S_S_B_2A_PLAYER_H
#include <string.h>
class player {
private:
    string name;
    int left_cards;
    int won_cards;
public:
    player();
    player(name);

    string getName();
    int stacksize();
    int cardesTaken();

};
#endif //S_S_B_2A_PLAYER_H
