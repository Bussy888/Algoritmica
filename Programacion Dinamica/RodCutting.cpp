#include <bits/stdc++.h> 
using namespace std;
int t;
int k;
 
int max(int a, int b) {
    if(a>b){//2
        return a;
    }else{
        return b;
    }
}
 
int cutRod(int valor[], int index, int n){
    if (index == 0) {//1
        return n * valor[0];//1
    }
    int notCut = cutRod(valor,index - 1,n);//n
    int cut = INT_MIN;//1
    int rod_length = index + 1;//2
 
    if (rod_length <= n){//1
        cut = valor[index] + cutRod(valor,index,n - rod_length);//n
    }   
    return max(notCut, cut);//2
}
 
int main(){
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "El valor maximo obtenible es: " << cutRod(arr, size - 1, size);
    getchar();
    return 0;
}