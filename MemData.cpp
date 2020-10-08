#include <bitset>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "MemData.hpp"

#define SIZE 32768

using namespace std;

static bitset<16> Memoria[SIZE];
static unsigned short int posFinalProg=0, PC;

void memError(){
    cout << "Acesso de memoria em posicao invalida";
    //cout<< "Chamou função";
    abort();
}

unsigned short int getProgramLength(){
    return posFinalProg;
}

unsigned short int getData(unsigned short int pos){
    if(pos=0xffff){
        cout << "Halt" << endl;
    }
    if(pos<=posFinalProg || pos>SIZE){
    	cout<<"Posição "<<pos;
        memError();
    } else {
        return (unsigned short int)Memoria[pos].to_ulong();
    }
    return -1;
}

bitset<16> getProgramData(unsigned short int pos){
    if(pos<0 || pos>posFinalProg){
        memError();
    } else {
        return Memoria[pos];
    }
    return -1;
}

void setPC(unsigned short int newPC){
    PC=newPC;
}

unsigned short int getPC(){
    return PC;
}

void setData(unsigned short int pos, unsigned short int value) {
    unsigned short int mask = 0x0001;
    bitset<16> Data;
    if(pos<=posFinalProg || pos>SIZE){
    } else {
        for (int i=0; i<16; i++){
            if((value & mask) == 0) {
                Data.reset(i);
            } else {
                Data.set(i);
            }
        mask=mask<<1;
        }
        cout << pos << endl;
        Memoria[pos]=Data;
    }
}
 
bitset<16> decryptograph(char word[]){
    bitset<16> decrypt;
    
    for(int i=0; i<4; i++){
        switch(word[i]){
            case '0':{
                decrypt.reset(15-i*4-0); 
                decrypt.reset(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case '1':{
                decrypt.reset(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case '2':{
                decrypt.reset(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case '3':{
                decrypt.reset(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case '4':{
                decrypt.reset(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case '5':{
                decrypt.reset(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case '6':{
                decrypt.reset(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case '7':{
                decrypt.reset(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case '8':{
                decrypt.set(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case '9':{
                decrypt.set(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case 'a':{
                decrypt.set(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case 'b':{
                decrypt.set(15-i*4-0);
                decrypt.reset(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case 'c':{
                decrypt.set(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case 'd':{
                decrypt.set(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.reset(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
            case 'e':{
                decrypt.set(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.reset(15-i*4-3);
                break;
            }
            case 'f':{
                decrypt.set(15-i*4-0);
                decrypt.set(15-i*4-1);
                decrypt.set(15-i*4-2);
                decrypt.set(15-i*4-3);
                break;
            }
        }
    }
    return decrypt;
}


void setProgtoMem(char caractere[]){
    Memoria[posFinalProg]=decryptograph(caractere);
    posFinalProg++;
}