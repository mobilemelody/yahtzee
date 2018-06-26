/********************************************************************* 
** Author: Melody Reebs
** Date: 06/08/2018
** Title: Yahtzee
** Description: Scorecard class specification file
*********************************************************************/

#ifndef SCORECARD_HPP
#define SCORECARD_HPP

#include <iostream>
#include <vector>
#include "Player.hpp"
using std::cout;
using std::endl;
using std::vector;

class Scorecard {
  private:
    vector<Player *> players;
    int numPlayers;
  public:
    // Constructors
    Scorecard();

    // Methods
    void addPlayer(Player *playerPtr);
    void print();
};

#endif
