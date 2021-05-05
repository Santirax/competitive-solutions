#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main (){

  int N;
  cin>>N;

  while(N--){
    int A, C, a1, c1;
    cin>>A>>C;
    a1 = A;
    c1 = C;

    //LCM (A, B) = C
    //A la tengo, C tambien, el chiste es encontrar B y sea minima

    //Mapa para el factor y su potencia para a y c
    map<int, int>factIgualesC;
    map<int, int>factIgualesA;
    //vector<int>fact;

    /*La tipica factorizacion sqrt(N), que ya se conoce, mapeando
    el valor del factor con su potencia, tanto para A como para B*/
    long double raiz = sqrt(C);

    for(int i = 2; i <= raiz; i++){
      while(C % i == 0){
        C = C/i;
        factIgualesC[i]++;
      }
    }
    if(C > 1){
      factIgualesC[C]++;
    }

    raiz = sqrt(A);
    for(int i = 2; i <= raiz; i++){
      while(A % i == 0){
        A = A/i;
        factIgualesA[i]++;
      }
    }
    if(A > 1){
      factIgualesA[A]++;
    }

    /*Mi cirterio es que si la division de C/A no es
    entera no contiene los factores del LCM (A, B) = C
    */
    long double division = (float)c1/(float)a1;

    int divEntera = (int)division;

    if(division == divEntera){
      /*Si es entera quiere decir que los contiene
      y eso se usa para ver cuales son esos factores
      que pertencen a B y sean minimos*/
      int B = 1;
      /*Se toma los el exponentes que sean mayores, se elevan
      a esa potencia y se multiplican a la B, en caso de que sean
      iguales asi se deja porque quiere decir que C ya los contiene*/
      for(auto x: factIgualesC){
        if(x.second > factIgualesA[x.first])
          B *= pow(x.first, x.second);
           else if (x.second < factIgualesA[x.first])
            B *= pow(x.first, factIgualesA[x.first]);
      }
      cout<<B<<"\n";
    }else{
      cout<<"NO SOLUTION\n";
    }
  }


  return 0;
}
