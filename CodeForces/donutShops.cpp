#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (){
    
    
    int n; cin>>n;
    while(n--){
        ll a, b, c;
        cin>>a>>b>>c;
        ll r1, r2;
    
        if(a < c){
            r1 = 1;
        } else {
            r1 = -1;
        }
    
        if(b*a > c){
            r2 = b;
        }else{
            r2 = -1;
        }
    
        cout << r1 << " "<< r2 << "\n";
    }
    
    return 0;
}
