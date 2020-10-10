//Serhii Maltsev sm5zj 09/04/2020 xToN.cpp
#include <iostream>
using namespace std;

int xton (int x, int n){
  if (n == 0){
    return 1;
  } else {
    return xton(x, n-1)*x;
  }
}

   
int main (){
  int x;
  int n;
  cin >> x;
  cin >> n;
  cout << xton(x,n) << endl;
  return 0;
}
