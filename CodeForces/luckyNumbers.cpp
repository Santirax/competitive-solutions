#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binaryExponentation(ll x, ll n) {
  if (n == 0) return 1;
  if (n == 1) return x;

  if (n % 2 == 0) return binaryExponentation(x * x, n / 2);
  return x * binaryExponentation(x * x, (n - 1) / 2);
}

int main (){

  int N; cin>>N;
  ll res = 0;
  for(int i = 1; i <= N; i++){
    res += binaryExponentation(2, i);
  }

  cout<<res<<"\n";

  return 0;
}
