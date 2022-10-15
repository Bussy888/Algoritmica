#include <bits/stdc++.h> 

using namespace std;
class Grafo
{
public:
    Grafo();
    Grafo(int nodos);
    vector< vector<int> > prim();
private:
    const int INF = numeric_limits<int>::max();
    int cantidadNodos; //cantidad de nodos
    vector< vector<int> > adyacencia; //matriz de adyacencia
};
Grafo::Grafo(int nodos)
{
    this->cantidadNodos = nodos;
        this->adyacencia = vector< vector<int> > (cantidadNodos);

        for(int i = 0; i < cantidadNodos; i++)
            adyacencia[i] = vector<int> (cantidadNodos, INF);
}

vector< vector<int> > Grafo :: prim(){
    // uso una copia de adyacencia porque necesito eliminar columnas
    vector< vector<int> > adyacencia = this->adyacencia;
    vector< vector<int> > arbol(cantidadNodos);
    vector<int> markedLines;
    vector<int> :: iterator vectorIterator;

    // Inicializo las distancias del arbol en INF.
    for(int i = 0; i < cantidadNodos; i++)
        arbol[i] = vector<int> (cantidadNodos, INF);

    int padre = 0;
    int hijo = 0;
    while(markedLines.size() + 1 < cantidadNodos){
        padre = hijo;
        // Marco la fila y elimino la columna del nodo padre.
        markedLines.push_back(padre);
        for(int i = 0; i < cantidadNodos; i++)
            adyacencia[i][padre] = INF;

        // Encuentro la menor distancia entre las filas marcadas.
        // El nodo padre es la linea marcada y el nodo hijo es la columna del minimo.
        int min = INF;
        for(vectorIterator = markedLines.begin(); vectorIterator != markedLines.end(); vectorIterator++)
            for(int i = 0; i < cantidadNodos; i++)
                if(min > adyacencia[*vectorIterator][i]){
                    min = adyacencia[*vectorIterator][i];
                    padre = *vectorIterator;
                    hijo = i;
                }

        arbol[padre][hijo] = min;
        arbol[hijo][padre] = min;
    }
    return arbol;
}