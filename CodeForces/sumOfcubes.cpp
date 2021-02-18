#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isInt(long double x){
    
    if(((ll)x - x) == 0.0)return true;
    return false;
    
}
int main (){
    
    int t; cin>>t; 
    while(t--){        
        ll x; cin>>x;
        
        ll rot = cbrtl(x);
        
        bool ban = false;
        for(int i = 1; i <= rot; i++){
            
            long double a = cbrtl(x-pow(i,3));
            if(isInt(a) && a != 0.0){
                //cout << a << " " << pow(i,3) << endl;
                ban = true; break;
                
            }
        }
        
        if(ban)cout<<"YES\n"; else cout <<"NO\n";
    }
    
    
    return 0;
}
