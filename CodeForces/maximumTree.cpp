#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n; cin>>n;
    vector<int>vec(n);
    for(int & x: vec)cin>>x;
    
    sort(vec.rbegin(), vec.rend());
    long long res = 1, prev = 1;
    for(int i = 0; i < vec.size(); i++){
        long long act = prev*vec[i];
        res += act;
        prev = vec[i]*prev;
    }
    
    cout << res << endl;
    
    return 0;
}
