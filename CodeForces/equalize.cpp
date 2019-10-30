#include <bits/stdc++.h>
using namespace std;
int main (){
 int n, t;
 cin>>t;
 while(t--){
   long long res = 0;
   cin>>n;
   long long x;
   long long sum = 0;
   for(int i = 0; i < n; i++){
     cin>>x;
     sum += x;
   }
   //cout<<sum<<" "<<n<<endl;
   cout<<((sum % n == 0) ? sum/n : sum/n + 1) <<endl;
   //cout<<ceil((double)sum/(double)n)<<endl;
 }



 return 0;
}
