#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int lli;

int main (){

  lli size = 3e6;
  vector<lli>criba(3e6, 1);
  vector<lli>primos;
  criba[0] = criba[1] = 0;
  for(lli i = 2; i < size; i++){
    //criba[i] = 2;
    if(criba[i]){
      for(lli j = i*i; j < size; j+=i){
        criba[j] = j;
      }
      primos.push_back(i);
    }
  }

  lli k;
  while(cin>>k && k != 0){

    if(criba[k] == 1){
      cout<<0<<"\n";
      //break;
    }else {
      int cont = 0;
      for (lli i = 0; ; i++) {
        //cout<<criba[i]<<" ";
        //cout<<primos[i]<<" ";
        if(criba[i] == 1){
          if(i > k){cont++; break;}
          else cont = 0;
        }else
           cont++;
      }
      //cout<<endl;
      cout<<cont<<endl;
    }

  }

  return 0;
}
