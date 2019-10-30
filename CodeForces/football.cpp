#include <bits/stdc++.h>
using namespace std;
int main (){
 map<string, int>goals;
 int n;
 cin>>n;
 string s;
 for(int i = 0; i < n; i++){
  cin>>s;
  goals[s]++;
 }

 string winTeam;
 int gols = -1;
 for(auto x: goals){
   if(x.second > gols){
     gols = x.second;
     winTeam = x.first;
   }
 }

 cout<<winTeam<<"\n";
  return 0;
}
