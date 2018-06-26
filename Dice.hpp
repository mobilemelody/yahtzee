/********************************************************************* 
** Author: Melody Reebs
** Date: 06/08/2018
** Title: Yahtzee
** Description: Dice class specification file
*********************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

class Dice {
  private:
    int currentValues[5];

  public:
    // Methods
    int roll(int);
    void rollAll();
    int getValue(int);
    int* getValArray();
    void printValues();
    int calcSum();
    int calcUpper(int);
    int calcNumofKind(int);
    int calcNuminRow(int);
    int calcFullHouse();

    int getScore(int);

    // For testing
    void setValues(int, int, int, int, int);
};

#endif
