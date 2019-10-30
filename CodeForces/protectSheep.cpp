#include <bits/stdc++.h>
using namespace std;

char m[510][510];

int main (){
  int M, N;
  cin>>M>>N;



  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= N; j++){
      cin>>m[i][j];
    }
  }
  int ban = 1;
  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= N; j++){
      if(m[i][j] == 'S'){
        if(m[i-1][j] == 'W' || m[i+1][j] == 'W' || m[i][j-1] == 'W' || m[i][j+1] == 'W')
         ban = 0;
      }
    }
  }

  if(ban == 0)cout<<"No\n";
  else{
    for(int i = 1; i <= M; i++){
      for(int j = 1; j <= N; j++){
        if(m[i][j] == '.')m[i][j] = 'D';
      }
    }
    cout<<"Yes\n";
    for(int i = 1; i <= M; i++){
      for(int j = 1; j <= N; j++){
        cout<<m[i][j];
      }
      cout<<"\n";
    }
  }



  return 0;
}
