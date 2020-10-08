#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "MemData.hpp"
#include "Decoder.hpp"
#include "RegData.hpp"

using namespace std;

void openFail(void){
    cout << "Problemas com a declaracao de parametros de inicializacao, devem ser declarado o nome do arquivo seguido do modo de execucao: direto ou pausado" << endl;
}

void printRegisters(){
    printf("R0: 0x%.4x\t R1: 0x%.4x \t R2: 0x%.4x\nR3: 0x%.4x\t R4: 0x%.4x \t R5: 0x%.4x\nR6: 0x%.4x\t R7: 0x%.4x\n",getRegister(0),getRegister(1),getRegister(2),getRegister(3),getRegister(4),getRegister(5),getRegister(6),getRegister(7));
    printf("Neg: %d\t Zero: %d\t NegZero: %d\t Carry: %d\t Overflow: %d\n", getFlag(0), getFlag(1), getFlag(2), getFlag(3), getFlag(4));
}

void setToMem(char *nomeArquivo){

    string leitura;
    ifstream arq(nomeArquivo, ios::in|ios::binary);
    char caractere[5];
    if (arq.is_open()) {
        while (!arq.eof()){
            getline(arq,leitura);
            if(leitura.size()==4){
                strcpy(caractere, leitura.c_str());
                setProgtoMem(caractere);
            }
        }
        arq.close();
    }
    else {
        cout << "Nao foi possivel abrir o arquivo";
        abort();
    }
}

void callDecoder(){
    decode();
}

int main (int argc, char *argv[]){
    
    char direto[]="direto", pausado[]="pausado";
    unsigned short int n;

    if(argc!=3){

        openFail();
        abort();

    } else if(strcmp(argv[2], direto)==0){

        setToMem(argv[1]);
        n=getProgramLength();
        for(int i=0; i<n; i++){
            decode();
        }

        printRegisters();
    } else if(strcmp(argv[2], pausado)==0){

        setToMem(argv[1]);
        n=getProgramLength();

        for(int i=0; i<n; i++){
            decode();
            system("CLS"); //<<<<<<<<<<<<<<<<<<<<<< DESCOMENTAR QUANDO O PROGRAMA TIVER PRONTO, LIMPA A TELA A CADA EXECUÇÃO PRA NÃO FICAR UM MILHÃO DE VALOR NA TELA, MAS ANTES É MELHOR DEIXAR PRA DEBUGAR MAIS FÁCIL
            printRegisters();
            cin.ignore();
        }
        
    } else {

        openFail();
        abort();
    }

    return EXIT_SUCCESS;

}