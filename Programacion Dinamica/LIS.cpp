#include <bits/stdc++.h> 
#define INF 1e9
using namespace std;

int n;
int buscando; 
int seq[100010];
vector<int> subseq;

bool f(int k) {
    return subseq[k]>buscando;
}
int bs() {
    long  inicio  = 0;
    long long  fin = subseq.size()-1;
    long long  mid = (inicio + fin)/2; 
    while( inicio<fin ) {
        if(f(mid)) {
            fin = mid;
        }else{
            inicio = mid+1;
        }
        mid = (inicio+fin)/2;
    }
    return mid;


}

int lis(){
    int longitud = 1;//1
    subseq.push_back(-INF);
    subseq.push_back(seq[1]);
    for(int i=1; i<n;i++){//n
        if(seq[i+1]>subseq.back()){//1
            subseq.push_back(seq[i+1]);//2
            longitud++;//2
        }else{
            buscando=seq[i+1];//2
            int index = bs();//log n
            if(index!=1){//1
                subseq[index]=seq[i+1];//4
            }
        }
    }
    return longitud;//1
}

int main() {
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
           cin>>seq[i];
        }
    }
    cout<<lis()<<endl;
    return 0;
}