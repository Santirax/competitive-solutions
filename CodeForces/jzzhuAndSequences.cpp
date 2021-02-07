#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll modulo = 1e9+7;

//a % b, de la manera que pide el problema
ll mod (ll a, ll b){
   if(b < 0) 
     return mod(a, -b);   
   ll ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}


ll nearestPower(ll n){
    ll x = 6;
    while(x+6 < n){
        x += 6;
        
    }
    return x;
}

int main(){
    
    ll x, y; cin>>x>>y;
    
    ll f1 = x, f2 = y;
    vector<ll>res(10);
    
    res[1] = f1;
    res[2] = f2;
    res[3] = f2-f1;
    res[4] = -f1;
    res[5] = -f2;
    res[6] = f1-f2;
    res[7] = f1;
    res[8] = f2;
    //res[9] = f2-f1;
    //cout << -1 % modulo << endl;
    
    
    ll n; cin>>n;
    if(n < 9)cout<< mod(res[n],modulo) <<endl;
    else
    cout << mod( res[ n-nearestPower(n) ], modulo) << endl;
    
}
