#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
    
    int t; cin>>t;
    while(t--){
        
        map<ll, ll>cont;
        
        int n; cin>>n;
        vector <ll> vec(n); 
        for(int i = 0; i < n; i++){
            cin>>vec[i];
            cont[vec[i]]++;
        }
        
        set<ll>rep;
        vector<ll>rep2;
        for(auto[x, y]: cont){
            rep.insert(y);
            rep2.push_back(y);
        }
        
        ll res = 1e9;
        for(ll y: rep){
            ll cont = 0;
            for(int i = 0; i < rep2.size(); i++){
                if(rep2[i] < y){
                    cont += rep2[i];
                } else if(rep2[i] > y){
                    cont += (rep2[i]-y); 
                } 
            }
            res = min(res, cont);            
        }
        
        cout << res << "\n";
    }
    
    
    return 0;
}
