#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

size_t numeroDeBitsagrupar;
map<string,int> contarPalabras(size_t tamanoDePalabras,string archivo);

int main() {
  cout << "ingrese el numero de caracteres a agrupar" <<endl;
  cin>>numeroDeBitsagrupar;
  map<string,int> diccionarioContarPalabra=contarPalabras(numeroDeBitsagrupar,"casos/in1.txt");
  string prueba ="escribir";
  ofstream file("out.txt",ofstream::out);
  for(size_t i=0;i<prueba.size();i++){
    file<<prueba[i];
  }
  file.close();
  return 0;
}
map<string,int>contarPalabras(size_t tamanoDePalabras,string archivo){
  map<string,int> diccionarioContarPalabra;
  string palabra="";
  fstream file(archivo.c_str());
  while(file.good()) {
    for (size_t indCaracter = 0; indCaracter < tamanoDePalabras; indCaracter++) {
      char caracter=file.get();
      palabra.push_back(caracter);
    }
    if(diccionarioContarPalabra.count(palabra)==0){
      diccionarioContarPalabra[palabra]=0;
    }
    diccionarioContarPalabra[palabra]++;
  }
  return diccionarioContarPalabra;
}
