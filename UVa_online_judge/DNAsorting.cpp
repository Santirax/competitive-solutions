#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main (){

  int T;
  int N, M;
  cin>>T;
  while (T--) {

    /*Un vector que contiene un par el cual contiene otro par con la cadena y un float (por que un float?
    Mas adelante la explicacion) que es el numero de inversiones que tiene esa cadena y como el metodo a usar
    es el burbuja, me va a ordenar la cadena, entonces necesito salvar la cadena original*/
    vector< pair < pair<float, string>, string > > cadenas;
    //Un par para guardar valores por iteracion y hacer push_back
    pair < pair <float, string>, string>  par;
    //Otro pair auxiliar del auxiliar
    pair <float, string> parAux;
    //Leer la entrada
    cin>>N>>M;
    //Liena en balnco
    cin.ignore();
    //Una variable flotante auxiliar inicializada en un valor despreciable, que por las dimensiones
    //de M y N nunca llegue a ser entero pero util para saber cual es el primer elemento
    float aux = 0.001;

    //Leemos la entrada
    for (int i = 0; i < M; i++, aux+=0.001) {
      //Guardamos cadena
      getline(cin, parAux.second);
      //Su valor de inversiones va a ser un decimal muy pequeño que nos va a servir mas adelante,
      //sin que afecte directamente el entero de inversiones
      parAux.first = aux;
      //Guardamos el primer par del par total
      par.first = parAux;
      //Salvamos la cadena original
      par.second = parAux.second;
      //Lo metemos al arreglo
      cadenas.push_back(par);
    }

    //Impresion de ayuda
    /*for(int i = 0; i < M; i++){
      cout<<cadenas[i].first.second<<" y "<<cadenas[i].first.first<<endl;
    }*/

    //Tenemos que recorrer todos las cadenas dentro del arreglo
    for(int x = 0; x < M; x++)
    {
      //Metodo burbuja para contar las inversiones, metiendonos con el pair del pair e incrementando sus inversiones xD
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          if(cadenas[x].first.second[j] > cadenas[x].first.second[j+1])
          {
            swap(cadenas[x].first.second[j], cadenas[x].first.second[j+1]);
            cadenas[x].first.first++;
          }
        }
      }
    }

    //Impresion de ayuda
    /*cout<<"Sin sort\n";
    for(int i = 0; i < M; i++){
      cout<<cadenas[i].first.first<<" y "<<cadenas[i].first.second<<endl;
    }*/

    //Hacemos un sort de las inversiones y aqui es donde nos ayudan los decimales, porque asi se ordenan
    //conforme al orden de entrada en caso de que las inversiones sean las mismas
    sort(cadenas.begin(), cadenas.end());

    //Impresion de ayuda
    /*cout<<"Con sort\n";
    for(int i = 0; i < M; i++){
      cout<<cadenas[i].first.first<<" y "<<cadenas[i].first.second<<endl;
    }*/

    //Impresion de las cadenas ordenadas
    for(int i = 0; i < M; i++){
      cout<<cadenas[i].second<<"\n";
    }

    if(T) //Presentacion castrosa xD
    cout<<"\n";

    //Y listo, problema resuelto

  }

  return 0;
}
