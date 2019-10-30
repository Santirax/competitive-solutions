#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> criba(1e6+10, 1);

void sieve (){
    criba[0] = 0;
    criba[1] = 0;
    for(ll i = 0; i < 1e6+5; i++){
        if(criba[i]){
            for(ll j = i*i; j < 1e6+5; j+=i)
                criba[j] = 0;
        }
    }
}

int main (){
  int n;
  ll x;
  sieve();
  
  cin>>n;
  //Para que el numero sea un t_prime debe de contener solo tres divisores
  //Los unicos numeros que cumplen esta condicion son aquellos cuya raiz cuadrada sea un numero primo
  //Por ejemplo 4 cumple ya que su raiz es 2
  //El 16 no cumple ya que su raiz es 4 y 4 no es primo
  //La demostracion queda pendiente xD

  for(int i = 0; i < n; i++){
    cin>>x;
    
    ld res = sqrt(x);
    if((res - (ll)res) == 0 && res != 1){ //Puede ser un t prime
        if(criba[(ll)res] == 1){ //Es un t_prime
            cout<<"YES\n";
        }else{ //No es un t_prime
            cout<<"NO\n";
        }
    }else {
        cout<<"NO\n";
    }
    
  }

  return 0;
}
