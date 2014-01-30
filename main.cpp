//Lauryn Loudermilk
//Project 1 - CS470
//Object Oriented Tennis Simulator
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
#include "Player.hpp"
#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"
#include "SetScore.hpp"

/*
 The program simulates a tennis match.  It first draws a random
 number to decide which of the two players serves the first game of
 the match.  Given the probability of player A winning a point
 against player B if she is serving, the function `point' decides
 the outcome of the point.  To make the program more realistic, one
 needs to change the way the function `point' decides which player
 wins a point.
 
 The rules of the game are:
 
 A match is won by the first player to win 3 sets.  A set is won by
 the first player to win 6 games if ahead by two games. If the set
 reaches a score of 6-5, another game is played.  If the player who
 is ahead wins that game, the set is over, won by a score of 7-5.
 Otherwise the score is 6-6 and a tie breaker is played. The winner
 of the tie breaker is the winner of the set 7-6.
 
 Players alternate who serves a game. The server is the player who
 first hits the ball. Player also alternate who serves the first
 game of a set.  A game is won by the first player to get at
 least 4 points and be ahead by two points. Tennis uses a strange
 way of counting points.  We can simply count points by 0,1,2,...
 
 Points are the basic unit of play.  A point consists of a player
 putting the ball into play (serving) followed by the two players
 hitting it back and forth until something goes wrong such as the
 ball is hit out of bounds.
 
 A tie breaker is a game in which the first player to score at least
 seven and be ahead by two wins.  The service in a tie breaker
 alternates. The player whose turn it would be to serve in a normal
 game serves once. Thereafter the players alternate serving twice
 until the tie breaker is over.
 
 Written by: Ali A. Kooshesh
 Edited by: Lauryn Loudermilk
 */


int main()
{
    int prob1 = 70;
    int prob2 = 70;
    
    srand( getpid() );
    int randSeed;
    
    std::cout << "Enter a seed for the random-number generator ";
    std::cin >> randSeed;
    srand( randSeed );
    
    Player *p1 = new Player( prob1 );
    Player *p2 = new Player( prob2 );
    
    //The only changes I made were going from game to match below
    Match *match = new Match( p1, p2 );
    Score *score = match->play( p1 );
    score->print();
    
    delete match;
    delete  reinterpret_cast<MatchScore *>(score);
    delete p1;
    delete p2;
    
    return 0;
}
