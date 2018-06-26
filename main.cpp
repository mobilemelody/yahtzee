#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Scorecard.hpp"
#include "Player.hpp"
#include "Dice.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;

int main() {
  char confirm;
  string reroll;
  int category, rolls, rounds = 0;
  unsigned seed;
  seed = time(0);
  srand(seed);

  // Setup game
  Scorecard game;
  Dice dice;
  Player player1("Melody");
  game.addPlayer(&player1);
  game.print();
  cout << endl;

  // Play game
  while (rounds < 13) {
    dice.rollAll();
    dice.printValues();
    rolls = 1;
    cout << "Enter dice numbers to reroll (or enter 0 if you do not want to reroll any dice): ";
    getline(cin, reroll);
    cout << endl;
    while (rolls < 3 && reroll != "0") {
      for (int i = 0; i < reroll.length(); i++) {
        string ch = reroll.substr(i, 1);
        if (ch != " ") {
          dice.roll(stoi(ch) - 1);
        }
      }
      dice.printValues();
      rolls++;
      if (rolls < 3) {
        cout <<"Enter dice numbers to reroll (or enter 0 if you do not want to reroll any dice): ";
        getline(cin, reroll);
        cout << endl;
      }
    }

    confirm = 'n';
    while (confirm != 'y') {
      cout << "In which category do you want to record your score? ";
      cin >> category;
      if (player1.getScore(category) > -1) {
        cout << "This category has already been used. ";
        confirm = 'n';
      }
      else {
        cout << "This category will give you " << dice.getScore(category) << " points. Do you want to continue?  ('y' or 'n'):";
        cin >> confirm;
        cin.ignore();
      }
    }
    cout << endl;
    
    bool flag = player1.setScore(category, dice.getScore(category));
    while (!flag) {
      cout << "In which category do you want to record your score? ";
    }
    rounds++;
    game.print();
    cout << endl;
  }

  return 0;
}
