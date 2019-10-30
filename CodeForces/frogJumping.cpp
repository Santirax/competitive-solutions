#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
  int T;
  cin>>T;
  while(T--){
   ll a, b, k;
   cin>>a>>b>>k;
   ll res = 0;
   ll multA, multB;
   if(k%2 == 0){
     multA = k/2;
     multB = k/2;
   }else{
    multB = k/2;
    multA = k-multB;
   }
   res = multA*a - multB*b;
   cout<<res<<"\n";
  }

 return 0;
}
