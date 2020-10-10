//Serhii Maltsev sm5zj 09/20/2020 testPostfixCalc.cpp
#include <iostream>
#include <string>
using namespace std;

#include "postfixCalculator.h"

int main() {

  postfixCalculator * x = new postfixCalculator();
  string token;

  while (cin >> token){
    if (token == "+"){
      x -> addition();
    } else if (token == "-"){
      x -> subtraction();
    } else if (token == "*"){
      x -> multiplication();
    } else if (token == "/"){
      x -> division();
    } else if (token == "~"){
      x -> negation();
    } else {
      x -> addToStack(stoi(token));
    }
  }

  cout << (x -> printLast()) << endl;

  delete x;
  return 0;

}
