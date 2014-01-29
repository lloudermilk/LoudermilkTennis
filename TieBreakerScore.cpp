//Ali Kooshesh and Lauryn Loudermilk
#include "TieBreakerScore.hpp"
#include <iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

TieBreakerScore::TieBreakerScore( Player *p1, Player *p2 ): Score(p1, p2) {}

bool TieBreakerScore::haveAWinner() {
    return (player1Score() >= 7 || player2Score() >= 7)
    && abs(player1Score() - player2Score()) >= 2;
}

void TieBreakerScore::print(){
    cout << setw(16) << "(tie breaker  " << player1Score() << "-" << player2Score() << ")";
}