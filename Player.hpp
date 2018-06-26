/********************************************************************* 
** Author: Melody Reebs
** Date: 06/08/2018
** Title: Yahtzee
** Description: Player class specification file
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using std::string;

class Player {
  private:
    string name;
    int upperScores[6];
    int lowerScores[7];
    int yahtzeeBonus;
  
  public:
    // Constructors
    Player(string);

    // Methods
    void setName(string);
    bool setScore(int, int);
    string getName();
    string getInitials();
    int getScore(int);
    int getUpperScore(int);
    int getLowerScore(int);
    int getUpperSubTotal();
    int getUpperTotal();
    int getLowerSubTotal();
    int getLowerTotal();
    int getTotalScore();
};

#endif
