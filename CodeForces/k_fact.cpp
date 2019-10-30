#include <bits/stdc++.h>
using namespace std;
int main (){

  int N, k;
  cin>>N>>k;
  vector<int>primes;
  for(int i = 2; i <= sqrt(N); i++){
    if(N % i == 0){
      while(N % i == 0){
        N/=i;
        primes.push_back(i);
      }
    }
  }
  if(N > 1)primes.push_back(N);

  /*for(int x: primes){
    cout<<x<<" ";
  }*/

  if(primes.size() < k){
    cout<<-1<<endl;
  }else{
    for(int i = 0; i < k-1; i++){
      cout<<primes[i]<<" ";
    }
    int last = 1;
    for(int i = k-1; i < primes.size(); i++){
      last *= primes[i];
    }
    cout<<last<<endl;

  }


  return 0;
}
