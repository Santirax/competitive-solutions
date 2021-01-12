#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n; j++){
            cout<<"*";
        }
        cout << endl;
    }*/
    
    cout << "*";
    for(int i = 0; i < n-2; i++)cout <<" ";
    cout << "* ";
    
    for(int i = 0; i < n; i++)cout<<"*";
    
    cout << endl;
    
    for(int j = 0; j < n-2; j++){
        cout << "*";
        for(int i = 0; i < n-2; i++)cout <<" ";
        cout << "* ";
        
        cout << "*";
        for(int i = 0; i < n-2; i++)cout <<" ";
        cout << "*";
        
        cout <<endl;
    }
    
    for(int i = 0; i < n; i++)cout<<"*";
    
    cout << " *";
    for(int i = 0; i < n-2; i++)cout <<" ";
    cout << "*";
    
    cout << endl;
    return 0;
}
