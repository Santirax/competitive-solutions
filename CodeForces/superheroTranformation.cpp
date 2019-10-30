#include <bits/stdc++.h>
using namespace std;
int main (){
 map<char, int>voc;
 voc['a'] = 1;
 voc['e'] = 1;
 voc['i'] = 1;
 voc['o'] = 1;
 voc['u'] = 1;
 string s1;
 string s2;
 cin>>s1>>s2;
 if(s1.size() != s2.size())
  cout<<"No\n";
   else{ 
       int ban = 1;
    for(int i = 0; i < s1.size(); i++){
        if(voc[s1[i]] != voc[s2[i]]){
            ban = 0;
            break;
        }
    }
    
     if(ban)cout<<"Yes\n"; else cout<<"No\n";
   }
   

  return 0;
}
