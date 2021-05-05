/*
90
1 2 3    7 4 1
4 5 6 -> 8 5 2
7 8 9    9 6 3

180
1 2 3    9 8 7
4 5 6 -> 6 5 4
7 8 9    3 2 1

270
1 2 3    3 6 9
4 5 6 -> 2 5 8
7 8 9    1 4 7

verRef
1 2 3    7 8 9
4 5 6 -> 4 5 6
7 8 9    1 2 3
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> vvc;

bool isEqual(vvc m, vvc n){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m.size(); j++){
            if(m[i][j] != n[i][j]) return false;
        }
    }
    return true;
}

vvc rot90(vvc & matrix){
    vvc newMatrix = matrix;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            newMatrix[j][matrix.size()-i-1] = matrix[i][j]; 
        }
    }
    
    return newMatrix; 
}

vvc rot180(vvc & matrix){
    vvc newMatrix = matrix;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            newMatrix[matrix.size()-i-1][matrix.size()-j-1] = matrix[i][j]; 
        }
    }
    
    return newMatrix; 
}

vvc rot270(vvc & matrix){
    vvc newMatrix = matrix;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            newMatrix[matrix.size()-j-1][i] = matrix[i][j]; 
        }
    }
    
    return newMatrix; 
}

vvc verRef(vvc & matrix){
    vvc newMatrix = matrix;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size(); j++){
            newMatrix[matrix.size()-i-1][j] = matrix[i][j]; 
        }
    }
    
    return newMatrix; 
}


int main (){    
    
    int n; int cont = 1;
    while(cin>>n){
        
        //char matrix[n][n];
        vvc matrix(n, vector<char>(n, 'c'));
        vvc transform (n, vector<char>(n, 'c'));
        /*for(auto x: matrix){
            for(char y: x)
                cout << y << " ";
            cout << endl;
        }*/
        string s1, s2; 
        for(int i = 0; i < n; i++){
            cin>>s1>>s2;
            for(int j = 0; j < n; j++)matrix[i][j] = s1[j];
            for(int j = 0; j < n; j++)transform[i][j] = s2[j];
            
        }
        
        cout << "Pattern "<<cont<<" was ";
        cont++;
        if(isEqual(matrix, transform)){
            cout << "preserved.\n";
        } else {
            
            auto matAux = rot90(matrix);
            if(isEqual(matAux, transform)){
                cout << "rotated 90 degrees.\n"; continue;
            }
            matAux = rot180(matrix);
            if(isEqual(matAux, transform)){
                cout << "rotated 180 degrees.\n"; continue;
            }
            matAux = rot270(matrix);
            if(isEqual(matAux, transform)){
                cout << "rotated 270 degrees.\n"; continue;
            }
            
            matAux = verRef(matrix);
            if(isEqual(matAux, transform)){
               cout << "reflected vertically.\n"; continue; 
            }
        
            auto aux = matAux;
        
            matAux = rot90(aux);
            if(isEqual(matAux, transform)){
                cout << "reflected vertically and rotated 90 degrees.\n"; continue;
            }
            matAux = rot180(aux);
            if(isEqual(matAux, transform)){
                cout << "reflected vertically and rotated 180 degrees.\n"; continue;
            }
            matAux = rot270(aux);
            if(isEqual(matAux, transform)){
                cout << "reflected vertically and rotated 270 degrees.\n"; continue;
            }
            
            cout << "improperly transformed.\n";
        }
        
        /*cout << "Original\n";
        for(auto x: matrix){
            for(char y: x)
                cout << y;
            cout << endl;
        }
        
        cout << "\n90 rot\n";
        auto mt = rot90(matrix);
        
        for(auto x: mt){
            for(char y: x)
                cout << y;
            cout << endl;
        }
        
        cout << "\n180 rot\n";
        mt = rot180(matrix);
        
        for(auto x: mt){
            for(char y: x)
                cout << y;
            cout << endl;
        }
        
        cout << "\n270 rot\n";
        mt = rot270(matrix);
        
        for(auto x: mt){
            for(char y: x)
                cout << y;
            cout << endl;
        }
        
        cout << "\nverRef\n";
        mt = verRef(matrix);
        
        for(auto x: mt){
            for(char y: x)
                cout << y;
            cout << endl;
        }
        
        cout << "\nTransformada\n";
        for(auto x: transform){
            for(char y: x)
                cout << y;
            cout << endl;
        } */
            
        
    }
    return 0;
}
