#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
  ll n, k;
  ll ti, fi;
  ll res = -1e10;
  cin>>n>>k;
  for(int i = 0; i < n; i++){
    cin>>fi>>ti;
    if(ti <= k){
      res = max(res, fi);
    }else{
      res = max(res, fi-(ti-k)); 
    }
  }
  cout<<res<<"\n";

  return 0;
}
