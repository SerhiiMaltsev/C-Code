//Serhii Maltsev sm5zj 09/28/2020 bitCounter.cpp

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int numberOfN(int x){
  if (x == 0){
    return 0;
  } else if (x % 2 == 0) {
    return numberOfN(x/2);
  } else {
    return numberOfN(x/2)+1;
  }
}

string converter(string val, int initialBase, int finalBase){
  char x = val[0];
  int length = val.length();
  string initialVal = val;
  int initialB = initialBase;
  int finalB = finalBase;
  int decimal = 0;
  while (initialVal.length() != 0){
    x = initialVal[0];
    if (int(x) > 57){
      decimal += (int(x)-55) * pow (initialB, length-1);
    } else {
      decimal += (int(x)-48) * pow (initialB, length-1);
    }
    initialVal.erase (0, 1);
    length--;
  }
  
  int finalLength = 0;
  while (pow (finalB, finalLength) < decimal){
    finalLength++;
  }
  
  int quotient = decimal/finalB;
  int remainder = decimal%finalB;
  char j = '1';
  string finalVal = "";
  int lengthForFlip = finalLength;
  while (finalLength != 0){
    if (remainder > 9) {
      j = remainder + 55;
    } else {
      j = remainder + 48;
    }
    finalVal += j;
    remainder = quotient % finalB;
    quotient = quotient/finalB;
    finalLength--;
  }

  string flippedVal = "";
  
  for (int i = 0; i < lengthForFlip; i++){
    flippedVal += finalVal [lengthForFlip -i -1];
  }
  
  return flippedVal;
}

int main (int argc, char** argv){
  
  string s1(argv[1]);
  int i1 = stoi(s1);
  string s2(argv[2]);
  string s3(argv[3]);
  int t3 = stoi(s3);
  string s4(argv[4]);
  int t4 = stoi(s4);
  cout << i1 << " has " <<  numberOfN(i1) << " bit(s)" << endl;
  cout << s2 << " (base " << s3 << ") = " << converter(s2, t3, t4) << " (base " << s4 << ")" << endl;  
  return 0;
}
