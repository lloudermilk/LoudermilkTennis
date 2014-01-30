//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include "Game.hpp"
#include "Score.hpp"
#include "GameScore.hpp"
#include "PointScore.hpp"

Game::Game( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *Game::play( Player *p ) {
    //Create a new score object of GameScore type
    Score *score = new GameScore( player1(), player2() );
    
    //Play until we have a winner
    while( !score->haveAWinner() ) {
        //Pointscore object (recasted from score object) to hold scores per game
        PointScore *pointScore = reinterpret_cast<PointScore *>( p->serveAPoint() );
        //Add the score of the winner to the score array
        score->addScore( pointScore->getWinner() );
        //Free the memory
        delete pointScore;
    }
    //Return the score
    return score;
}

