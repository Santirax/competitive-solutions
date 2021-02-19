#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPosible(ll x, vector< pair<ll, int> > & tokens){
    
    if(x == tokens.size()-1)return true;
    
    ll sum = 0;
    for(int i = 0; i <= x; i++){
        sum += tokens[i].first;
    }
    
    if(sum >= tokens[x+1].first){
        
        for(int i = x+1; i < tokens.size()-1; i++){
            if((sum + tokens[i].first) >= tokens[i+1].first){
                sum+=tokens[i].first;
            } else {
                return false;
            }
        }
        return true;
    } 
    
    return false;
}

ll binarySearch(vector< pair<ll, int> > & tokens){
    
    ll ini = 0, fin = tokens.size()-1;
    ll mid;
    
    ll pos_res;
    while(ini <= fin){
        
        mid = (ini+fin)/2;
        if(isPosible(mid, tokens)){
            fin = mid-1;
            pos_res = mid;
        }else{
            ini = mid+1;
        }
        
    }
    return pos_res;
}

int main(){
    
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        vector< pair<ll, int> > tokens;
        for(int i = 0; i < n; i++){
            ll x;
            cin>>x;
            tokens.push_back({x, i+1});
        }
        
        sort(tokens.begin(), tokens.end());
        ll pos = binarySearch(tokens);
        vector<int>res; 
        for(int i = pos; i < tokens.size(); i++){
            res.push_back(tokens[i].second);
        }
        sort(res.begin(), res.end());
        
        cout << res.size() << "\n";
        for(ll x: res){
            cout << x <<" ";
        }
         cout << "\n";
    }
    
    
    
    return 0;
}
