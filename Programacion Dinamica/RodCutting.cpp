#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;
int t;
int k;
 
int max(int a, int b) {
    if(a>b){
        return a;
    }else{
        return b;
    }
}
 
int cutRod(int valor[], int index, int n){
    if (index == 0) {
        return n * valor[0];
    }
    int notCut = cutRod(valor,index - 1,n);
    int cut = INT_MIN;
    int rod_length = index + 1;
 
    if (rod_length <= n){
        cut = valor[index] + cutRod(valor,index,n - rod_length);
    }   
    return max(notCut, cut);
}
 
int main(){
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "El valor maximo obtenible es: " << cutRod(arr, size - 1, size);
    getchar();
    return 0;
}