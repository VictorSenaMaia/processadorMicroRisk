#include <iostream>
#include <bitset>
#include <stdlib.h>
#include "Decoder.hpp"
#include "MemData.hpp"
#include "ULA.hpp"
using namespace std;

void formato1(bitset<16> Analise){
    bitset<3> Rt, Ra, Rb;
    bitset<5> OPcode;
    unsigned short int OP;
    Rt[2]=Analise[13];
    Rt[1]=Analise[12];
    Rt[0]=Analise[11];

    Ra[2]=Analise[5];
    Ra[1]=Analise[4];
    Ra[0]=Analise[3];

    Rb[2]=Analise[2];
    Rb[1]=Analise[1];
    Rb[0]=Analise[0];
    
    OPcode[4]=Analise[10];
    OPcode[3]=Analise[9];
    OPcode[2]=Analise[8];
    OPcode[1]=Analise[7];
    OPcode[0]=Analise[6];
    OP=(unsigned short int)OPcode.to_ulong();
    
    switch(OP){
        case 0x0000: {
            zeros((unsigned short int)Rt.to_ulong());
            break;
        }
        case 0x0001:{
            ones((unsigned short int)Rt.to_ulong());
            break;
        }
        case 0x0002:{
            AND((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0003:{
            NAND((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0004:{
            OR((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0005:{
            NOR((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0006:{
            XOR((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0007:{
            xnor((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0008:{
            passnota((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x0009:{
            passa((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x000A:{
            andnota((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x000B:{
            ornotb((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0010:{
            lsl((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x0011:{
            asl((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x0012:{
            lsr((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x0013:{
            asr((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x0014:{
            load((unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0016:{
            store((unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0018:{
            add((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x0019:{
            sub((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x001a:{
            addinc((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x001b:{
            subdec((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong(), (unsigned short int)Rb.to_ulong());
            break;
        }
        case 0x001c:{
            inca((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
        case 0x001d: {
            deca((unsigned short int)Rt.to_ulong(), (unsigned short int)Ra.to_ulong());
            break;
        }
    }
}

void formato2(bitset<16> Analise){
    bitset<3> Rc;
    bitset<11> Offset;
    
    Rc[2]=Analise[13];
    Rc[1]=Analise[12];
    Rc[0]=Analise[11];

    for(int i=0; i<11; i++){
        Offset[i]=Analise[i];
    }

    loadlit((unsigned short int)Rc.to_ulong(), (unsigned short int)Offset.to_ulong());

}

void formato3(bitset<16> Analise){
    bitset<3> Rc;
    bitset<8> Offset;

    Rc[2]=Analise[13];
    Rc[1]=Analise[12];
    Rc[0]=Analise[11];

    for(int i=0; i<8; i++){
        Offset[i]=Analise[i];
    }

    if(Analise[10]==0){
        lcl((unsigned short int)Rc.to_ulong(), (uint8_t)Offset.to_ulong());
    } else {
        lch((unsigned short int)Rc.to_ulong(), (uint8_t)Offset.to_ulong());
    }
}

void formato5(bitset<16> Analise){
    bitset<11> Offset;
        for(int i=0; i<11; i++){
            Offset[i]=Analise[i];
        }
    j((unsigned short int)Offset.to_ulong());
}

void formato6(bitset<16> Analise){
    bitset<3> Rb;
    Rb[2]=Analise[2];
    Rb[1]=Analise[1];
    Rb[0]=Analise[0];

    if(Analise[11]==0){
        jal((unsigned short int)Rb.to_ulong());
    } else {
        jr((unsigned short int)Rb.to_ulong());
    }
}

void formato4(bitset<16> Analise){
    if(Analise[13]==1 && Analise[12]==1){
        formato6(Analise);
    } else if(Analise[13]==1 && Analise[12]==0){
        formato5(Analise);
    } else {
        bitset<4> Cond;
        bitset<8> Offset;
        
        Cond[3]=Analise[11];
        Cond[2]=Analise[10];
        Cond[1]=Analise[9];
        Cond[0]=Analise[8];

        for(int i=0; i<8; i++){
            Offset[i]=Analise[i];
        }

        if(Analise[12]==0){
            jf((unsigned short int)Cond.to_ulong(), (uint8_t)Offset.to_ulong());
        } else {
            jt((unsigned short int)Cond.to_ulong(), (uint8_t)Offset.to_ulong());
        }
    }
}

void decode (){
    bitset<16> Analise;
    Analise=getProgramData(getPC());
    if(Analise[15]==0 and Analise[14]==0){
        formato4(Analise);
    } else if(Analise[15]==0 and Analise[14]==1) {
        formato1(Analise);
    } else if(Analise[15]==1 and Analise[14]==0) {
        formato2(Analise);
    } else if(Analise[15]==1 and Analise[14]==1) {
        formato3(Analise);
    } else {
        cout << "Invalid Instruction, aborting program." << endl;
        abort();
    }

}