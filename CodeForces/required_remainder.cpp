#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main (){
    
    int t; cin>>t;
    ld x, y, n;
    
    while(t--){
        cin>>x>>y>>n;
        ld res = floor((n-y)/x);
        cout << fixed << setprecision(0) << res*x + y << endl;
    }
    
    return 0;
}
