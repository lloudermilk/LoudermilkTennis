//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>

#include "SetScore.hpp"

using namespace std;

SetScore::SetScore( Player *p1, Player *p2 ): Score(p1, p2), tieScore(0) {}
  
bool SetScore::haveAWinner() {
    //taken from tennis.cpp
    return (player1Score() >= 6 || player2Score() >= 6)
    && abs(player1Score() - player2Score()) >= 2;
}

bool SetScore::shouldPlayATieBreaker() {
    //taken from tennis.cpp
    return player1Score() == 6 && player2Score() == 6;
}

void SetScore::addTieScore( TieBreakerScore *score ) {
    addScore( score->getWinner() );
    this->tieScore = score;
}

void SetScore::print() {
    //altered to refect output of tennis.cpp
    cout << setw(10) << player1Score() << setw(18) << player2Score();
    if( tieScore != NULL )
      tieScore->print();
}
