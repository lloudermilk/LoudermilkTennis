//Ali Kooshesh and Lauryn Loudermilk
#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"

Match::Match( Player *p1, Player *p2 ): Competition( p1, p2 ) {}
Score *Match::play( Player *p ) {
    
    MatchScore *score = new MatchScore (player1(), player2());
    
    while( !score->haveAWinner() ) {
        Set *set = new Set (player1(), player2());
        Score *setScore = set->play(p);
        score->addScore(setScore);
        delete set;
        p = p->otherPlayer(p);
    }
    return score;
}