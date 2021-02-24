#include <bits/stdc++.h>
using namespace std;

int main (){
    
    int n, m;
    cin>>n>>m;
    
    vector<int>bulbs(m, 0);
    
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        for(int j = 0; j < x; j++){
            int y; cin>>y;
            bulbs[y-1]++;
        }
    }
    
    bool ban = true;
    for(int x: bulbs){
        if(x == 0){
            ban = false; break;
        }
    }
    
    if(ban)cout<<"YES\n"; else cout<<"NO\n";
    
    return 0;
}
