#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int x, y, z;
  cin>>x>>y>>z;

  if(z == 0){
    if(x > y)cout<<"+\n";
    else if(y > x)cout<<"-\n";
    else cout<<"0\n";
  }else if(x > y){
    int aux = y + z;
    if(x > aux)cout<<"+\n";
    else cout<<"?\n";
  }else if(y > x){
    int aux = x + z;
    if(y > aux)cout<<"-\n";
    else cout<<"?\n";
  }else if(z != 0)cout<<"?\n";

  return 0;
}
