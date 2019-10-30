#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll T = 7e4;
vll criba(T+20, 1);
vll primos;

void sieve(){
 criba[0] = criba[1] = 0;
 for(ll i = 0; i <= T; i++){
  if(criba[i]){
   for(ll j = i*i; j <= T; j+=i){
    criba[j] = 0;
   }
   primos.push_back(i);
  }
 }
}


bool isPrime(ll N){
    
  //Los primos van hasta raiz de N
  ll raiz = sqrt(N);
  if(N == 1)return false; // El uno no es primo
  for(ll i = 0; i < primos.size() && primos[i] <= raiz; i++){
      if(N % primos[i] == 0)return false;
  }
   return true;
}


int main (){
 sieve();
 
 ll L, R;
 while(cin>>L>>R){

  pair<ll, ll>cerca;
  pair<ll, ll>lejos;
  cerca.first = 0;
  cerca.second = 0;
  lejos.first = 0;
  lejos.second = 0;
  ll distC = 0, distL = 0;
  ll maxDist = 0, minDist = 0;
  ll banC = 0, banL = 0;
  ll primeTemp = 0;

  for(ll i = L; i <= R; i++){
   if(banC == 1)distC++;
   if(banL == 1)distL++;
   
   //Simulacion del proceso
   if(isPrime(i)){

     if(cerca.first == 0){
      cerca.first = i;
      banC = 1;
     }else if(cerca.second == 0){
        cerca.second = i;
        minDist = distC;
        distC = 0;
      }else if(distC < minDist){
        cerca.first = primeTemp;
        cerca.second = i;
        minDist = distC;
        distC = 0;
       }else{
         //primeTemp = i;
         distC = 0;
        }
      
      if(lejos.first == 0){
        lejos.first = i;
        banL = 1;
      }else if(lejos.second == 0){
        lejos.second = i;
        maxDist = distL;
        distL = 0;
       }else if(distL > maxDist){
          lejos.first = primeTemp;
          lejos.second = i;
          maxDist = distL;
          distL = 0;
        }else{
          distL = 0;
         }
     primeTemp = i;
   }
  }
  if(cerca.second == 0)cout<<"There are no adjacent primes.\n";
  else{ //cout<<cerca.first<<" "<<cerca.second<<endl;
       cout<<cerca.first<<","<<cerca.second<<" are closest, ";
       cout<<lejos.first<<","<<lejos.second<<" are most distant.\n";
       //cout<<"2,3 are closest, 7,11 are most distant.";
  }
 }


 return 0;
}
