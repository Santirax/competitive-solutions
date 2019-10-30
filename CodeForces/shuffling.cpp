#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;

/*int main (){
  ll n, m;
  cin>>n>>m;
  ll num = pow(2, n);
  vector<ll>nums(num);
  for(int i = 0; i < num; i++){
    cin>>nums[i];
  }

  if(m % 2 == 1){
    reverse(nums.begin(), nums.end());
    for(int i = 0; i < num; i++){
      cout<<nums[i]<<" ";
    }
  }else{
    for(int i = 0; i < num; i++){
      cout<<nums[i]<<" ";
    }
  }
  cout<<"\n";


  return 0;
}*/

int main (){
  int n, m;
  cin>>n>>m;
  int num = pow(2, n);
  vector<int>nums(num);
  for(int i = 0; i < num; i++){
    cin>>nums[i];
  }

  if(m % 2 == 1){
    reverse(nums.begin(), nums.end());
  }
  
  for(int i = 0; i < num; i++){
    cout<<nums[i]<<" ";
  }
  cout<<"\n";


  return 0;
}
