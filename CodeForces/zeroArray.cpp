#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;
  //map<int, int>mapa;
  int x;
  long long sum = 0;
  int maxi = -1;
  for(int i = 0; i < n; i++){
    cin>>x;
    maxi = max(maxi, x);
    sum += x;
    //mapa[x]++;
  }

  if(sum % 2 == 0 && (sum-maxi) >= maxi){
    cout<<"YES\n";
  }else{
    cout<<"NO\n";
  }



  return 0;
}
