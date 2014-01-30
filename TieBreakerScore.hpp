//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#ifndef _TieBreakerScore_hpp
#define _TieBreakerScore_hpp

#include "Score.hpp"
#include "Player.hpp"

/**  The player who scores at least 7 points and is ahead by at least
 *  2 points wins a tie-breaker.
 */

class TieBreakerScore: public Score {
public:
    TieBreakerScore( Player *p1, Player *p2 );
    //I declared two new functions below
    bool haveAWinner();
    void print();

};

#endif
