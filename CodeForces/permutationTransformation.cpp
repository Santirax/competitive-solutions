#include <bits/stdc++.h>
using namespace std;

int maxPosition(int i, int j, vector<int> & perm){
    int maxPosi, maxi = -1;
    
    for(int x = i; x <= j; x++){
        if(perm[x] > maxi){
            maxi = perm[x];
            maxPosi = x;
        }
    }
    return maxPosi;
}

void checkLevel(int i, int j, int level, vector<int> & perm, vector<int> &levels){
    
    if(i > j || i >= perm.size() || j < 0 ) return;
    
    int maxPos = maxPosition(i, j, perm);
    levels[maxPos] = level;
    
    checkLevel(i, maxPos-1, level+1, perm, levels);
    checkLevel(maxPos+1, j, level+1, perm, levels);
}

int main (){
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        vector<int> perm(n);
        vector<int> levels(n);
        for(int & x: perm)cin>>x;
        
        checkLevel(0, perm.size()-1, 0, perm, levels);
        
        for(int x: levels)cout<<x<<" ";
        cout << endl;
        
    }
    
    
    return 0;
}
