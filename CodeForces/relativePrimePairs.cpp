#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){

  cin.tie(0), cout.tie(0);
  ll l, r;
  cin>>l>>r;
  ll pares = (r-l+1)/2;

  cout<<"YES\n";
  for(ll i = l; i <= r; i+=2){
    cout<<i<<" "<<i+1<<endl;
  }


  return 0;
}
