#include <bits/stdc++.h>
using namespace std;
int main (){
 vector<int>dp(105);
 dp[1] = 1;
 int n;
 cin>>n;
 for(int i = 2, j = 4; i <= n; j+=4, i++)
   dp[i] = dp[i-1] + j;

 cout<<dp[n]<<"\n";

 return 0;
}
