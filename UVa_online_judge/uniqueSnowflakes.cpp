#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<ll> unique(n);
    map<int, int> mapa;
    ll x;
    for(int i = 0; i < n; i++){
      cin>>unique[i];
    }


    ll cont = 0, maxcont = -1;
    int idx = 0, temp = 0;
    for(int i = 0; i < n; i++){

      if(!mapa[unique[i]]){
        if(i == 0)
          mapa[unique[i]] = -1;
        else
          mapa[unique[i]] = i;

        cont++;
        //cout<<unique[i]<<" -> "<<mapa[unique[i]]<<"\n";

      }else{

        if(mapa[unique[i]] == -1) mapa[unique[i]] = 0;
        //cout<<"Num rep = " << mapa[unique[i]]<<"\n";
        //cout<<"Cont = "<<cont<<"\n";
        maxcont = max(maxcont,cont); //Maximo
        cont = i-mapa[unique[i]]; //Contador por rango, dice cuantos numeros van por el rango
        temp = mapa[unique[i]]+1; //Una variable temporal para no perder el indice
        for(int j = idx; j <= mapa[unique[i]]; j++){
          mapa.erase(unique[j]);
        } //Borramos el rango que no nos sirve
        mapa[unique[i]] = i; //Actualizamos el valor
        idx = temp; //Y tambien el indice en el cual nos quedamos que
        //guaradamos en temp porque lo ibamos a eliminar del mapa
      }
    }
    cout << max(cont, maxcont) << "\n"; //Al final la respuesta es
    //solo del contador con el mayor numero
  }

  return 0;
}
