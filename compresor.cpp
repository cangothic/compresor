#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
size_t numeroDeBitsagrupar;
map<string,int> diccionarioContarPalabra;
int main() {
  cout << "ingrese el numero de caracteres a agrupar" <<endl;
  cin>>numeroDeBitsagrupar;
  string palabra="";
  for (fstream file("in1.txt");file.good();) {
    for (size_t indCaracter = 0; indCaracter < numeroDeBitsagrupar; indCaracter++) {
      char caracter=file.get();
      palabra.push_back(caracter);
    }
    if(diccionarioContarPalabra.count(palabra)==0){
      diccionarioContarPalabra[palabra]=0;
    }
    diccionarioContarPalabra[palabra]++;
  }
  string prueba ="escribir";
  ofstream file("out.txt",ofstream::out);
  for(size_t i=0;i<prueba.size();i++){
    file<<prueba[i];
  }
  file.close();
  return 0;
}
