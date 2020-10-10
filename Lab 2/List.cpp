//Serhii Maltsev sm5zj 09/14/2020 List.cpp
#include "List.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

List::List(){
  head = new ListNode();
  tail = new ListNode();
  head -> next = tail;
  tail -> previous = head;
  count = 0;
}

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

bool List::isEmpty() const{
  if (count == 0){
    return true;
      } else {
    return false;
  }
}

void List::makeEmpty(){
  ListItr x = first();
  ListNode * y = head;
  while (x.isPastEnd() == false){
    y = x.current;
    x.moveForward();
    delete y;
  }
    
  head -> next = tail;
  tail -> previous = head;
  count = 0;
}

ListItr List::first(){
  ListItr x =  ListItr (head -> next);
  return x;
}

ListItr List::last(){
  ListItr x = ListItr (tail -> previous);
  return x;
}

void List::insertAfter(int x, ListItr position){
  ListNode* z = position.current;
  ListNode* afterZ = z -> next;
  ListNode* newNode = new ListNode ();
  newNode -> value = x;
  z -> next = newNode;
  newNode -> previous = z;
  newNode -> next = afterZ;
  afterZ -> previous = newNode;
  count++;
  delete newNode;
}

void List::insertBefore(int x, ListItr position){
  ListNode* z = position.current;
  ListNode* beforeZ = z -> previous;
  ListNode* newNode = new ListNode ();
  newNode -> value = x;
  z -> previous = newNode;
  newNode -> next = z;
  newNode -> previous = beforeZ;
  beforeZ -> next = newNode;
  count++;
}

void List::insertAtTail(int x){
  ListNode* newNode = new ListNode();
  newNode -> value = x;
  newNode -> next = tail;
  newNode -> previous = tail -> previous;
  ListNode* changePreviousNext = tail -> previous;
  changePreviousNext -> next = newNode;
  tail -> previous = newNode;
  count++;
}

ListItr List::find(int x){
  ListItr y =  ListItr (head);
  while (y.isPastEnd() == false && y.retrieve() != x){
    y.moveForward();
  }
  return y;
}


void List::remove(int x){
  ListItr y = find (x);
  ListNode* z = y.current;
  if (z -> next != NULL){
    z -> previous -> next = z -> next;
    z -> next -> previous = z -> previous; 
    count--;
  }
  delete z;
}

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
  if (forward == true){
    ListItr x = source.first();
    while (x.isPastEnd() == false){
      cout << x.retrieve() << endl;
      x.moveForward();
    }
  } else {
    ListItr x = source.last();
    while (x.isPastBeginning() == false){
      cout << x.retrieve() << endl;
      x.moveBackward();
    }
  }
}
