#include<iostream>
#include <vector>
using namespace std;
typedef long long int lli;
lli size = 1e7;
vector<lli>criba(size+10, 1);
//vector<lli>criba(size+10, 1);
void sieve(){
  criba[0] = criba[1] = 0;
  for(lli i = 2; i <= size; i++){
    if(criba[i]){
      for(lli j = i*i;  j <= size; j+=i){
        criba[j] = 0;
      }
    }
  }
}

//Funcion chingona
/*Dada una cadena (string) y su intervalo [a,b], convierte
esa cadena en un entero (long long int)*/
lli subStringToInt(string s, int i, int j){
  lli sub = 0;//Variable que guarda el resultado
  for (int x = j, idx = 0, pot = 1; x >= i; x--, idx++,  pot*=10) {
    /*Trucazo para convertir un numero de tipo char a tipo int
    restando el ASCII del 0, y para respetar el numero, se multilica por
    la potencia que lo respresenta en la cadena, se hace de j a i para respetar
    la posicion, pinche sistema numerico chido xD*/
    sub += ((s[x] - '0')*pot);
  }
  //cout<<sub<<endl;
  return sub;
}

int main(){

  //Criba de Eratostenes para colar primos
  sieve();
  /*for (int i = 0; i < 10; i++) {
    cout<<criba[i]<<" ";
  }*/
  //La cadena que se va a leer
  string s;
  while (cin>>s && s != "0") {
    //Variable para la respuesta con un valor centinela
    int res = -1;
    //Este for viene del analisis de que el numero primo dentro de la cadena
    //Es menor que 100,000, lo que significa a lo mas 6 digitos, de hecho 5
    //Porque el 100,000 no es primo xD
    for(int i = 0; i < 6; i++){
      //Un for recorriendo la cadena
      for(int j = 0; j < s.size(); j++){
        //lli s1 = subStringToInt(s, j, j);
        //Si el tamaño de la subcadena es mayor al tamaño de la cadena
        //Quiere decir que ya no va a haber mas cadenas de dicho tamaño
        if(j+i >= s.size())break;
        //Funcion creada por un servidor xD
        lli s1 =  subStringToInt(s, j, j+i);
        //Si la subcadena en entero es primo, es mayor que el actual y es menor
        //a 100,000 (error de calculo xD) entonces esa subcadena es el actual
        if(criba[s1] && s1 > res && s1 < 100000){
          res = s1;
          //cout<<res<<endl;
        }
        //cout<<j<<", "<<j+i<<endl;
      }
    }
    cout<<res<<"\n";
  }


 return 0;
}
