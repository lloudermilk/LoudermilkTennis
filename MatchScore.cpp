//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>

#include "MatchScore.hpp"
#include "SetScore.hpp"

using namespace std;

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}

bool MatchScore::haveAWinner()  {
    //Taken from tennis.cpp
    return player1Score() == 3 || player2Score() == 3;
}

void MatchScore::addScore( Score *score ) {
    scores[setNumber] = reinterpret_cast<SetScore *>(score);
    setNumber++;
    //This line is necesary to increment the player's scores
    score->getWinner() == player1() ? p1Score++ : p2Score++;
}

void MatchScore::print() {
    //Altered to reflect tennis.cpp's output
    cout << "   Set No.    Player A          Player B\n";
    for( int i = 0; i < setNumber; i++ ){
        cout << setw(7) << i+1;
        scores[i]->print();
        cout << endl;
    }
}

MatchScore::~MatchScore() {
    for( int i = 0; i < setNumber; i++ )
        delete scores[i];
}
