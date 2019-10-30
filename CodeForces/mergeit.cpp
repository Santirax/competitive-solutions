#include <bits/stdc++.h>
using namespace std;
int main (){

  long long t = 0;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;

    long long x, cont1 = 0LL, cont2 = 0LL, cont = 0LL;
    for(int i = 0; i < n; i++){
      cin>>x;
      if(x % 3 == 1){
        cont1++;
      }else if (x % 3 == 2){
        cont2++;
      }else{
        cont++;
      }
    }

    if(cont1 == 0){

      cout<<cont + floor(cont2/3)<<endl;

    }else if(cont2 == 0){

      cout<<cont + floor(cont1/3)<<endl;

    }else{

      long long res = 0;

      if(cont1 == cont2){
        res = cont1;

      }else if(cont1 > cont2){
        long long dif = cont1 - cont2;

        res = cont1 - dif;
        res += floor(dif / 3);

      }else{
        long long dif = cont2 - cont1;

        res = cont2 - dif;
        res += floor(dif / 3);

      }

      long long sol = cont + res;
      cout<<sol<<endl;

    }

  }

  return 0;

}
