#include <bits/stdc++.h>
using namespace std;
int main (){

  int n, s;
  cin>>n>>s;

  vector<int>inc(n);
  vector<int>dec(n);

  for(int i = 0; i < n; i++)cin>>inc[i];
  for(int i = 0; i < n; i++)cin>>dec[i];

  if(inc[s-1] == 0 && dec[s-1] == 0){
    cout<<"NO\n";
  }else if(inc[0] == 0){
    cout<<"NO\n";
  }else if(inc[s-1] == 1) {
    cout<<"YES\n";
  }else {
    if(inc[s-1] == 0 && dec[s-1] == 1){

      int ban = 0;
      for(int i = s-1; i < n; i++){
        if(inc[i] == 1 && dec[i] == 1){
          cout<<"YES\n";
          ban = 1;
          break;
        }
      }

      if(ban == 0)cout<<"NO\n";

    }
  }




  return 0;
}
