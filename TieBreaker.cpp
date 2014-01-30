//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"
#include "PointScore.hpp"
#include "Game.hpp"

TieBreaker::TieBreaker( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *TieBreaker::play( Player *p ) {
    //for switching the server
    bool shouldSwitch = false;
    
    TieBreakerScore *score = new TieBreakerScore(player1(),player2());
    //this line is tricky because of the recast needed, since serveAPoint returns
    //the wrong object. a player is returned form serveAPoint, and a score is needed
    //to determine the winner. then i am adding the score of the winner of the point served
    //to the score array.
    score->addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner());
    //change server for the first time
    p = p->otherPlayer(p);
    //now play again until we have a winner, changing servers every other serve
    while (!score->haveAWinner()){
        //play again with the same typecast as before
        score->addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner());
        //determine if you should switch servers
        if (shouldSwitch)
            p = p->otherPlayer(p); //switch if necessary
        //this works to switch servers every other serve
        shouldSwitch = !shouldSwitch;
    }
    //return the score object
    return score;
}