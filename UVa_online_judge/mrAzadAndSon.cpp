#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isPrime(lli N){
  long double raiz = sqrt(N);
  for(int i = 2; i <= raiz; i++){
    if(N % i == 0)return false;
  }

  return true;

}

int main (){
  lli N;
  while(cin>>N && N != 0){
    int i = 0;
    if(isPrime(N) == false)
      cout<<"Given number is NOT prime! NO perfect number is available.\n";
        else{
           lli perfect = (pow(2, N)-1);
           if(isPrime(perfect)){
             perfect = pow(2, (N-1))*(pow(2, N)-1);
             cout<<"Perfect: "<<perfect<<"!\n";
           }else{
            cout<<"Given number is prime. But, NO perfect number is available.\n";
           }
        }

  }


  return 0;
}
