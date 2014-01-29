//Ali Kooshesh and Lauryn Loudermilk
#include "Set.hpp"
#include "SetScore.hpp"
#include "Game.hpp"
#include "GameScore.hpp"
#include "TieBreaker.hpp"

Set::Set( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *Set::play( Player *p ) {
    //score for the set
    SetScore *score = new SetScore(player1(),player2());
    //keep playing until there is a "winner"
    while (!score->haveAWinner())
    {
        Game *game = new Game(player1(),player2());
        Score *gameScore = game->play(p);
        //determine score
        score->addScore(gameScore->getWinner());
        //no longer needed, so delete
        delete game;
        //this must be done before the tiebreaker is played
        p = p->otherPlayer(p);
        //determine if tiebreaker is needed
        if(score->shouldPlayATieBreaker()){
            //create a new tiebreaker
            TieBreaker* tie = new TieBreaker(player1(),player2());
            //recast the score to work with the score array
            score->addTieScore(reinterpret_cast<TieBreakerScore *>(tie->play(p)));
            //break!
            break;
        }
    }
    return score;
}