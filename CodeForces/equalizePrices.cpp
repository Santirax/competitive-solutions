#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main (){
 int T, n, k; ll x;
 cin>>T;
 while(T--){
   ll mini = 1e9, maxi = -1;
   cin>>n>>k;
   for(int i = 0; i < n; i++){
      cin>>x;
      maxi = max(x, maxi);
      mini = min(x, mini);
   }
   if((mini + k) >= (maxi-k))cout<<mini+k<<"\n";
   else cout<<"-1\n";
 }
 return 0;
}
