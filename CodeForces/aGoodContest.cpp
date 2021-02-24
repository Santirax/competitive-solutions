#include <bits/stdc++.h>
using namespace std;
int main (){
    
    int n; cin>>n;
    bool ban = false;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        int a, b;
        cin>>a>>b;
        if(a >= 2400 && b > a)ban = true;
    }
    
    if(ban) cout << "YES\n"; else cout << "NO\n";
    
    return 0;
}
