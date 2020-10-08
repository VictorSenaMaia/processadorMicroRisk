#include <iostream>
#include <bitset>
#include <stdlib.h>
#include "RegData.hpp"

using namespace std;

void add(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=5;//getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int valor;
  int sobra;
  while (RegB) {
    sobra = RegA & RegB;
    RegA ^= RegB;
    RegB = sobra << 1;
  }
  cout<<valor;
  //setRegister(rt, valor);
}


int main() {
  //bitset<3>Rt,Ra, Rb;
  unsigned short int Rt;
  unsigned short int Ra;
  unsigned short int Rb;
  cin >> Ra >> Rb;
  //add((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
   add(Rt,Ra,Rb);
   
   
  cout << Rt << endl;
  //add((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong())
}
