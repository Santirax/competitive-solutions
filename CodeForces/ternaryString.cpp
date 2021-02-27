#include <bits/stdc++.h>
using namespace std;

bool isComplete(map<int, int> & bucket){
    for(auto x: bucket){
        if(x.second <= 0)return false;
    }
    return true;
}

int main (){
    //Rellenar de 0's
    /*int buck[3] = {'\0'};
    
    for(int i = 0; i < 3; i++){
        cout << buck[i] << "\n";
    }*/
    int t; cin>>t;
    while(t--){
        
        string s; cin>>s;
        
        map<int, int>bucket;
        bucket[1] = 0;
        bucket[2] = 0;
        bucket[3] = 0;
        
        int i = 0, j = 0;
        int pivote = j;
        int current = 0;
        int res = 1e6;
        
        while(i < s.size()){
            
            int aux = s[pivote]-'0';
            //cout <<"Pivote = "<< pivote << endl;
            //cout <<"i = "<<i<<", j = "<<j<<"\n";  
            //cout <<"Aux = "<< aux << endl;
            //cout << "S[pivote] = " <<s[pivote]<<endl;
            
            if(pivote == j){
                bucket[aux]++;
                j++;
                current++;
            } else { 
                bucket[aux]--;
                i++;
                current--;
            }
            
            if(isComplete(bucket)){
                res = min(res, current);
                pivote = i;
                
            } else {
                
                if(j < s.size()){
                    pivote = j;
                }
            }
            //cout << res << endl << endl;
        }
        
        if(res == 1e6)cout<<"0\n"; 
        else cout << res << endl;
        
    }
    
    return 0;
}
