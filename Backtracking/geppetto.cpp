#include <bits/stdc++.h> 
#include <string>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

set <pair<int,int>> prohibido;
int contador=0;
int ingredientes;
int prohibiciones; 

void cocina(int ingrediente, vector<int> pizza){

        if(ingrediente>ingredientes){
            contador++;
            return;
        }

        cocina(ingrediente+1, pizza);
        for(auto it : pizza){
            int maxIng = max(ingrediente, (int) it);
            int minIng = min(ingrediente, (int) it);
            pair<int,int> par = make_pair(minIng,maxIng);
            auto oit = prohibido.find(par);

            bool existe = par.first == oit->first &&  par.second == oit->second;

            if(existe){
                return;
            }
        }
        pizza.push_back(ingrediente);
        cocina(ingrediente+1, pizza);

        

}

void readint(int& ret){
    ret = 0;
    char r;
    bool start=false,neg=false;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(neg) ret *= -1;
}

int main(){
    input;

    readint(ingredientes);
    readint(prohibiciones);
    if(prohibiciones==0){
        prohibido.insert(make_pair(21,21));
    }
    int a, b;
    for(int i=0; i<prohibiciones; i++){
        readint(a);
        readint(b);
        int minI = min(a,b);
        int maxI = max(a,b);
        prohibido.insert(make_pair(minI,maxI));
    }
    int i=0;
    vector<int> pizza;
    pizza.push_back(0);
    cocina(1,pizza);

    cout<<contador<<endl;
    return 0;
}