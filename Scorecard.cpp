/********************************************************************* 
** Author: Melody Reebs
** Date: 06/08/2018
** Title: Yahtzee
** Description: Scorecard class implementation file
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Scorecard.hpp"
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::setw;
using std::left;

// Default constructor
Scorecard::Scorecard() {
  numPlayers = 0;
}

// Add player to game
void Scorecard::addPlayer(Player *playerPtr) {
  players.push_back(playerPtr);
  numPlayers++;
}

// Print the current scorecard
void Scorecard::print() {
  // Create separation line strings
  int firstCol = 15;
  string line, totLine, col;
  line.assign(numPlayers * 6 + firstCol + 2, '-');
  totLine.assign(numPlayers * 6 + firstCol + 2, '=');
  col = " | ";
  
  // Print scorecard header with player names
  cout << left << "Yahtzee scorecard" << endl;
  cout << totLine << endl;
  cout << setw(firstCol) << "Players";
  for (int i = 0; i < numPlayers; i++) {
    cout << col << players[i]->getInitials();
  }
  cout << endl;
  cout << line << endl;
  
  // Print upper section scores
  string upperLabels[] = {" 1. Aces", " 2. Twos", " 3. Threes", " 4. Fours", " 5. Fives", " 6. Sixes"};
  cout << "UPPER SECTION" << endl;
  cout << line << endl;
  for (int j = 0; j < 6; j++) {
    cout << setw(firstCol) << upperLabels[j];
    for (int i = 0; i < numPlayers; i++) {
      int score = players[i]->getUpperScore(j);
      cout << col;
      if (score > 0) {
        cout << setw(3) << score;
      }
      else if (score == 0) {
        cout << setw(3) << "X";
      }
      else {
        cout << setw(3) << "-";
      }
    }
    cout << endl;
  }
  cout << line << endl;
  
  // Print upper section subtotal and total
  cout << setw(firstCol) << "Subtotal";
  for (int i = 0; i < numPlayers; i++) {
    cout << col << setw(3) << players[i]->getUpperSubTotal();
  }
  cout << endl;
  cout << setw(firstCol) << "Upper Total";
  for (int i = 0; i < numPlayers; i++) {
    cout << col << setw(3) << players[i]->getUpperTotal();
  }
  cout << endl << line << endl;
  
  // Print lower section scores
  string lowerLabels[] = {" 7. 3 of a Kind", " 8. 4 of a Kind", " 9. Full House", "10. 4 in a Row", "11. 5 in a Row", "12. Yahtzee", "13. Chance"};
  cout << "LOWER SECTION" << endl;
  cout << line << endl;
  for (int j = 0; j < 7; j++) {
    cout << setw(firstCol) << lowerLabels[j];
    for (int i = 0; i < numPlayers; i++) {
      int score = players[i]->getLowerScore(j);
      cout << col;
      if (score > 0) {
        cout << setw(3) << score;
      }
      else if (score == 0) {
        cout << setw(3) << "X";
      }
      else {
        cout << setw(3) << "-";
      }
    }
    cout << endl;
  }
  cout << line << endl;

  // Print lower section subtotal and total
  cout << setw(firstCol) << "Subtotal";
  for (int i = 0; i < numPlayers; i++) {
    cout << col << setw(3) << players[i]->getLowerSubTotal();
  }
  cout << endl;
  cout << setw(firstCol) << "Lower Total";
  for (int i = 0; i < numPlayers; i++) {
    cout << col << setw(3) << players[i]->getLowerTotal();
  }

  // Print grand total
  cout << endl << totLine << endl;
  cout << setw(firstCol) << "GRAND TOTAL";
  for (int i = 0; i < numPlayers; i++) {
    cout << col << setw(3) << players[i]->getTotalScore();
  }
  cout << endl << totLine << endl;
}
