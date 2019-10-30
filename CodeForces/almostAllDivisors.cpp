#include <bits/stdc++.h>
using namespace std;

inline bool isPrime(long long n){
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0) return false;
  }
  return true;
}

inline int contDiv(long long n){
  int res = 1;
  for(int i = 2; i <= sqrt(n); i++){
    int cont = 0;
    while(n % i == 0){
      n/=i;
      cont++;
    }
    res *= (cont+1);
  }
  if(n > 1){
    res *= 2;
  }
  return res;
}

int main (){

  int T;
  cin>>T;
  while(T--){ //Casos de prueba
    int n;
    cin>>n;
    vector<long long> v(n); //Vector donde van los divisores menos 1 y n

    for(int i = 0; i < n; i++){ //Leemos los divisores
      cin>>v[i];
    }

    sort(v.begin(), v.end()); //Los ordenamos

    long long aux = v[0]*v[n-1];
    long long res;

    int ban = 1;

    if(n == 1){ //SI es solo un elemento hay que checar si es primo

      if(isPrime(v[0])){
        res = v[0]*v[0];
      }else
        ban = 0;


    }else if (n == 2){

      res = v[0]*v[1];
      if((contDiv(res)-2) != 2){
        ban = 0;
      }

    }else if(n & 1){ // Impar

      for(int i = 1, j = n-2; i < n/2-1; i++, j--){
        res = v[i] * v[j];
        if(res == aux){
          aux = res;
        }else{
          ban = 0;
          break;
        }
      }

      res = v[(n/2)]*v[(n/2)];
      if(res != aux){
        ban = 0;
      }

    }else { //Par
      for(int i = 1, j = n-2; i < (n/2); i++, j--){
        res = v[i] * v[j];
        if(res == aux){
          aux = res;
        }else{
          ban = 0;
          break;
        }
      }
    }

    if(contDiv(res)-2 != v.size() || ban == 0)
      cout<<"-1\n";
    else cout<<res<<"\n";

  }





  return 0;
}
