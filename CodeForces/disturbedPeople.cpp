#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;
  vector<int>v(n);

  int aux = 0;
  for(int i = 0; i < n; i++){
    cin>>v[i];
    aux+=v[i];
  }

  if(aux == 0 || aux == n)
    cout<<"0\n";
  else{
    int cont = 0;
    for(int i = 1; i < n-1; i++){
      if(v[i-1] == 1 && v[i+1] == 1 && v[i] == 0){
        cont++;
        v[i+1] = 0;
      }
    }
    cout<<cont<<"\n";
  }


  return 0;
}
