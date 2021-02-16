#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n; cin>>n;
    map<string, int> names;
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        if(names.count(s)){
            cout<<s<<to_string(names[s])<<endl;
            names[s]++;
        } else {
            cout << "OK\n";
            names[s]++;
        }
    }
    
    
    return 0;
}
