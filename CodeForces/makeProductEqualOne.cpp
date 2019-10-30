#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;
  int contPos = 0;
  int contNeg = 0;
  int contZero = 0;
  vector<int>a(n);
  for(int i = 0; i < n; i++){
    cin>>a[i];
    if(a[i] > 0)contPos++;
    else if(a[i] < 0) contNeg++;
    else contZero++;
  }
  //sort(a.begin(), a.end());

  long long res = 0;

  for(int i = 0; i < n; i++){
    if(a[i] == 0)res+=1;
    else res += abs(a[i])-1;
  }

  if(contNeg % 2 != 0){
    if(contZero == 0)
      res += 2;
  }

  cout<<res<<"\n";

  return 0;
}
