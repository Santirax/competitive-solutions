#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main (){

  int T;
  ll a, b, c;
  cin>>T;
  while(T--){
    cin>>a>>b>>c;
    ll sum = a+b+c;
    
    cout<<fixed<<setprecision(0)<<(sum/2)<<"\n";

  }

  return 0;
}
