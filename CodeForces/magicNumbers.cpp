#include <bits/stdc++.h>
using namespace std;
int main (){
  string num;
  cin>>num;
  int ban = 1;
  for(int i = 0; i < num.size(); i++){
    if(num[i] != '1' && num[i] != '4'){
      ban = 0;
      break;
    }
  }
  
 if(ban == 0){
   cout<<"NO\n";
 }else{
   if(num[0] != '1'){
     cout<<"NO\n";
   }else{
    ban = 1;
    for(int i = 0; i < num.size();){
      if(num[i] == '1' && num[i+1] == '4' && num[i+2] == '4'){
        i+=3;
      }else if(num[i] == '1' && num[i+1] == '4'){
       i+=2;
      }else if(num[i] == '1'){
       i++;
      }else{
        ban = 0;
        break;
      }
    }
    if(ban == 0)cout<<"NO\n"; else cout<<"YES\n";
   }
 }
 
   return 0;
}
