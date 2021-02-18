#include <bits/stdc++.h>
using namespace std;



int main (){
    
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        vector<int>vec(n);
        for(int & x: vec)cin>>x;
        int res = 0;
        for(int i = 0; i < vec.size()-1; i++){
            
            if((double)max(vec[i], vec[i+1])/(double)min(vec[i], vec[i+1]) > 2){
                int maxi = max(vec[i], vec[i+1]);
                int mini = min(vec[i], vec[i+1]);
                int cont = 0;
                //cout << maxi << ", " << mini << endl;
                while(mini < maxi){
                    mini += mini;
                    cont++;
                }
                res += (cont-1);
            }
            
        }
        
        cout << res << endl;
        
    }
    
    
    
    return 0;
}
