#include <bits/stdc++.h>
using namespace std;

int main (){
    
    int t; cin>>t;
    while(t--){
        vector<int> pares;
        vector<int> impares;
        string s;
        cin>>s;
        for(char c: s){
            int digito = c-'0';
            if(digito % 2 == 0)pares.push_back(digito);
            else impares.push_back(digito);
        }
        
        int i = 0, j = 0;
        vector<int> res;
        while(1){
            
            if(i == pares.size()){
                //Vamos a ver si tiene algo impares
                for(;j<impares.size(); j++){
                    res.push_back(impares[j]);
                }
                break;
            }
            
            if(j == impares.size()){
                //Vamos a ver si tiene algo pares
                for(;i<pares.size(); i++){
                    res.push_back(pares[i]);
                }
                break;
            }
            
            //Checamos quien es el menor
            if(pares[i] > impares[j]){
                
                res.push_back(impares[j]);
                j++;
                
            }else{
                res.push_back(pares[i]);
                i++;
            }
            
        }
        for(int x: res)cout<<x;
        cout<<endl;
        
    }
    
}
