#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "MemData.hpp"
#include "RegData.hpp"

using namespace std;

static unsigned short int Register[8];
static bool Flag[6]; //Sequencia: Neg, Zero, NegZero, Carry, Overflow,true;

unsigned short int getRegister(unsigned short int number){
    if(number<0 or number>7){
        cout << "Pedido de registrador inexistente, abortando programa." << endl;
        cout<<"Numero registrador: "<<number;
        abort();
    } else {
        return Register[number];
    }
    return -1;
}

void setRegister(unsigned short int number, unsigned short int value){
    if(number<0 or number>7){
        cout <<"Pedido de registrador inexistente, abortando programa." << endl;
        abort();
    } else {
        Register[number]=value;
    }
}

bool getFlag(unsigned short int number) {
    if(number<0 or number>4){
        cout << "Pedido de flag inexistente, abortando programa." << endl;
			abort();
    } else {
        return Flag[number];
    }
    return -1;
}

void setFlag(unsigned short number, bool value) {
    if(number<0 or number>4){
        cout << "Pedido de flag inexistente, abortando programa" << endl;
        abort();
    } else{
        Flag[number]=value;
    }
}