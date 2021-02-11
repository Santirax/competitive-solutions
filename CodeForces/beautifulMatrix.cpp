#include <bits/stdc++.h>
using namespace std;
int main (){
    
    int matrix[6][6];
    int posI, posJ;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == 1){
                posI = i;
                posJ = j;
            }
        }
    }
    
    cout << abs(3-posI) + abs(3-posJ) << endl;
    
    
    return 0;
}
