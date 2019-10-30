#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;

  if(n & 1){ //Impar
    vector<int>res(2*n);

    res[0] = 1;
    res[n] = 2;

    int idx = 1;
    int ban = 1; //0 -> se incrementa 1, -1 -> se decrementa n
    //1 -> se incrementa n
    for(int i = 2*n; i >= 3; i--){
      //cout<<idx<<"\n";
      res[idx] = i;

      if(i % 2 == 0){
        if(ban == 1){
          idx += n;
          ban = 0;
        }else{
          idx -= n;
          ban = 1;
        }
        //El siguinete es decremento o aumento en n unidades
      }else{
        //El siguinete es incremento en 1
        idx++;
      }

    }

    cout<<"YES\n";
    for(int x: res){
      cout<<x<<" ";
    }

    cout<<endl;

  }else{ //Par
    cout<<"NO\n";
  }

  return 0;
}
