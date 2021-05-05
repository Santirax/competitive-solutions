#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

int main (){

 int N;
 while(cin>>N){
  Long cont = 1;
  Long mod = 1%N;
  while(mod != 0){
   cont++;
   mod = ((mod*10)+1)%N;
  }
  cout<<cont<<"\n";

 }


  return 0;
}
