#include <bits/stdc++.h>
using namespace std;
 
int min(int x, int y, int z) {
    return min(min(x, y), z);
    }
 
int editDist(string str1, string str2, int size1, int size2)
{
    if (size1 == 0){
        return size2;
    }
    if (size2 == 0){
        return size1;
    }
    if (str1[size1 - 1] == str2[size2 - 1]){
        return editDist(str1, str2, size1 - 1, size2 - 1);
    }
    return 1+min(editDist(str1, str2, size1, size2 - 1), // Insertar
                 editDist(str1, str2, size1 - 1, size2), // Remover
                 editDist(str1, str2, size1 - 1, size2 - 1) // Reemplazar
                );
}
 
int main()
{
    string str1 = "spiderman";
    string str2 = "superman";
 
    cout << editDist(str1, str2, str1.length(), str2.length());
 
    return 0;
}