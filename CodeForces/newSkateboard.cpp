#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5+10;
int main (){

  string s;
  cin>>s;

  long long cont = 0;
  for(int i = 0; i < s.size(); i++){
    if((s[i] - '0')%4 == 0)cont++;
  }


  int dp[MAX];
  dp[0];
  for(int i = 0; i < s.size(); i++)
   dp[i] = i;

  //cout<<s<<endl;
  for(int i = 0; i < s.size()-1; i++){
    string a, b, aux;
    a = s[i], b = s[i+1];
    aux = a+b;
    //cout<<aux<<endl;
    //cout<<aux<<endl;
    int div = stoi(aux, nullptr, 10);
    if(div % 4 == 0)cont += dp[i]+1;
  }

  cout<<cont<<"\n";

  return 0;
}
