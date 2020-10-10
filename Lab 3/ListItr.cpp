//Serhii Maltsev sm5zj 09/14/2020 ListItr.cpp
#include "ListItr.h"
#include <iostream>
using namespace std;

ListItr::ListItr(){
  
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}


bool ListItr::isPastEnd() const{
  if (current -> next == NULL){
    return true;
  } else {
    return false;
  }
}

bool ListItr::isPastBeginning() const{
  if (current -> previous == NULL){
    return true;
  } else {
    return false;
  }
}

void ListItr::moveForward(){
  if (isPastEnd () == false){
    ListNode* x = current -> next;
    current = x;
  }
}

void ListItr::moveBackward(){
  if (isPastBeginning() == false){
    ListNode* x = current -> previous;
    current = x;
  }
}

int ListItr::retrieve() const{
  return current -> value;
}


