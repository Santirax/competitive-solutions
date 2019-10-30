#include <bits/stdc++.h>
using namespace std;

bool isPrime(int N){
  for(int i = 2; i <= sqrt(N); i++){
    if(N % i == 0)return true;
  }
  return false;
}


int main (){

  int n;
  cin>>n;

  for(int i = n-3; i >= 0; i--){
    if(isPrime(n-i) && isPrime(i)){
      cout<<n-i<<" "<<i<<endl;
      break;
    }
  }


  return 0;
}
