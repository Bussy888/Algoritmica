#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n;
int x;
bool f(int number) {
    return number*number > x;
}

void bs() {
    int ini = 0;
    int fin = 10000;
    int respuesta=0;
    while(ini < fin - 1 ) {
        int mid = (ini + fin) / 2;
        //cout<<mid<<" "<<x<<endl;
        if(f(mid)) {  /// MOdificar la funcion de condicion
            fin = mid;
        } else {
            ini = mid;
        }
        if(mid*mid==x){
        	respuesta = 1;
        	cout<<"True"<<endl;
        	break;
        }
    }
    if(respuesta == 0){
    	cout<<"False"<<endl;
    }
}
int main() {
    cin>>n;
    for (int i = 0; i < n; i++){
    cin>>x;
    bs();
    }
    return 0;
}