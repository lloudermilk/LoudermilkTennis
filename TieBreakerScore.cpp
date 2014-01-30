//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include "TieBreakerScore.hpp"
#include <iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

TieBreakerScore::TieBreakerScore( Player *p1, Player *p2 ): Score(p1, p2) {}

bool TieBreakerScore::haveAWinner() {
    //must be implemented here since a tie winner requires a
    //different score than a regular win
    return (player1Score() >= 7 || player2Score() >= 7)
    && abs(player1Score() - player2Score()) >= 2;
}

void TieBreakerScore::print(){
    //implemented to print tiebreakers when printing sets
    cout << setw(16) << "(tie breaker  " << player1Score() << "-" << player2Score() << ")";
}