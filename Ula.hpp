#ifndef ULA_HPP
#define ULA_HPP

#include <iostream>
#include <bitset> 

#include "RegData.hpp"
#include "MemData.hpp"
using namespace std;

void add(unsigned short int rt, unsigned short int ra,unsigned short int rb);
void addinc(unsigned short int rt, unsigned short int ra,unsigned short int rb);
void AND(unsigned short int rt, unsigned short int ra,unsigned short int rb);
void andnota(unsigned short int rt, unsigned short int ra,unsigned short int rb);
void asl(unsigned short int rc, unsigned short int ra);
void asr(unsigned short int rc, unsigned short int ra);
void deca(unsigned short int rc, unsigned short int ra);
void inca(unsigned short int rc, unsigned short int ra);
void j(unsigned short int rd);
void jal(unsigned short int rb);
void jr(unsigned short int rb);
void zeros(unsigned short int rc);
void XOR(unsigned short int rc, unsigned short int ra,unsigned short int rb);
void xnor(unsigned short int rc, unsigned short int ra,unsigned short int rb);
void sub(unsigned short int rt, unsigned short int ra,unsigned short int rb);
void subdec(unsigned short int rt, unsigned short int ra,unsigned short int rb);
void store(unsigned short int ra,unsigned short int rb);
void passnota(unsigned short int rc,unsigned short int ra);
void passa(unsigned short int rc,unsigned short int ra);
void OR(unsigned short int rc, unsigned short int ra,unsigned short int rb);
void ornotb(unsigned short int rc, unsigned short int ra,unsigned short int rb);
void ones(unsigned short int rc);
void NOR(unsigned short int rc, unsigned short int ra,unsigned short int rb);
void NAND(unsigned short int rc, unsigned short int ra,unsigned short int rb);
void lsr(unsigned short int rc, unsigned short int ra);
void lsl(unsigned short int rc, unsigned short int ra);
void loadlit(unsigned short int rc, unsigned short int ra);
void lch(unsigned short int rc, uint8_t ra);
void lcl(unsigned short int rc, uint8_t ra);
void load(unsigned short int rc,unsigned short int ra);
void jt( unsigned short int condicao, uint8_t Offset);
void jf( unsigned short int condicao, uint8_t Offset);


#endif