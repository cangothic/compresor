#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
size_t numero_agrupar;
map<string,int> diccionario;
int main() {
  cout << "ingrese el numero de caracteres a agrupar" <<endl;
  cin>>numero_agrupar;
  string palabra="";
  for (fstream file("in1.txt");file.good();) {
    for (size_t i = 0; i < numero_agrupar; i++) {
      char character=file.get();
      palabra.push_back(character);
    }
    if(diccionario.count(palabra)==0){
      diccionario[palabra]=0;
    }
    diccionario[palabra]++;
  }
  string prueba ="escribir";
  ofstream file("out.txt",ofstream::out);
  for(size_t i=0;i<prueba.size();i++){
    file<<prueba[i];
  }
  file.close();
  return 0;
}
