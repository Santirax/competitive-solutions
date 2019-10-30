#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;

  int m = n/2 + 1;

  cout<<m<<"\n";
  for(int i = 1; i <= m; i++){
    cout<<"1 "<<i<<"\n";
  }

  for(int i = 2; i <= n-m+1; i++){
    cout<<m<<" "<<i<<"\n";
  }

  return 0;
}
