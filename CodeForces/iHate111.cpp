#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, bool> DP; 

bool solve(long long number){
    for(int i = 0; i < 20; i++){
        if(number % 11 == 0) return true;
        number -= 111;
        if(number < 0) break;
    }
    return false;
}

int main(){

    int t; cin>>t;
    while(t--){

        long long x; cin>>x;
        if(x > 1099) cout << "YES\n"; else
        cout << (solve(x) ? "YES" : "NO") << endl ;
    }
    return 0;
}
