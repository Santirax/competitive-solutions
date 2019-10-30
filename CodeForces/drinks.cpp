#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main (){
   int tot;
   cin>>tot;
   vector<ld>per(tot+2, 0);
   for(int i = 0; i < tot; i++)
    cin>>per[i];
   
   ld totPer= 0;
   for(int i = 0; i < tot; i++){
     totPer += (per[i]/100.0);
   }

   cout<<fixed<<setprecision(8);
   cout<<(totPer/(ld)tot)*100.0<<endl;

   return 0;
}
