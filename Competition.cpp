//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator

#include "Competition.hpp"
#include "Player.hpp"

Competition::Competition( Player *player1, Player *player2 ): p1( player1 ), p2 ( player2 ) {}

Player *Competition::player1() { return p1; }
Player *Competition::player2() { return p2; }
