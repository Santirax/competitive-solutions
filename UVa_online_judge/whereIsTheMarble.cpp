#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
  int N, Q, caso = 1;

  while(cin>>N && cin>>Q && N != 0 && Q != 0){

    vector <int> marbles;
    int x;
    /*Leemos las canicas*/
    for(int i = 0; i < N; i++){
      cin>>x;
      marbles.push_back(x);
    }

    /*Ordenamos el vector*/
    sort(marbles.begin(), marbles.end());

    /*Pedimos las queries junto con la binaria alv*/
    cout<<"CASE# "<<caso<<":"<<endl;
    for(int i = 0; i < Q; i++){
      int querie;
      cin>>querie;
      int ini = 0, mid, fin = marbles.size()-1, res = -1;
      while(ini <= fin){
        mid = (ini+fin)/2;
        if(marbles[mid] < querie){
          ini = mid+1;
        }else{
          fin = mid-1;
          res = mid;
        }
      }
      if(querie != marbles[res])
       cout<<querie<<" not found\n";
        else
         /*res+1 compensando que estamos indexando desde 1*/
         cout<<querie<<" found at "<<res+1<<"\n";
    }

    /*Meramente para la impresion*/
    caso++;

  }

  return 0;
}
