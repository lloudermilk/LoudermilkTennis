//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include "Set.hpp"
#include "SetScore.hpp"
#include "Game.hpp"
#include "GameScore.hpp"
#include "TieBreaker.hpp"

Set::Set( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *Set::play( Player *p ) {
    //Score object for the set
    SetScore *score = new SetScore(player1(),player2());
    //keep playing until there is a winner
    while (!score->haveAWinner()){
        //Make a new game
        Game *game = new Game(player1(),player2());
        //score object for the game
        Score *gameScore = game->play(p);
        //add the winner's game score to the score array
        score->addScore(gameScore->getWinner());
        //free the memory
        delete game;
        //change servers before the tiebreaker is played
        p = p->otherPlayer(p);
        //determine if tiebreaker is needed
        if(score->shouldPlayATieBreaker()){
            //create a new tiebreaker object
            TieBreaker* tie = new TieBreaker(player1(),player2());
            //recast the score to work with the score array
            score->addTieScore(reinterpret_cast<TieBreakerScore *>(tie->play(p)));
            //break once winner is determined
            break;
        }
    }
    return score;
}