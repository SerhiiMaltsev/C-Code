//Serhii Maltsev sm5zj 09/24/2020 stack.cpp

#include "stack.h"
#include <iostream>
using namespace std;

stack::stack(){
  s = new List();
  count = 0;
}

stack::~stack(){
  delete s;
}

void stack::push (int e){
  s -> insertAtTail(e);
  l = s -> last();
  count++;
}

void stack::pop (){
  l = s -> last();
  s -> remove(l.retrieve());
  l = s -> last();
  count--;
}

int stack::top(){
  int x = l.retrieve();
  return x;
}

bool stack::empty(){
  if (count == 0){
    return true;
  } else {
    return false;
  }
}
