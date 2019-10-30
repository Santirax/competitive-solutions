#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*ll lcs( string X, string Y){
	int m = X.size();
	int n = Y.size();

   ll L[m+1][n+1];
   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}*/

int main(){
  int a=0, g=0, t=0, c=0;

  int n;
  cin>>n;
	string s;
  cin>>s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A')a++;
    if(s[i] == 'G')g++;
    if(s[i] == 'T')t++;
    if(s[i] == 'C')c++;
  }

  int res = min (min(a, g), min(t, c));
  cout<<res<<"\n";
  return 0;
}
