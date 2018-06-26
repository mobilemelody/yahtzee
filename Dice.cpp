/********************************************************************* 
** Author: Melody Reebs
** Date: 06/08/2018
** Title: Yahtzee
** Description: Dice class implementation file
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Dice.hpp"
using std::cout;
using std::endl;
using std::string;

int Dice::roll(int index) {
  currentValues[index] = rand() % 6 + 1;
  return currentValues[index];
}

void Dice::rollAll() {
  for (int i = 0; i < 5; i++) {
    roll(i);
  }
}

int Dice::getValue(int index) {
  return currentValues[index];
}

int* Dice::getValArray() {
  return currentValues;
}

void Dice::printValues() {
  cout << "Your roll: " << endl;
  string line;
  line.assign(13, '-');
  cout << line << endl;
  for (int i = 0; i < 5; i++) {
    cout << "Dice " << i + 1 << " | " << " " << currentValues[i] << " ";
    cout << endl << line << endl;
  }
}

int Dice::calcSum() {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += currentValues[i];
  }
  return sum;
}

int Dice::calcUpper(int val) {
  int score = 0;
  for (int i = 0; i < 5; i++) {
    if (currentValues[i] == val) {
      score += val;
    }
  }
  return score;
}

int Dice::calcNumofKind(int num) {
  bool flag = false;
  int index = 0;
  while (!flag && index < (5 - num + 1)) {
    int val = currentValues[index];
    int numVals = 1;
    for (int i = (index + 1); i < 5; i++) {
      if (currentValues[i] == val) {
        numVals++;
      }
    }
    if (numVals >= num) {
      flag = true;
    }
    index++;
  }

  if (flag && num == 5) {
    return 50;
  }
  else if (flag) {
    return calcSum();
  }
  else {
    return 0;
  }
}

int Dice::calcNuminRow(int num) {
  int tempArray[5];
  for (int i = 0; i < 5; i++) {
    tempArray[i] = currentValues[i];
  }

  // Sort temp array
  for (int start = 0; start < 4; start++) {
    int minIndex = start;
    int minVal = tempArray[start];
    for (int i = (start + 1); i < 5; i++) {
      if (tempArray[i] < minVal) {
       minVal = tempArray[i];
        minIndex = i;
      }
    }
    tempArray[minIndex] = tempArray[start];
    tempArray[start] = minVal;
  }
 
  if (num == 4) {
    int count = 0, i = 0;
    bool flag = false;
    while (i < 4 && !flag) {
      if (tempArray[i] == (tempArray[i + 1] - 1)) {
        count++;
      }
      else if ((tempArray[i] < (tempArray[i + 1] - 1)) && i != 0) {
        flag = true;
      }
      i++;
    }
    
    if (count >= 3) {
      return 30;
    }
    else {
      return 0;
    }
  }

  else if (num == 5) {
    bool flag;
    flag = (tempArray[0] == (tempArray[1] - 1)) && (tempArray[1] == (tempArray[2] - 1)) && (tempArray[2] == (tempArray[3] - 1)) && (tempArray[3] == (tempArray[4] - 1));
    if (flag) {
      return 40;
    }
  }

  else {
    return 0;
  }
}

int Dice::calcFullHouse() {
  int val1, val2, numVal1 = 0, numVal2 = 0;
  val1 = currentValues[0];
  numVal1++;
  for (int i = 1; i < 5; i++) {
    if (currentValues[i] == val1) {
      numVal1++;
    }
    else {
      val2 = currentValues[i];
    }
  }
  for (int i = 0; i < 5; i++) {
    if (currentValues[i] == val2) {
      numVal2++;
    }
  }

  if ((numVal1 == 3 && numVal2 == 2) || (numVal1 == 2 && numVal2 == 3)) {
    return 25;
  }
  else {
    return 0;
  }
}

int Dice::getScore(int category) {
  switch(category) {
    case 1: return calcUpper(1);
    case 2: return calcUpper(2);
    case 3: return calcUpper(3);
    case 4: return calcUpper(4);
    case 5: return calcUpper(5);
    case 6: return calcUpper(6);
    case 7: return calcNumofKind(3);
    case 8: return calcNumofKind(4);
    case 9: return calcFullHouse();
    case 10: return calcNuminRow(4);
    case 11: return calcNuminRow(5);
    case 12: return calcNumofKind(5);
    case 13: return calcSum();
    default: return 0;
  }
}

// FOR TESTING
void Dice::setValues(int val1, int val2, int val3, int val4, int val5) {
  currentValues[0] = val1;
  currentValues[1] = val2;
  currentValues[2] = val3;
  currentValues[3] = val4;
  currentValues[4] = val5;
}
