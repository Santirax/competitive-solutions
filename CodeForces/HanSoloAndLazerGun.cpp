#include <bits/stdc++.h>
using namespace std;
int main (){
 int N;
 double x_o, y_o, x, y;
 cin>>N;
 cin>>x_o>>y_o;
 set<double>pendientes;
 for(int i = 0; i < N; i++){
  cin>>x>>y;
  double m;
  if (x-x_o == 0){
    pendientes.insert(1e6);
  }else{
    m = (y-y_o)/(x-x_o);
    pendientes.insert(m); 
   }
 }
 cout<<pendientes.size()<<endl;
 return 0;
}
