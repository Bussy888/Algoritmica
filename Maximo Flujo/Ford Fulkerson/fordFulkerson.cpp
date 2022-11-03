#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101   

int grafo[MAX_N][MAX_N];     
int path[MAX_N];                
int nodes;
int maxFlow(int start,int theend) { 
    int maxFlow = 0;
    while(true) { 
        memset(path, -1, sizeof(path));
        stack<int> pila;
        pila.push(start);
        path[start] = start; 
        while(!pila.empty() && path[theend]==-1) {
            int currentNode = pila.top();
            pila.pop();
            for(int i = 0 ; i < nodes ; i++) {
                if(grafo[currentNode][i] > 0 && path[i]==-1)  {  // puedo visitar? 
                    path[i] = currentNode;                       // guardar camino 
                    pila.push(i);                                  // agregar a la cola
                }   
            }
        }
       
        if(path[theend]==-1) {
            break;
        }
        int minFlow = 1e9;
        for(int from = path[theend],to = theend; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]);
        }
        
        for(int from = path[theend],to = theend; from!=to ; from = path[to = from]) {
            grafo[from][to] -= minFlow; // grafo de capacidad
            grafo[to][from] += minFlow; // grafo residual
        }
        maxFlow += minFlow;
    }
    return maxFlow;
}



int main() {
input;
int  aristas, nroCases;
cin>>nroCases; 
while(nroCases--) {
    cin>>nodes>>aristas;
    int start,theend; 
    cin>>start>>theend;
    memset(grafo,0,sizeof(grafo));
    for(int i=0;i<aristas;i++) {
        int from, to, capacity; 
        cin>>from>>to>>capacity;
        grafo[from][to] = capacity;          // camino capacidad
        grafo[to][from] = 0;                //  flujo camino residual 
    }
    cout<<maxFlow(start,theend)<<endl;
    }    
}