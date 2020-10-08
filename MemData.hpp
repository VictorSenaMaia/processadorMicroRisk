#ifndef MEMDATA_HPP
#define MEMDATA_HPP
#include <bitset>

unsigned short int getData(unsigned short int pos);
std::bitset<16> getProgramData(unsigned short int pos);
void setProgtoMem(char caractere[]);
unsigned short int getProgramLength();
void setPC(unsigned short int newPC);
unsigned short int getPC();
void setData(unsigned short int pos, unsigned short int value);

#endif