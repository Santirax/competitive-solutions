#include<bits/stdc++.h>
using namespace std;
int main (){
  int n, m;
  vector<int> c (100001, 0);
  cin>>n;
  vector<int>a(n);
  for(int i = 0; i < n; i++){
    cin>>a[i];
    c[a[i]] = 1;
  }
  cin>>m;
  vector<int>b(m);
  for(int i = 0; i < m; i++){
    cin>>b[i];
    c[b[i]] = 1;
  }

  int ban = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      long sum = a[i] + b[j];
      if(c[sum] == 0){
        cout<<a[i]<<" "<<b[j]<<endl;
        ban = 1;
        break;
      }
    }
    if(ban == 1)break;
  }

  return 0;
}
