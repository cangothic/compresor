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
struct Compare
{
  bool operator()(const Nodo& lhs, const Nodo& rhs) const
  {
    return lhs.peso > rhs.peso;
  }
};

void dfs(Nodo n, string codificacion,map<string,string> &mapaCodificacion){
    cout<<n.peso<<endl;
    if(n.valor!=""){
        mapaCodificacion[n.valor] = codificacion;
        cout<<n.valor<<" es "<<codificacion<<endl;
    }
    if(n.izq!=nullptr){
        dfs(*n.izq,codificacion+='0',mapaCodificacion);
    }
    if(n.der!=nullptr){
        dfs(*n.der,codificacion+='1',mapaCodificacion);
    }
}
int main(){
    cout<<"hola"<<endl;
    int tamDiccionario = 4;
    int i=0;
    string palabra = "";
    map<string,int> mapa;
    for(ifstream file("casos/in1.txt"); file.good();i++){
        char caracter = file.get();
        palabra+=caracter;
        if(i%4==3){
            mapa[palabra]++;
            palabra = "";
        }
    }
    priority_queue<Nodo,vector<Nodo>,Compare> p;
    for(map<string,int>::iterator it=mapa.begin();it!=mapa.end();it++){
        Nodo* nodo = new Nodo(it->second,it->first);
        p.push(*nodo);
    }

    while(p.size()>1){
        Nodo* n11 = new Nodo(p.top());p.pop();
        Nodo* n22 = new Nodo(p.top());p.pop();
        Nodo* n3 = new Nodo(n11->peso+n22->peso);
        n3->izq = n11;
        n3->der = n22;
        p.push(*n3);

    }
    Nodo padre = p.top();p.pop();
    map<string,string> mapaCodificacion; /*antes y despues*/

    dfs(padre,"",mapaCodificacion);
    return 0;
}
