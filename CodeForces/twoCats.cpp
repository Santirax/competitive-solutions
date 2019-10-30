#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//vector<ll>k;

ll b;

vector< vector<ll> > DP (5000, vector<ll>(5000, -1));

vector<ll>potPrime;

//ll res = 0;

ll contDiv(int i, ll numDiv){
    
  //cout<<i<<" "<<numDiv<<endl;
  //cout<<"Res = "<<endl;
  //cout<<b<<endl;
  if(numDiv == b)return 1;
  
  if(i >= potPrime.size())return 0;
  
  if(numDiv > b)return 0;
  
  if(DP[i][numDiv] != -1)return DP[i][numDiv];
  
  ll res = 0;
  for(int j = 0; j <= potPrime[i]; j++){
      res = (res + contDiv(i+1, numDiv*(j+1)))%1000000007;
      //cout<<res<<endl;
  }
  return DP[i][numDiv] = res;
  //return DP[i][j] = (contDiv(i+1, j) + contDiv(i+1, j*k[i]));
}


vector<ll>criba(2e6+10, 1);
vector<ll>primos;

void sieve(){
    
    criba[0] = 0;
    criba[1] = 0;
    
    for(ll i = 2; i <= 1e6+100; i++){
        if(criba[i]){
          for(ll j = i*i; j <= 1e6+100; j+=i)
              criba[j] = 0;
          
          primos.push_back(i);
        }
    }
}

int main (){
  ll n;
  cin>>b>>n;
  ll v;
  
  sieve();
  map<ll, int>potPrimeAux;
  /*for(int i = 0; i < 15; i++)
      cout<<primos[i]<<endl;*/
  
  //cout<<primos.size()<<endl;
  
  //cout<<primos[primos.size()-1]<<endl;
  for(int i = 0; i < n; i++){
     cin>>v;
     for(int i = 0; i < primos.size(); i++){
         if(v % primos[i] == 0){
             while(v % primos[i] == 0){
                 potPrimeAux[primos[i]]++;
                 v/=primos[i];
            }
        }
        if(v == 1)break;
    }
     /*ll div = 1;
     for(ll i = 2; i <= sqrt(v); i++){
       if(v % i == 0){
          while(v % i == 0){
              potPrimeAux[i]++;
              v/=i;
          }
       }
       div = 0;
     }*/
     
     if(v > 1){
         potPrimeAux[v]++;
     }
  }
  //cout<<a<<endl;
  
  
  /*for(auto x: potPrimeAux)
      cout<<x.first<<" -> "<<x.second<<endl;*/
  
  for(auto x: potPrimeAux)
      potPrime.push_back(x.second);
  
  
  /*for(ll x: potPrime)
      cout<<x<<" ";*/
  
  //cout<<endl<<endl;

  cout<<contDiv(0, 1)<<endl;
  
  return 0;
}
