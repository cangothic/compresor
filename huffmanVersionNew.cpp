#include <bits/stdc++.h>
/*
 «Copyright brian giraldo and carlos vergara 2016>>
  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
*/
using namespace std;
struct Nodo{
    int peso;
    Nodo* izq;
    Nodo* der;
    string valor;
    Nodo(){
        izq = NULL;
        der = NULL;
    }
    Nodo(int _peso){
        peso = _peso;
        izq = NULL;
        der = NULL;
    }
    Nodo(int _peso,string _valor){
        peso = _peso;
        valor = _valor;
        izq = NULL;
        der = NULL;
    }

    ~Nodo(){
    }
};
bool operator >(const Nodo& lhs, const Nodo& rhs)
{
    return lhs.peso > rhs.peso;
}

void dfs(Nodo n, string codificacion,map<string,string> &mapaCodificacion){
    if(n.valor!=""){
        cout<<n.valor<<" codificado es "<<codificacion<<endl;
        mapaCodificacion[n.valor] = codificacion;
    }
    if(n.izq!=nullptr){
        dfs(*n.izq,codificacion+'0',mapaCodificacion);
    }
    if(n.der!=nullptr){
        dfs(*n.der,codificacion+'1',mapaCodificacion);
    }
}
int main(){
    int tamanoPalabra = 4;
    int i=0;
    string palabra ="";
    string dirArchibo = "casos/in1.txt";
    map<string,int> mapa;
    for(ifstream file(dirArchibo.c_str()); file.good();i++){
        char caracter = file.get();
        palabra+=caracter;
        if(i%tamanoPalabra==tamanoPalabra-1){
            mapa[palabra]++;
            palabra = "";
        }
    }
    palabra = "";
    priority_queue<Nodo,vector<Nodo>,greater<Nodo>> p;
    for(map<string,int>::iterator it=mapa.begin();it!=mapa.end();it++){
        Nodo* nodo = new Nodo(it->second,it->first);
        p.push(*nodo);
    }

    while(p.size()>1){
        Nodo* nodoIzquierdo= new Nodo(p.top());p.pop();
        Nodo* nodoDerecho = new Nodo(p.top());p.pop();
        Nodo* nodoPadre = new Nodo((nodoIzquierdo->peso)+(nodoDerecho->peso));
        nodoPadre->izq = nodoIzquierdo;
        nodoPadre->der = nodoDerecho;
        p.push(*nodoPadre);

    }
    Nodo padre = p.top();p.pop();
    map<string,string> mapaCodificacion; /*antes y despues*/

    dfs(padre,"",mapaCodificacion);


    ofstream fileOut("out.txt", ofstream::out);
    i =0;
    for(ifstream file(dirArchibo.c_str()); file.good();i++){
        char caracter = file.get();
        palabra+=caracter;
        if(i%tamanoPalabra==tamanoPalabra-1){
            fileOut<<mapaCodificacion[palabra];
            palabra = "";
        }
    }
    fileOut.close();

    return 0;
}
