/********************************************************************* 
** Author: Melody Reebs
** Date: 06/08/2018
** Title: Yahtzee
** Description: Player class implementation file
*********************************************************************/

#include <string>
#include "Player.hpp"
using std::string;

Player::Player(string nm = "Player") {
  name = nm;
  yahtzeeBonus = 0;
  for (int i = 0; i < 6; i++) {
    upperScores[i] = -1;
  }
  for (int i = 0; i < 7; i++) {
    lowerScores[i] = -1;
  }
}

void Player::setName(string nm) {
  name = nm;
}

bool Player::setScore(int category, int val) {
  if (category < 7) {
    if (upperScores[category - 1] < 0) {
      upperScores[category - 1] = val;
      return true;
    }
    else {
      return false;
    }
  }
  else {
    if (lowerScores[category - 7] < 0) {
      lowerScores[category - 7] = val;
      return true;
    }
    else if (category == 12 && lowerScores[category - 7] > 0 && val > 0) {
      yahtzeeBonus++;
    }
    else {
      return false;    }
  }
}

string Player::getName() {
  return name;
}

string Player::getInitials() {
  return name.substr(0, 3);
}

int Player::getScore(int category) {
  if (category < 7) {
    return upperScores[category - 1];
  }
  else {
    return lowerScores[category - 7];
  }
}

int Player::getUpperScore(int index) {
  return upperScores[index];
}

int Player::getLowerScore(int index) {
  return lowerScores[index];
}

int Player::getUpperSubTotal() {
  int sum = 0;
  for (int i = 0; i < 6; i++) {
    if (upperScores[i] > 0) {
      sum += upperScores[i];
    }
  }
  return sum;
}

int Player::getUpperTotal() {
  int subTotal = getUpperSubTotal();
  if (subTotal >= 63) {
    return subTotal + 35;
  }
  else {
    return subTotal;
  }
}

int Player::getLowerSubTotal() {
  int sum = 0;
  for (int i = 0; i < 7; i++) {
    if (lowerScores[i] > 0) {
      sum += lowerScores[i];
    }
  }
  return sum;
}

int Player::getLowerTotal() {
  return getLowerSubTotal() + (yahtzeeBonus * 100);
}

int Player::getTotalScore() {
  return getUpperTotal() + getLowerTotal();
}

