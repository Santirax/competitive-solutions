#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main (){

  lli a, b, c, d;
  cin>>a>>b>>c>>d;

  lli res = -1;
  for(lli i = 0; i <= 100; i++){
    for(lli j = 0; j <= 100; j++){
      if(b + i*a == d + j*c){
        //cout<<i<<" and "<<j<<"\n";
        cout<<b + i*a<<endl; return 0;
      }
    }
  }

  cout<<res<<"\n";


  return 0;
}
