//Serhii Maltsev sm5zj 09/20/2020 postfixCalculator.cpp
#include "postfixCalculator.h"
#include <iostream>
using namespace std;


postfixCalculator::postfixCalculator(){
  st = new stack();
}

postfixCalculator::~postfixCalculator(){
  delete st;
}

int postfixCalculator::printLast(){
  return st -> top();
}

void postfixCalculator::addition(){
  if (st -> count >= 2){
    int x = st -> top();
    st -> pop();
    int y = st -> top();
    st -> pop();
    st -> push (x + y);
  } else {
    exit (1);
  }
}

void postfixCalculator::subtraction(){
  if (st -> count >= 2){
    int x = st -> top();
    st -> pop();
    int y = st -> top();
    st -> pop();
    st -> push(y - x);
  } else {
    exit(1);
  }
}

void postfixCalculator::addToStack (int x){
  st -> push(x);
}


void postfixCalculator::multiplication(){
  if (st -> count >=2){
    int x = st -> top();
    st -> pop();
    int y = st -> top();
    st -> pop();
    st -> push (x*y);
  } else {
    exit (1);
  }
}

void postfixCalculator::negation(){
  if (st -> count >=1){
    int x = st -> top();
    st -> pop();
    st -> push (x*(-1));
  } else {
    exit(1);
  }
}

void postfixCalculator::division(){
  if (st -> count >=2){
    int x = st -> top();
    st -> pop();
    int y = st -> top();
    st -> pop();
    st -> push (y/x);
  } else {
    exit (1);
  }
}
