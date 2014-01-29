//Ali Kooshesh and Lauryn Loudermilk
#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"
#include "PointScore.hpp"
#include "Game.hpp"

TieBreaker::TieBreaker( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *TieBreaker::play( Player *p ) {
    //for switching server
    bool shouldSwitch = false;
    
    TieBreakerScore *score = new TieBreakerScore(player1(),player2());
    score->addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner());
    p = p->otherPlayer(p);
    
    while (!score->haveAWinner()){
        score->addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner());
        if (shouldSwitch)
            p = p->otherPlayer(p);
        //this works to switch servers every other serve
        shouldSwitch = !shouldSwitch;
    }
    return score;
}