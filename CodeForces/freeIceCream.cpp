#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main (){
    int n; ll x;
    cin>>n>>x;
    
    char sign; 
    
    ll currentIce = x;
    ll d;
    
    ll distress = 0;
    
    for(int i = 0; i < n; i++){
        cin>>sign>>d;
        if(sign == '-'){
            
            if(d <= currentIce){
                currentIce -= d;
            } else {
                distress++;
            }
            
        }else{
            currentIce += d;
        }
    }
    
    cout << currentIce << " " << distress << "\n";
    
    
    
    
    return 0;
}
