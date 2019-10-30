#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
   string s;
   cin>>s;
   int isPal = 1;
   for(int i = 0, j = s.size()-1; i < s.size()/2; i++, j--){
     if(s[i] != s[j]){
      isPal = 0;
      break;
     }
   }
   
   if(isPal == 0){
    cout<<s<<"\n";
   }else{
    if(s.size() == 1)
     cout<<"-1\n";
      else{
        int change = 0;
        char l = s[0];
        for(int i = 1; i < s.size(); i++){
          if(s[i] != l){
            change = 1;
          }
        }
        if(change == 0){
          cout<<"-1\n";
        }else{
          sort(s.begin(), s.end());
          cout<<s<<"\n";
        }
      }
   }
   
  }//Fin del caso


  return 0;
}
