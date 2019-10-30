#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
vector<vector<int>> la;
vector<bool> vis;
vector<int> teams;

int cont = 0;

inline void dfs(int ini){
  vis[ini] = true;

  for(int i = 0; i < la[ini].size(); i++){
    int u = la[ini][i];
    if(!vis[u]){
      cont++;
      teams.push_back(u);
      dfs(u);
    }
  }
  //urchildrenfly2002
}

int main (){

  int N, k;
  cin>>N>>k;
  la.resize(N+1);
  vis.resize(N+1, false);
  //trip.resize(N/3);
  int u, v;
  for(int i = 0; i < k; i++){
    cin>>u>>v;
    la[u].push_back(v);
    la[v].push_back(u);
  }

  vector<int>sol;

  int comp = 0;

  int idx = 0;

  int ban = 1;
  int cont2 = 0; int cont1 = 0;

  vector<int> dosA;
  vector<int> unA;

  for(int i = 1; i <= N; i++){
    if(!vis[i]){
      comp++; cont = 1;
      teams.push_back(i);
      dfs(i);

      if(cont == 3){
        for(int i = 0; i < 3; i++)sol.push_back(teams[i]);
        teams.clear();
      }else if(cont == 2){
        cont2++;
        for(int i = 0; i < 2; i++)dosA.push_back(teams[i]);
        teams.clear();
      }else if(cont == 1){
        cont1++;
        unA.push_back(teams[0]);
        //cout<<teams[0]<<"\n";
        teams.clear();
      }else
      if(cont > 3){ban = 0; break;}

    }
  }

  /*for(int x: sol)cout<<x<<" ";
  cout<<endl;
  for(int x: dosA)cout<<x<<" ";
  cout<<endl;
  for(int x: unA)cout<<x<<" ";*/

  //cout<<cont2<<" y "<<cont1<<"\n";

  if(ban){

    //cout<<"Entra\n";
    //cout<<cont1<<"  "<<cont2<<endl;
    int mod1 = cont1 % 3;
    int mod2 = cont2 % 3;

    bool sePuede = false;
    if(cont1 > cont2){
      if(((cont1 - cont2) % 3) == 0)sePuede = true;
    }

    if(cont1 == cont2){

      int idx = 0;
      int cont = 1;
      for(int i = 0; i < dosA.size(); i++){
        if(cont == 3){sol.push_back(unA[idx]); idx++; cont = 1;}
        sol.push_back(dosA[i]);
        cont++;
      }
      if(cont1 != 0)
      sol.push_back(unA[idx]);


      for(int i = 0; i < N; i+=3){
        cout<<sol[i]<<" "<<sol[i+1]<<" "<<sol[i+2]<<"\n";
      }

    }else if(sePuede){

      int idx = 0;
      for(int i = 0; i < dosA.size(); i++){
        sol.push_back(dosA[i]);
        if(i % 3 == 0){sol.push_back(unA[idx]); idx++;}
      }

      for(int i = idx; i < unA.size(); i++){
        sol.push_back(unA[i]);
      }


      for(int i = 0; i < N; i+=3){
        cout<<sol[i]<<" "<<sol[i+1]<<" "<<sol[i+2]<<"\n";
      }

    }else{
      cout<<"-1\n";
    }

  }else{
    cout<<-1<<endl;
  }

  return 0;
}
