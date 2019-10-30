#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n){
  for(ll i = 2; i <= sqrt(n); i++)
   if(n % i == 0)return false;

  return true;
}
// El problema se resuelve utilizando la conjetura de Goldbach
// Puedes descomponer el n original en 1 (n es primo), 2 (n%2== 0 | n-2 es primo) o 3 (suma de tres primos)
int main (){
 ll n;
 cin>>n;
 if(isPrime(n)){
   cout<<1<<endl;
 }else if(n%2 == 0){
   cout<<2<<endl;
 }else if(isPrime(n-2)){
   cout<<2<<endl;
 }else{
   cout<<3<<endl;
 }
 return 0;
}
