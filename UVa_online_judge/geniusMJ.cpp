#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> punto;
int main (){
  int T;
  int N;
  cin>>T;
  while(T--){
   vector<punto>s1;
   vector<punto>s2;
    cin>>N;
    int x, y;
    punto p;
    for(int i = 0; i < N; i++){
     cin>>x>>y;
     p.first = x;
     p.second = y;
     s1.push_back(p);
    }
    for(int i = 0; i < N; i++){
     cin>>x>>y;
     p.first = x;
     p.second = y;
     s2.push_back(p);
    }

    sort(s1.begin(), s1.end());
    
   int ban = 1;
   int banFin = 0;
    
   for(int i = 0; i < 4; i++){
       
     sort(s2.begin(), s2.end());
     /*for(int x = 0; x < s1.size(); x++){
         cout<<s1[x].first <<" "<< s1[x].second<<" <-> ";
         cout<<s2[x].first <<" "<< s2[x].second<<" = ";
         cout<<hypot((s1[x].first-s2[x].first), (s1[x].second-s2[x].second))<<endl;
    }*/
     //cout<<endl;
     ban = 1;
     double actual, anterior;
     
     actual = hypot(s1[0].first-s2[0].first, s1[0].second-s2[0].second);
     
     anterior = actual;
     //cout<<actual<<endl; 
     for(int j = 1; j < s1.size(); j++){
      actual = hypot((s1[j].first-s2[j].first), (s1[j].second-s2[j].second));
      //cout<<actual<<endl;
      if(actual != anterior){ban = 0; break;}
      anterior = actual;
     }
     
     for(int j = 0; j < s2.size(); j++){
       int aux = s2[j].first;
       s2[j].first = -s2[j].second;
       s2[j].second = aux;;
     }
     
     if(ban == 1)banFin = 1;
     
   }
   
   if (banFin == 1)cout<<"MATCHED\n"; else cout<<"NOT MATCHED\n";

  }



  return 0;
}
