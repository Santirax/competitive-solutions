#include <bits/stdc++.h>
using namespace std;

inline int sumDig(int x){
 int sum = 0;
 while(x != 0){
   sum += (x%10);
   x /= 10;
 }
 return sum;
}

int main (){
 int n;
 cin>>n;
 int res;
 for(int i = n; ;i++ ){
   if(sumDig(i) % 4 == 0){res = i; break;}
 }
 cout<<res<<"\n";
 return 0;
}
