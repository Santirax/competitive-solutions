#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;

  int contDif = 0;
  for(int i = 0, j = s.size()-1; i < (s.size()/2); i++, j--){
    if(s[i] != s[j]){
      contDif++;
    }
  }
  if(contDif == 1 || (contDif == 0 && s.size()%2==1))cout<<"YES\n";
  else cout<<"NO\n";

  return 0;
}
