#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main (){    
    
    int n; cin>>n;
    vector<ll>boxes(n);
    
    for(ll & x: boxes){
        cin>>x;
    }
    
    sort(boxes.rbegin(), boxes.rend());
    
    vector<ll> boxIntoBox(n, 1e9+10);
    
    //for(ll x: boxes)cout<<x<<"\n";
    
    for(ll x: boxes){
        
        if(x < boxIntoBox[0]){
            boxIntoBox[0] = x;
        } else {
            int i = 0;
            while(x >= boxIntoBox[i]){
                i++;
            }
            boxIntoBox[i] = x;
        }
    }
    int cont = 0;
    for(ll x: boxIntoBox){
        if(x < 1e9+10){
            cont++;
        }
    }
    
    cout << cont << endl;
    
    return 0;
}
