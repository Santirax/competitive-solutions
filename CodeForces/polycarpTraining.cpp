#include <bits/stdc++.h>
using namespace std;
int main (){

  int days = 1;
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin>>v[i];
  }

  sort(v.begin(), v.end());


  for(int i = 0; i < n; i++){
    if(v[i] >= days){
      days++;
    }
  }

  cout<<days-1<<"\n";



  return 0;
}
