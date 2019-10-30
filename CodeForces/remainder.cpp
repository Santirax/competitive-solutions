#include <bits/stdc++.h>
using namespace std;
int main() {


  cin.tie(0);
  int n, x, y;
  string s;
  cin>>n>>x>>y;
  cin>>s;

  int cont = 0;

  int id = (n-1)-y;

  //if(s[(n-1)-x] == '0')cont++;

  for(int i = (n-x); i < n; i++){

    //cout<<i<<" "<<s[i]<<"\n";

    if(s[i] == '1' && i != id){
      cont++;
    }else if(i == id && s[i] == '0'){
      cont++;
    }
  }

  cout<<cont<<"\n";


  return 0;
}
