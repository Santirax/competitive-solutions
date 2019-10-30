#include <bits/stdc++.h>

using namespace std;

int main (){
  int n, m;
  cin>>n>>m;



  vector<vector<char>> tab(n, vector<char>(m, '-'));


  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>tab[i][j];
    }
  }

  char curr = 'W';
  for(int i = 0; i < n; i++){
    if(i % 2 == 0)curr = 'W'; else curr = 'B';
    for(int j = 0; j < m; j++){

      if(tab[i][j] == '.'){
        tab[i][j] = curr;

      }
      curr = curr == 'B' ? 'W' : 'B';
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<tab[i][j];
    }
    cout<<endl;
  }


  return 0;
}
