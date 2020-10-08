#include <bitset>
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

#define SIZE 32768

using namespace std;

bitset<16> Memoria[SIZE];
static int counter=0;
unsigned short int posFinalProg=0;

using namespace std;

void setData(unsigned short int pos, unsigned short int value) {
    unsigned short int mask = 0x0001;
    bitset<16> Data;
    if(pos<=posFinalProg || pos>SIZE){
    } else {
        for (int i=0; i<16; i++){
            cout << "Resultado and "<< (value&mask) << endl;
            if((value & mask) == 0) {
                Data.reset(i);
            } else {
                Data.set(i);
            }
        mask=mask<<1;
        }
        Memoria[pos]=Data;
    }
}


bitset<16> bitreturn(){
    bitset<16> test;
    int count=0;

    char n[4] ={'f','e','d','c'};//{'b','a','9','8'};{'7','6','5','4'};{'3','2','1','0'};

    for(int i=0; i<4; i++){
        cout << n[i] << endl;
        switch(n[i]){
            case '0':{
                    test.reset(15-i*4-0); 
                    test.reset(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case '1':{
                    test.reset(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case '2':{
                    test.reset(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.set(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case '3':{
                    test.reset(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.set(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case '4':{
                    test.reset(15-i*4-0);
                    test.set(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case '5':{
                    test.reset(15-i*4-0);
                    test.set(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case '6':{
                    test.reset(15-i*4-0);
                    test.set(15-i*4-1);
                    test.set(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case '7':{
                    test.reset(15-i*4-0);
                    test.set(15-i*4-1);
                    test.set(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case '8':{
                    test.set(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case '9':{
                    test.set(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case 'a':{
                    test.set(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.set(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case 'b':{
                    test.set(15-i*4-0);
                    test.reset(15-i*4-1);
                    test.set(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case 'c':{
                    test.set(15-i*4-0);
                    test.set(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case 'd':{
                    test.set(15-i*4-0);
                    test.set(15-i*4-1);
                    test.reset(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
                case 'e':{
                    test.set(15-i*4-0);
                    test.set(15-i*4-1);
                    test.set(15-i*4-2);
                    test.reset(15-i*4-3);
                    break;
                }
                case 'f':{
                    test.set(15-i*4-0);
                    test.set(15-i*4-1);
                    test.set(15-i*4-2);
                    test.set(15-i*4-3);
                    break;
                }
        }
    }
    return test;
}



int main () {
    
    bitset<16> a(string("0000000000000100")), b (string("0000000000000001")), d;
    bitset<8> c(string("11111111"));

    
    printf("A= %d c= %d \n", (unsigned short int)a.to_ulong(), (unsigned short int)c.to_ulong());
    /*
    unsigned long int i;
    unsigned short int j;
    unsigned int k;
    i=a.to_ulong();
    j=(unsigned short int)a.to_ulong();
    k=(unsigned int)a.to_ulong();
    cout << i << endl << j << endl << k << endl;
    //a=setData(2, b);
    //cout << a << endl << b << endl;
    //cout << (unsigned short int)a.to_ulong() << endl << (unsigned short int)b.to_ulong() << endl;
    //cout << bitreturn() << endl;

    */

   /*unsigned short int a, b;
    cin >> a;
    cin >> b;

    setData(a,b);
    */
}