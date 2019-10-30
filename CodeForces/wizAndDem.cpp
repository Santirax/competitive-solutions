#include <bits/stdc++.h>
using namespace std;
int main (){
  int n, x, y;
  cin>>n>>x>>y;
  double porcent = ceil( n*((double)y/100) );
  if (porcent-x < 0)
      cout<<"0\n";
        else
         cout<<porcent-x<<"\n";
  
  return 0;
}
