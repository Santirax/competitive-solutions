#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        
        ll n, x, sum = 0; cin>>n>>x;
        vector<ll> nums(n);
        vector<ll> aux (n);
        bool ban = true;
        for(int i = 0; i < n; i++){
            cin>>nums[i];
            aux[i] = nums[i];
            sum += nums[i];
        }
        
        while(ban){
            for(int i = 0; i < n; i++){
                if(aux[i] % x == 0){
                    aux[i] = aux[i] / x;
                } else {
                    aux[i] = -1; 
                }
            }
            
            for(int i = 0; i < n; i++){
                if(aux[i] != -1)sum+=nums[i];
                else {ban = false; break;} 
            }
        }
        
        cout << sum << "\n";
        
    }
    
    return 0;
}
