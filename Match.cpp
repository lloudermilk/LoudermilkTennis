//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"

Match::Match( Player *p1, Player *p2 ): Competition( p1, p2 ) {}
Score *Match::play( Player *p ) {
    //New score object of type MatchScore
    MatchScore *score = new MatchScore (player1(), player2());
    //Play until there's a winner
    while( !score->haveAWinner() ) {
        //In each match we play sets, so create a new set object for each set you play
        Set *set = new Set (player1(), player2());
        //A score object to hold the score for the set with the value of the
        //player's score after finishing the set
        Score *setScore = set->play(p);
        //Add the score to the score array
        score->addScore(setScore);
        //Free the memory
        delete set;
        //Change server
        p = p->otherPlayer(p);
    }
    //return the score object
    return score;
}