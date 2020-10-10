//Serhii Maltsev sm5zj 09/26/2020 prelab4.cpp

#include <iostream>
using namespace std;

void sizeOfTest(){
  int a;
  cout << "Size of int: " << sizeof(a) << endl;

  unsigned int b;
  cout << "Size of unsigned int: " << sizeof(b) << endl;

  float c;
  cout << "Size of float: " << sizeof(c) << endl;

  double d;
  cout << "Size of double: " << sizeof(d) << endl;

  char e;
  cout << "Size of char: " << sizeof(e) << endl;

  bool f;
  cout << "Size of bool: " << sizeof(f) << endl;

  int* g;
  cout << "Size of int*: " << sizeof(g) << endl;

  char* h;
  cout << "Size of char*: " << sizeof(h) << endl;

  double* i;
  cout << "Size of double*: " << sizeof(i) << endl;

}

void overflow(){
  unsigned int x = 4294967295;
  cout << x <<  " + 1 = " << (x+1) << endl;
}

void outputBinary(int x){
  string s = "00000000000000000000000000000000";
  int i = 0;
  int j = 1;
  while (x != 0){
    i = 1;
    j = 1;
    while (i <= x){
      i = i * 2;
      j++;
    }
    i = i/2;
    x = x - i;
    s[32-j+1] = '1';
  }
  cout << s.substr(0, 4) + " " + s.substr(4, 4) + " " + s.substr(8, 4)
    + " " + s.substr (12, 4) + " " + s.substr (16, 4) + " " +
    s.substr (20, 4) + " " + s.substr (24, 4) + " " +
    s.substr (28, 4) << endl;
    
}

int main(){
  
  int token;
  cin >> token; 
  sizeOfTest();
  overflow();
  outputBinary(token);
  
  return 0;
}
