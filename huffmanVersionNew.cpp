#include <bits/stdc++.h>
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
    int tamDiccionario = 4;
    int i=0;
    string palabra = "";
    map<string,int> mapa;
    for(ifstream file("casos/in1.txt"); file.good();i++){
        char caracter = file.get();
        palabra+=caracter;
        if(i%tamDiccionario==tamDiccionario-1){
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
    for(ifstream file("casos/in1.txt"); file.good();i++){
        char caracter = file.get();
        palabra+=caracter;
        if(i%tamDiccionario==tamDiccionario-1){
            cout<<"agregare la palabra "<<palabra<<" con codificacion "<<mapaCodificacion[palabra]<<endl;
            fileOut<<mapaCodificacion[palabra];
            palabra = "";
        }
    }
    fileOut.close();

    return 0;
}
