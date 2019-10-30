#include<bits/stdc++.h>
using namespace std;
int main (){
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vector<int>sides(4*n);
    for(int i = 0; i < 4*n; i++){
      cin>>sides[i];
    }

    map<int, int> cub;
    for(int i = 0; i < 4*n; i++){
      //cout<<sides[i]<<" ";
      cub[sides[i]]++;
    }

    bool ban = true;
    for(auto x: cub){
      //cout<<x.first<<" y "<<x.second<<"\n";
      if(x.second % 2 != 0){
        ban = false; break;
      }
    }

    if(ban == false){
      //cout<<"Aqui\n";
      cout<<"NO\n";
    }else{
      //cout<<endl;
      sort(sides.begin(), sides.end());
      //for(int x: sides)cout<<x<<" ";
      //cout<<endl;
      int u = sides[0] * sides[sides.size()-1];
      for(int i = 1, j = sides.size()-2; i < 4*n; i++, j--){
        int v = sides[i] * sides[j];
        if(u != v){
          ban = false;
          break;
        }else{
          u = v;
        }
      }
      if(ban)cout<<"YES\n"; else cout<<"NO\n";
    }
  }

  return 0;
}
