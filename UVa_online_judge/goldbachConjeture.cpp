#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int lli;

int main (){

  lli size = 1e6+1;
  vector<lli>criba(1e6+1, 1);
  vector<lli>primos;
  criba[0] = criba[1] = 0;
  for(lli i = 2; i <= size; i++){
    //criba[i] = 2;
    if(criba[i] == 1){
      for(lli j = i*i; j <= size; j+=i){
        criba[j] = j;
      }
      primos.push_back((int)i);
    }
  }

  int k;
  while(cin>>k && k != 0){

    if(criba[k] == 1){
      cout<<"Goldbach's conjecture is wrong.\n";
    }else {
      int i, p, ban = 0, res = 0;
      for(i = 1; i < primos.size(); i++){
        p = k - primos[i];
        if(criba[p] == 1){
          ban = 1; break;
        }
      }
      if(ban == 1){
        cout<<k<<" = "<<primos[i]<<" + "<<p<<"\n";
      }else
       cout<<"Goldbach's conjecture is wrong.\n";
    }

  }


  return 0;
}
