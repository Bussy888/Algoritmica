#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

vector<pair<int, int>> grafo[100000];
vector<pair<int,int>> mst[100000];
set <int> nodos[100000];
multiset<pair<int,int>> priorityQueue;
int visitados[100000];
int parent[100000];
int parentPeso[100000];
int aristas;
int numNodos;

void findMST(int nodoInicial){
    priorityQueue.insert(make_pair(0, nodoInicial));
    memset(visitados, false, sizeof(visitados));
    while (!priorityQueue.empty()){
        pair<int, int> nodoActual = *priorityQueue.begin();
        priorityQueue.erase(priorityQueue.begin());
        int verticeActual = nodoActual.second;
        if (!visitados[verticeActual]){
            visitados[verticeActual] = true;
            for (int i = 0; i < grafo[verticeActual].size(); i++){
                int verticeVecino = grafo[verticeActual][i].first;
                int pesoVecino = grafo[verticeActual][i].second;
                if(!visitados[verticeVecino]){
                    if(parent[verticeVecino]==-1 || (pesoVecino<parentPeso[verticeVecino]
                    && parentPeso[verticeVecino]!=-1)){
                        parent[verticeVecino]=verticeActual;
                        parentPeso[verticeVecino]=pesoVecino;
                    }
                    priorityQueue.insert(make_pair(pesoVecino, verticeVecino));
                }
            }
            if(parent[verticeActual]!=-1 && parentPeso[verticeActual]!=-1 ){
                mst[verticeActual].push_back(
                            make_pair(parent[verticeActual],parentPeso[verticeActual]));
                mst[parent[verticeActual]].push_back(
                            make_pair(verticeActual,parentPeso[verticeActual]));
            }
            

        }
    }
}

void printMst(){
	cout << "Destino\tOrigen\tPeso\n";
	for(int i = 0; i < numNodos; i++){
        vector<pair<int,int>> nodoActual = mst[i];
        for (auto it: nodoActual){
            cout << i+1 << "\t" << it.first + 1<< "\t" << it.second << "\n";
        }
	}
}

int main(){
    input;
    cin>>numNodos>>aristas;
    for (int i = 0; i < aristas; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        grafo[a].push_back(make_pair(b,c));
        grafo[b].push_back(make_pair(a,c));
    }
    memset(parent, -1, sizeof(parent));
    memset(parent, -1, sizeof(parentPeso));
    int nodoInicial;
    cin>>nodoInicial;
    nodoInicial--;
    findMST(nodoInicial);
    printMst();
    return 0;
}
