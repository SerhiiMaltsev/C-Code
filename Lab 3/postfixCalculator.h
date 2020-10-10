//Serhii Maltsev sm5zj 09/20/2020 postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include "stack.h"
#include "List.h"
using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();

  ~postfixCalculator();

  void addition();

  void subtraction ();

  void addToStack (int x);

  void multiplication();

  void division();

  void negation();

  int printLast();
  
 private:
  stack* st;
};

#endif

  
