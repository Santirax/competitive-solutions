#include <bits/stdc++.h>
using namespace std;

int main (){
    
    int n;
    cin>>n;
    while(n--){
        string s1, s2;
        cin>>s1>>s2;
        
        if(s1.size() != s2.size()){
            cout<<"No\n";
        }else{
            for(int i = 0; i < s1.size(); i++){
                s1[i] = tolower(s1[i]);
                s2[i] = tolower(s2[i]);
                
                if(s1[i] == 'b' || s1[i] == 'p' || s1[i] == 'B' || s1[i] == 'P')s1[i] = 'b';
                if(s2[i] == 'b' || s2[i] == 'p' || s2[i] == 'B' || s2[i] == 'P')s2[i] = 'b';
                if(s1[i] == 'i' || s1[i] == 'e' || s1[i] == 'I' || s1[i] == 'E')s1[i] = 'i';
                if(s2[i] == 'i' || s2[i] == 'e' || s2[i] == 'I' || s2[i] == 'E')s2[i] = 'i';
                
            }
            
            //cout << s1 << " - " << s2 << endl;
            if(s1 == s2)cout<<"Yes\n"; else cout <<"No\n";
        }
    
    }
    
    
    return 0;
}
