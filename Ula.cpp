#include <iostream>
#include <bitset> 
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "MemData.hpp"
#include "RegData.hpp"
#include "MemData.hpp"

using namespace std;
unsigned short int sinalExtend(unsigned short int num){
	unsigned short int var;
	ultimoBit=num>>7;
	if(ultimoBit==1){
		var = 0xffff0000;
		
	}
	else{
		var=0x0;
	}
	num=num^var;
	return num;	
}
void overFlow(unsigned short int n1, unsigned short int n2,unsigned short int carry){
	unsigned short int ultimoBit1, penultimoBit1;
	unsigned short int ultimoBit2, penultimoBit2;
	ultimoBit1=n1>>15;
	ultimoBit2=n2>>15;
	
	penultimoBit1=n1<<1;
	penultimoBit1=penultimoBit1>>15;
	penultimoBit2=n1<<1;
	penultimoBit2=penultimoBit1>>15;
	
	if((ultimoBit1 | ultimoBit2) != 0){
		if(penultimoBit1 ==1 and penultimoBit2==1){
			setFlag(4,1);		
		} else if((penultimoBit1 ==1 or penultimoBit2==1) and carry ==1){
			setFlag(4,1);		
		} else
		{
			setFlag(4,0);
		}
	}
	setFlag(4,0);
}
void incPC(){   
    unsigned short int PC=getPC(); 
	unsigned int sobra;
	unsigned int inc=1;   
	//incrementa um 
    while (inc) {
	    sobra =PC & inc;
	    PC^= inc;
	    inc = sobra << 1;
    }  
	setPC(PC);
}
void add(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned int sobra;
  while (RegB) {
    sobra = RegA & RegB;
    RegA ^= RegB;
    RegB = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  }
  setRegister(rt, RegA);
 
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  overFlow(RegA, RegB,sobra);
  //cout<<RegA;
  //atualizaFlag();
  incPC();
}
void addinc(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned int inc=1;
  unsigned int sobra;
  //faz a soma dos números
  while (RegB) {
    sobra = RegA & RegB;
    RegA ^= RegB;
    RegB = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  }
  //incrementa um 
  while (inc) {
    sobra = RegA & inc;
    RegA ^= inc;
    inc = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  } 
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  overFlow(RegA, RegB,sobra)
  setRegister(rt, RegA);
  cout<<RegA;
  
  incPC();
}
void AND(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int RegT;
  //Comparação entre os valores
  RegT=RegA & RegB;
  setRegister(rt, RegT);
  //cout<<"Valor Logico: "<<RegT;
  setFlag(4,0);
  setFlag(3,0);
  
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
 
  incPC();
}
void andnota(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int RegT;
  //Comparação entre os valores
  RegA=~RegA;
  RegT=RegA & RegB;
  setRegister(rt, RegT);
  //cout<<"Valor Logico: "<<RegA;
  setFlag(4,0);
  setFlag(3,0);
  
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  incPC();
}
void asl(unsigned short int rc, unsigned short int ra) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegC;
  unsigned short int carry;
  unsigned short int overFlow;
  carry=ra>>15;
  ra=ra<<1;
  overFlow=(ra>>15)^(ra>>15);
  setFlag(4,overFlow);
   //cout<<"Valor Ra: "<<bitset<8>(RegA)<<endl;
  RegC=RegA;
  RegC=RegC<<1;
 
  setRegister(rc, RegC);
  
  //carry
  setFlag(3,carry);
  
  //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  
  incPC();
}
void asr(unsigned short int rc, unsigned short int ra) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegC;
  unsigned short int Aux;
  
  //cout<<"Valor Ra: "<<bitset<16>(RegA)<<endl;
  Aux=RegA;
  RegA=RegA<<15;
  
  Aux=Aux>>1;
  RegC=RegA^Aux;
		
  setRegister(rc, RegC);
  
  //cout<<"Valor Rc: "<<bitset<16>(RegC);
  setFlag(4,0);
  setFlag(3,0);
  
  //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  incPC();
}
void deca(unsigned short int rc, unsigned short int ra) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegC;
  unsigned int inc=-1;
  unsigned int sobra;		
  setRegister(rc, RegC);
  
  //incrementa um 
  while (inc) {
    sobra = RegA & inc;
    RegA ^= inc;
    inc = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  } 
  RegC=RegA;
  //cout<<"Valor:    "<<RegC;
  
  //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  overFlow(RegA, RegB,sobra);
  incPC();
}
void inca(unsigned short int rc, unsigned short int ra) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegC;
  unsigned int inc=1;
  unsigned int sobra;		
  
  
  //incrementa um 
  while (inc) {
    sobra = RegA & inc;
    RegA ^= inc;
    inc = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  } 
  RegC=RegA;
  setRegister(rc, RegC);
  //cout<<"Valor:    "<<RegC;
  
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  overFlow(RegA, RegB,sobra);
  incPC();
}
void j(unsigned short int rd){
  unsigned short int PCatual=getPC();
  unsigned int inc=1;
  unsigned int sobra;
  unsigned short int var;
	ultimoBit=rd>>11;
	if(ultimoBit==1){
		var = 0xf000;
		
	}
	else{
		var=0x0;
	}
     rd=rd^var;
		
  
  while (rd) {
    sobra = PCatual & rd;
    PCatual ^= rd;
    rd = sobra << 1;
  }
 
  setPC(PCatual);
  //cout<<RegA;
  //atualizaFlag();
  incPC();
		
}
void jal(unsigned short int rb){
 
  setRegister(7,getPC()); 
  setPC(rb);
  //cout<<RegA;
  //atualizaFlag();
  incPC();
		
}
void jr(unsigned short int rb){
  
  setPC(getRegister(rb));
  //cout<<RegA;
  //atualizaFlag();
  incPC();
		
}
void zeros(unsigned short int rc){
	unsigned short int RegC =0;
	setRegister(rc,RegC);
	incPC();
	setflag(0,0);
	setflag(1,1);
	setflag(2,1);
	setflag(3,0);
	setflag(4,0);
}
void XOR(unsigned short int rc, unsigned short int ra,unsigned short int rb){
	unsigned short int RegA=getRegister(ra);
    unsigned short int RegB=getRegister(rb);
    unsigned short int RegC;
    RegC=RegA^RegB;
	setRegister(rc,RegC);
	incPC();
	//flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);	
}
void xnor(unsigned short int rc, unsigned short int ra,unsigned short int rb){
	unsigned short int RegA=getRegister(ra);
    unsigned short int RegB=getRegister(rb);
    unsigned short int RegC;
    RegC=RegA^RegB;
    RegC=~RegC;
	setRegister(rc,RegC);
	incPC();
	//flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);	
}
void sub(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned int sobra;
  unsigned int sinal;
  //faz a soma dos números
  RegB=-RegB;
  while (RegB) {
    sobra = RegA & RegB;
    RegA ^= RegB;
    RegB = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  }
 
  setRegister(rt, RegA);
  cout<<RegA;
  setFlag(3,sobra);
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  //cout<<RegA;
  //atualizaFlag();
  incPC();
}
void subdec(unsigned short int rt, unsigned short int ra,unsigned short int rb) {
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned int inc=-1;
  unsigned int sobra;
  //faz a soma dos números
  RegB=-RegB;
  while (RegB) {
    sobra = RegA & RegB;
    RegA ^= RegB;
    RegB = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  }
  //subtrai um 
  while (inc) {
    sobra = RegA & inc;
    RegA ^= inc;
    inc = sobra << 1;
    if(sobra==1){setFlag(3,1);}
  } 
  setRegister(rt, RegA);
  cout<<RegA;
  setFlag(3,sobra);
  incPC();
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
}
void store(unsigned short int ra,unsigned short int rb){
	 unsigned short int RegA=getRegister(ra);
	 unsigned short int RegB=getRegister(rb);
	 setData(RegA,RegB);
	 incPC();	 
}
void passnota(unsigned short int rc,unsigned short int ra){
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegC=getRegister(rc);
  RegC=~RegA;
  setRegister(rc, RegC);
  incPC();
   //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);	
}
void passa(unsigned short int rc,unsigned short int ra){
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegC=getRegister(rc);
  RegC=RegA;
  setRegister(rc, RegC);
  incPC();
   //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);	
}
void OR(unsigned short int rc, unsigned short int ra,unsigned short int rb){
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int RegC;
  
  RegC=RegA|RegB;
  setRegister(rc, RegC);
  incPC();
   //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);	
}
void ornotb(unsigned short int rc, unsigned short int ra,unsigned short int rb){
	
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int RegC;
  RegB=~RegB;
  RegC=RegA|RegB;
  setRegister(rc, RegC);
  incPC();
   //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);	
}
void ones(unsigned short int rc){
	unsigned short int RegC=getRegister(rc);
	RegC=1;
	setRegister(rc, RegC);
	incPC();
	 //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);
	
}
void NOR(unsigned short int rc, unsigned short int ra,unsigned short int rb){
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int RegC;
  
  RegA=~RegA;
  RegB=~RegB;
  RegC=RegA & RegB;
  setRegister(rc, RegC);
  incPC();
  //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);
}
void NAND(unsigned short int rc, unsigned short int ra,unsigned short int rb){
  unsigned short int RegA=getRegister(ra);
  unsigned short int RegB=getRegister(rb);
  unsigned short int RegC;
  
  RegA=~RegA;
  RegB=~RegB;
  RegC=RegA | RegB;
  setRegister(rc, RegC);
  incPC();
  //flag zero e negZero
  if(RegC==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegC<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);
}
void lsr(unsigned short int rc, unsigned short int ra){
	unsigned short int RegA=getRegister(ra);
    unsigned short int RegC=getRegister(rc);
	
	RegC=RegA>>1;
	setRegister(rc, RegC);
	incPC();
  //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
   if(RegA<0){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  setFlag(3,0);
}
void lsl(unsigned short int rc, unsigned short int ra){
	unsigned short int RegA=getRegister(ra);
    unsigned short int RegC=getRegister(rc);
    unsigned short int carry=ra>>15;
	unsigned short int sinal;
	RegC=RegA<<1;
	setRegister(rc, RegC);
	incPC();
 //flag zero e negZero
  if(RegA==0){
  	setFlag(1,1);
    setFlag(2,1);	  
  }
  //flag neg e negZero
  sinal=RegC>>15;
   if(sinal==1){
  	setFlag(0,1);
    setFlag(2,1);	  
  }
  setFlag(4,0);
  //cout<<RegA;
  //atualizaFlag();
}
void loadlit(unsigned short int rc, unsigned short int ra){
	//unsigned short int RA= getRegister(ra);
	//cout<<"Valor rc: "<<rc<<endl;
	unsigned short int var;
	ultimoBit=ra>>10;
	if(ultimoBit==1){
		var = 0xfc00;
		
	}
	else{
		var=0x0;
	}
     ra=ra^var;
		
	setRegister(rc,ra);
	incPC();
}
void lch(unsigned short int rc, uint8_t ra){
	uint8_t RegC;
	RegC=(ra<<8)|(rc & 0x00ff);
	setRegister(rc,RegC);
	incPC();
}
void lcl(unsigned short int rc, unsigned short int ra){
    unsigned short int RegC;
	RegC = ra| (rc & 0xFF00);
	
	setRegister(rc,RegC);
	incPC();
	
}
void load(unsigned short int rc,unsigned short int ra){
	unsigned short int endereco=getRegister(ra);
	 
	setRegister(rc,endereco);
	
	incPC();
}
void jt( unsigned short int nCondicao, unsigned short int Offset){
  unsigned short int PC=getPC();
  unsigned int sobra;
  unsigned short int condicao=getFlag(decodeCond(nCondicao));
  //cout<<"Teste";
  //atualizaFlag();
  Offset=sinalExtend(Offset);
	if(condicao==1){
		while (Offset) {
	    sobra = PC & Offset;
	    PC ^= Offset;
	    Offset = sobra << 1;
      }
	  setPC(PC);	   	
	}
  
  incPC();
	
}
void jf( unsigned short int nCondicao, unsigned short int Offset){
  unsigned short int PC=getPC();
  unsigned int sobra;
  unsigned short int condicao=getFlag(decodeCond(nCondicao));
  Offset=sinalExtend(Offset);
  cout<<"Valor PC"<<PC;
  //atualizaFlag();

	if(condicao==0){
		while (Offset) {
	    sobra = PC & Offset;
	    PC ^= Offset;
	    Offset = sobra << 1;
      }	
	  setPC(PC);   	
	}  
  incPC();	
}
unsigned short int decodeCond(unsigned short int numero){
	if(numero==4){
		condicao=0;
	}
	if(numero==5){
		condicao=1;
	}
	if(numero==6){
       condicao=3;	
	}
	if(numero==7){
		condicao=2;
	}
	if(numero==0){
		condicao=5;
	}
	if(numero==1){
		condicao=4;
	}
	
	return condicao;
}
