#include <bits/stdc++.h> 
using namespace std;
 
int binarySearch(long int n,long int ini,long int fin){
    long int mid = (ini + fin) / 2;
 
    if (ini > fin) {
        return -1;
    }
    if (mid * mid == n) {
        return mid;
    }else if (mid * mid > n) {
        return binarySearch( n, ini, mid - 1);
    } else {
        return binarySearch(n, mid + 1, fin);
    }
}
 
int main()
{
    long int n =25;
 
    cout << binarySearch(n, 1, n);
    return 0;
}