#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
    
    int t; cin>>t;
    while(t--){
        ll a, b; cin>>a>>b;
        if(a == b){
            cout << "2\n";
        }else if(a < b){
            cout << "1\n";
        }else{
            ll cont = 0; ll res = 1e9+100;
            int i = 0;
            if(b == 1){
                i = 1;
            } 
            
            for(;i<29;i++){
                cont = i;
                //cout << "Con " << i << "\n";
                ll aux = a;
                while(aux > 0){
                    aux = floor(aux/(b+i));
                    cont++;
                    //cout << aux << endl;
                }
                res = min(res, cont);
            }
            
            cout << res << endl;
        }
    }
    
    
    return 0;
}
