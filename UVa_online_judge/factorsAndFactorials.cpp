#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
int main (){

  vector<int>criba(110, 1);
  vector<int>primo;
  criba[0] = criba[1] = 0;
  for(int i = 2; i <= 101; i++){
    if(criba[i] == 1){
      for(int j = i*i; j <= 101; j+=i){
        criba[j] = 0;
      }
    }
  }

  /*for(int i = 0; i < 101; i++){
    cout<<criba[i]<<" ";
  }*/

  int N;
  while(cin>>N && N != 0){
    map<int, int>frec;
    for(int i = 2; i <= N; i++){

      if(criba[i] == 1){
        frec[i]++;
      }else{
        int x = i;
        for(int j = 2; j <= sqrt(i); j++){
          while(x % j == 0){
            x = x / j;
            frec[j]++;
          }
        }
        if(x > 1){
          frec[x]++;
        }
      }//else de is es primo o no
    }//for del factorial

    if(N < 10){
      cout<<"  "<<N<<"! =";
    }else if(N < 100){
      cout<<" "<<N<<"! =";
    }else{
      cout<<N<<"! =";
    }


    int cont = 1;
    //cout<<frec.size()<<endl;
    for(auto x: frec){
      //cout<<x.first<<" and ";
      //cout<<x.second;
      if(x.second < 10){
        cout<<"  "<<x.second;
      }else if(x.second >= 10 && x.second < 100){
        cout<<" "<<x.second;
      }else if(x.second >= 100) {
        cout<<x.second;
      }
      if(cont == 15 && frec.size() > 15)cout<<endl<<"      ";
      cont++;
    }
    cout<<"\n";

  }

  return 0;
}
