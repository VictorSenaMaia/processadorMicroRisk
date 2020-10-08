#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main () {
  string line;
  ifstream myfile ("shift", ios::in|ios::binary); // ifstream = padrão ios:in
  int x = 0, i = 0;
  char h;
  if (myfile.is_open())
  {
    while (! myfile.eof() ) //enquanto end of file for false continua
    {
      	getline (myfile,line);	// como foi aberto em modo texto(padrão)
                        		//e não binário(ios::bin) pega cada linha
        //myfile.get(h);
      //cout << h << endl;
      cout << line << endl << line.size() << endl << endl;
    }
    
    
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
