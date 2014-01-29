//Ali Kooshesh and Lauryn Loudermilk
#include "Set.hpp"
#include "SetScore.hpp"
#include "Game.hpp"
#include "GameScore.hpp"
#include "TieBreaker.hpp"

Set::Set( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *Set::play( Player *p ) {
    SetScore *score = new SetScore(player1(),player2());
    while (!score->haveAWinner())
    {
        Game *game = new Game(player1(),player2());
        Score *gameScore = game->play(p);
        score->addScore(p);
        delete game;
        p = p->otherPlayer(p);
        if(score->shouldPlayATieBreaker()){
            TieBreaker* tie = new TieBreaker(player1(),player2());
            score->addTieScore(reinterpret_cast<TieBreakerScore *>(tie->play(p)));
            break;
        }
    }
    return score;
}