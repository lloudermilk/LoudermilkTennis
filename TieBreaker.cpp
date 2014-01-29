//Ali Kooshesh and Lauryn Loudermilk
#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"
#include "Game.hpp"

TieBreaker::TieBreaker( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *TieBreaker::play( Player *p ) {
    Score *score = new TieBreakerScore(player1(),player2());
    bool shouldSwitch = false;
    while (!score->haveAWinner())
    {
        Game *game = new Game(player1(),player2());
        Score *gameScore = game->play(p);
        score->addScore(p);
        delete game;
        if (shouldSwitch)
            p = p->otherPlayer(p);
        //this works to switch servers every other serve
        shouldSwitch = !shouldSwitch;
    }
    return score;
}
