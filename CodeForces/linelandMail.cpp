#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main (){
  int n;
  cin>>n;
  vector<ll>num(2e5 +1);

  for(int i = 0; i < n; i++){
    cin>>num[i];
  }

  ll l = num[0];
  ll d = num[n-1];

  vector<pair<int, int>>res(2e5+1);
  for(int i = 0; i < n; i++){
    if(i == 0){
      res[i].first = abs(num[i] - num[i+1]);
      res[i].second = abs(num[i] - d);
    }else if(i == n-1){
      res[i].first = abs(num[i] - num[i-1]);
      res[i].second = abs(num[i] - l);
    }else{
      ll min1 = abs(num[i] - num[i-1]);
      ll min2 = abs(num[i] - num[i+1]);
      res[i].first = min(min1, min2);

      ll max1 = abs(num[i] - l);
      ll max2 = abs(num[i] - d);
      res[i].second = max(max1, max2);

    }
  }
  for(int i = 0; i < n; i++){
    cout<<res[i].first <<" "<<res[i].second<<"\n";
  }


  return 0;
}
