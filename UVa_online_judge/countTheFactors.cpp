#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;
int main (){

  /*Criba tuneada para tener en las posiciones el numero primo del que
  es multiplo*/
  lli size = 1e6+1;
  vector<lli>criba(1e6+1, 1);
  vector<lli>primos;
  criba[0] = criba[1] = 0;
  for(lli i = 2; i <= size; i++){
    //criba[i] = 2;
    if(criba[i] == 1){
      criba[i] = i;
      for(lli j = i*i; j <= size; j+=i){
        criba[j] = i;
      }
      primos.push_back((int)i);
    }
  }


  int k, n;
  while (cin>>k && k != 0){
    set<int> prime;
    n = k;
    /*Factorizacion en corto de un numero*/
    while(k > 1){
      prime.insert(criba[k]);
      k = k/criba[k];
    }
    cout<<n<<" : "<<prime.size()<<"\n";

  }

  //criba[]


  return 0;
}
