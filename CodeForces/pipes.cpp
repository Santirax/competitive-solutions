#include <bits/stdc++.h>
using namespace std;
int main (){

  int t;
  cin>>t;
  while(t--){
    int n;
    vector<string> pipe(2);
    cin>>n;
    cin>>pipe[0];
    cin>>pipe[1];

    bool estaAbajo = false;
    bool puede = true;
    for(int i = 0; i < n; i++){
      if((pipe[0][i]-'0') >= 3 && (pipe[1][i]-'0') >= 3){
        estaAbajo = (estaAbajo == false ? true : false);
      }else if(estaAbajo == true && (pipe[1][i]-'0') >= 3 && (pipe[0][i]-'0') <= 2){
        puede = false; break;
      }else if(estaAbajo == false && (pipe[0][i]-'0') >= 3 && (pipe[1][i]-'0') <= 2){
        puede = false; break;
      }

    }

    if(puede == false || estaAbajo == false){
      cout<<"NO\n";
    }else{
      cout<<"YES\n";
    }

  }



}
