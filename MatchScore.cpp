//Ali Kooshesh and Lauryn Loudermilk
#include "MatchScore.hpp"
#include "SetScore.hpp"

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}

bool MatchScore::haveAWinner()  {
    return player1Score() == 3 || player2Score() == 3;
}

void MatchScore::addScore( Score *score ) {
    scores[setNumber] = reinterpret_cast<SetScore *>(score);
    setNumber++;
}

void MatchScore::print() {
    for( int i = 0; i < setNumber; i++ )
      scores[i]->print();
}

MatchScore::~MatchScore() {
    for( int i = 0; i < setNumber; i++ )
      delete scores[i];
}
