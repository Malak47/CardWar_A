//
// Created by malaklinux on 3/28/23.
//

#include <iostream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"

using namespace std;
using namespace ariel;

Player player1("Player1");
Player player2("Player2");
Game game(player1, player2);

TEST_CASE("Start of each Game") {
    CHECK(player1.getName() == "Player1");
    CHECK(player1.stacksize() == 26);
    CHECK(player1.cardesTaken() == 0);
    player1.setName("Shushe");
    CHECK(player1.getName() == "Shushe");

    CHECK(player2.getName() == "Player2");
    CHECK(player2.stacksize() == 26);
    CHECK(player2.cardesTaken() == 0);
    player2.setName("lily");
    CHECK(player2.getName() == "lily");
}

TEST_CASE("After one round") {
    game.playTurn();
    CHECK(player1.stacksize() == 25);       //player 1 won the first round
    CHECK(player1.cardesTaken() == 1);

    CHECK(player2.stacksize() == 25);
    CHECK(player2.cardesTaken() == 0);

    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printLog());

}

TEST_CASE("After 10 rounds") {
    for (int i = 0; i < 9; ++i) {
        game.playTurn();
    }
    CHECK(player1.stacksize() == 14);
    CHECK(player1.cardesTaken() == 6);

    CHECK(player2.stacksize() == 14);
    CHECK(player2.cardesTaken() == 6);

    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printLog());

    CHECK(player1.stacksize() == player2.stacksize());
}

TEST_CASE("Default Constructor") {
    Player player3;
    Player player4;
    player3.setName("Unknown1");
    player4.setName("Unknown2");
    REQUIRE(player3.getName() == "Unknown1");
    REQUIRE(player4.getName() == "Unknown2");
}


TEST_CASE("Only one player joined the game") {
    CHECK_THROWS(Game{player1, player1});
    // CHECK_THROWS(Game{player1, NULL});
    CHECK_THROWS(Game{player2, player2});
    //CHECK_THROWS(Game{NULL, player2});
}

TEST_CASE("One of the players doesn't have a name") {
    Player NullPlayer("");
    CHECK_THROWS(Game{player1, NullPlayer});
}

TEST_CASE("End of the game and one Player still has cards left") {
    Game game2(player1, player2);
    CHECK_NOTHROW(game2.playAll());

    bool CardsLeft = player1.stacksize() != player2.stacksize();
    CHECK(CardsLeft);
}

TEST_CASE("Printing the winner at the first round") {
    Game game2(player1, player2);
    CHECK_THROWS(game2.printWiner());
}

TEST_CASE("Play one or more rounds after the game has ended") {
    Game game2(player1, player2);
    CHECK_NOTHROW(game2.playAll());
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());
}

TEST_CASE("Player wins the game although the other player has higher win_rate") {
    Game game2(player1, player2);
    CHECK_NOTHROW(game2.playAll());

    //We assume that player1 is the winner.
    //but player2 has more win rate
    bool rate = player1.getRate() < player2.getRate();
    CHECK(rate);
}
