#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
  int n;
  cin>>n;
  vector<int>nums(n+1);
  for(int i = 0; i < n; i++){
    cin>>nums[i];
  }

  //Pasamos todos los numeros a su forma negativa ya que son mas grandes
  for(int i = 0; i < n; i++){
    if(nums[i] >= 0)nums[i] = (-1*nums[i]) - 1;
  }
  if((n&1)){ //Impar

    int min = 0;
    int idMin;
    for(int i = 0; i < n; i++){
      if(nums[i] <= min){
        min = nums[i];
        idMin = i;
      }
    }

    for(int i = 0; i < n; i++){
      if(i == idMin)cout<<(-1*nums[i]) - 1<<" ";
      else cout<<nums[i]<<" ";
    }

  }else{ //Par
    for(int i = 0; i < n; i++){
      cout<<nums[i]<<" ";
    }
  }

  cout<<"\n";

  return 0;
}
