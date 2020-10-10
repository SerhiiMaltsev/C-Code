//Serhii Maltsev sm5zj 09/24/2020 stack.h

#include <iostream>
#include "List.h"
using namespace std;

class stack {
 public:
  stack();

  ~stack();

  void push (int e);

  void pop ();

  int top();

  bool empty();

  int count;
  
 private:
  List* s;
  
  ListItr l;
  
  
};
