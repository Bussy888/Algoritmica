#include <bits/stdc++.h>
using namespace std;
 
int min(int x, int y, int z) { 
    return min(min(x, y), z); 
    }
 
int editDistDP(string str1, string str2, int m, int n){
    int dp[m + 1][n + 1];//2
 
    for (int i = 0; i <= m; i++) {//m
        for (int j = 0; j <= n; j++) {//n
            if (i == 0){//2
                dp[i][j] = j; 
            }else if (j == 0){//2
                dp[i][j] = i;
            }else if (str1[i - 1] == str2[j - 1]){//4
                dp[i][j] = dp[i - 1][j - 1];
            }else{//13
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
            }
        }
    }
 
    return dp[m][n];//1
}
 
int main(){
    string str1 = "superman";
    string str2 = "batman";
 
    cout << editDistDP(str1, str2, str1.length(), str2.length());
 
    return 0;
}