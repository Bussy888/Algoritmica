#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

#define SIZE 100000 + 1
#define INF 10000000

using namespace std; 

int n,m;
int grafo[501][501];



void floydWarshall(){
    for(int pivote = 1; pivote<= n ; pivote++){
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
               grafo[i][j] = min(grafo[i][j],(grafo[i][pivote]+grafo[pivote][j]));
            }
        }
    }
}

int main() {
    input;
    cin>>n>>m;
    memset(grafo,-1,sizeof(grafo));
    for(int i = 0 ; i < m; i++) {
        int nodo1,nodo2,peso; 
        cin>>nodo1>>nodo2>>peso;
        grafo[nodo1][nodo2] = peso;
    }
     for(int i=1;i<=n;i++) {
        for(int j =1; j <= n ;j++ ) {
          if(i==j) {
          grafo[i][j]=0;
          }else{
              if(grafo[i][j]==-1){
                  grafo[i][j] = INF;
              }
          }
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++) {
        for(int j =1; j <= n ;j++ ) {
            cout<<"[" <<grafo[i][j]<<"]";
        }
        cout<<endl;
    }


    floydWarshall();

    return 0;
}