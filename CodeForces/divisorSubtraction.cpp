#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll loPrimes(ll n){

  for(ll i = 2; i <= sqrt(n); i++)
    if(n % i == 0)return i;

  return n;
}

int main (){

  ll n;
  cin>>n;

  ll cont = 0;
  while(n != 0){
    ll p = loPrimes(n);
    if(p == 2){
      cont += (n/2);
      break;
    }else{
      n -= p;
      cont++;
    }
  }

  cout<<cont<<endl;

  return 0;
}
