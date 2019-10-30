#include <bits/stdc++.h>
using namespace std;
int main (){
  int q, n;
  string s;
  cin>>q;
  while(q--){
    cin>>n;
    cin>>s;
    if(n == 2){
      int a = s[0];
      int b = s[1];
      if(a < b){
        cout<<"YES\n";
        cout<<"2\n";
        cout<<s[0]<<" "<<s[1]<<"\n";
      }else{
        cout<<"NO\n";
      }
    }else{
      cout<<"YES\n";
      cout<<"2\n";
      cout<<s[0]<<" ";
      for(int i = 1; i < s.size(); i++){
        cout<<s[i];
      }
      cout<<"\n";
    }

    /*int x = (s[0]-'0');
    int ban = 1;
    vector<int>res;
    res.push_back(x);

    string aux; aux.push_back(s[1]);

    for(int i = 1; i < n; i++){
      //aux = s[i];
      if(x < stoi(aux)){
        x = stoi(aux);
        res.push_back(x);
        aux = s[i+1];
      }else{
        if(i+1 >= n){ban = 0;}
        aux += s[i+1];
      }
    }

    if(ban == 0)cout<<"NO\n";
    else{
      cout<<"YES\n";
      cout<<res.size()<<"\n";
      for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    }*/
  }

  return 0;
}
