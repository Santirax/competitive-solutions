#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;
  int top = 0, down = 0;
  vector<pair<int, int>>dominos;
  pair<int, int>domino;
  for(int i = 0; i < n; i++){
    cin>>domino.first;
    cin>>domino.second;
    top += domino.first;
    down += domino.second;
    dominos.push_back(domino);
  }

  if(top % 2 == 0 && down % 2 == 0)
   cout<<"0\n";
    else{
     int imparTop = 0, imparDown = 0;
     for(auto x: dominos){
       if(x.first % 2 == 1)imparTop++;
       if(x.second % 2 == 1)imparDown++;
       if(x.first % 2 == 1 && x.second % 2 == 1){imparTop--; imparDown--;}
     }
     
     if((imparTop+imparDown)%2 == 1 || (imparTop == 0 && imparDown == 0))
       cout<<"-1\n";
         else{
             cout<<1<<"\n";
         }
          
    }

  return 0;
}
