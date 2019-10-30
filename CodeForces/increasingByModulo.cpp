#include <bits/stdc++.h>
using namespace std;

vector<int>num;
int n, m;

/*inline bool esValido (int m){
  int aux = num[0];
  for(int i = 1; i < n; i++){
    if(num[i] < aux){

    }
  }
}*/

inline bool esValido(int x){
    int lst = num[0];
    if(m - lst <= x)
        lst = 0;
    for(int i = 1 ; i < n ; ++i){
        if(x >= m - num[i] + lst)
            continue;
        if(num[i] <= lst && lst - num[i] <= x)
            continue;
        if(num[i] > lst){
            lst = num[i];
            continue;
        }
        return false;
    }
    return true;
}


inline int busqueda(){
  int ini = 0, fin = m-1, mid;
  int res = 0;
  while(ini <= fin){
    mid = (ini + fin)/2;
    if(esValido(mid)){
      fin = mid - 1;
      res = mid;
    }else {
      ini = mid + 1;
    }
  }

  return res;
}

int main (){

  //int n, m;
  cin>>n>>m;
  int x;
  for(int i = 0; i < n; i++){
    cin>>x;
    num.push_back(x);
  }

  cout<<busqueda();

  return 0;
}
