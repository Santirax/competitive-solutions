#include <bits/stdc++.h>
using namespace std;

int main (){
    
    int t; cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        bool ban = true;
        long long int cont = 0;
        
        while(n != 1){
            if(n % 2 == 0){
                n /= 2;
            } else if (n % 3 == 0){
                n = (2*n)/3;
            } else if (n % 5 == 0){
                n = (4*n)/5;
            } else {
                ban = false; break;
            }
            cont++;
        }
        if(ban)cout << cont << endl;
        else cout << -1 << endl;
    }
    
    
    return 0;

}
