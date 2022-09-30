#include <bits/stdc++.h>

using namespace std;

int main (){
    
    int t; cin>>t;
    while(t--){
        
        int n, x, y;
        cin>>n>>x>>y;
        
        if(x == 0 && y == 0){
            cout << "-1\n";
        } else if(x == 0){
            //cout << "Cero en x\n";
            if( (n-1) % y == 0 ) {
                
                int res = 1;
                for(int i = 1, cont = 0; i <= n-1; i++){
                    
                    if( cont == y ){
                        res = i+1;
                        cont = 0;
                    }
                    cont++;
                    cout << res << " ";
                }
                cout << "\n";
                
            } else {
                cout << "-1\n";
            }
            
        } else if(y == 0){
            //cout << "Cero en y\n";
            if( (n-1) % x == 0 ) {
                
                int res = 1;
                for(int i = 1, cont = 0; i <= n-1; i++){
                    
                    if( cont == x ){
                        res = i+1;
                        cont = 0;
                    }
                    cont++;
                    cout << res << " ";
                }
                cout << "\n";
                
            } else {
                cout << "-1\n";
            }
            
        } else {
            //cout << "No creos\n";
            cout << "-1\n";
            
        }
        
        
        
    }
    
    
    
    return 0;
}