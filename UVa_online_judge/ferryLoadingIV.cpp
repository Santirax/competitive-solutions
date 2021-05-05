#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//L->dimension del ferry,
int L;


//Funcion para sumar cuantos carros podemos llevar de lado derecho
int sumR(queue<int> &right){
  int sum = 0;
  //Hasta que ya no existan carros o no exista espacio disponible
  for(;right.size()>0 && sum <= L;){
    sum+=right.front();
    if(sum > L){
      sum-=right.front();break;
    }else{
      right.pop();
    }
  }
  return sum;
}

//Funcion para sumar cuantos carros podemos llevar de lado izquierdo
int sumL(queue<int> &left){
  int sum = 0;
  //Hasta que ya no existan carros o no exista espacio disponible
  for(;left.size()>0 && sum <= L;){
    sum+=left.front();
    if(sum > L){
      sum-=left.front(); break;
    }else{
      left.pop();
    }
  }
  return sum;
}



int main (){
  int T;
  cin>>T;
  while(T--){
    //Carros de lado derecho
    queue<int> right;
    //carros de lado izquierdo
    queue<int> left;
    /*Casos->son los carros y medidas, dist->medida por carro,
    dir-> lado derecho o izquierdo*/
    int casos, dist;
    string dir;

    //sum->suma de las longitudes de los carros
    //cont->veces que el barco va a de lugar en lugar, contador de viajes
    //ban = 1->left side
    //ban = 2->right side
    int sum = 0, cont = 0;
    int ban = 1;
    cin>>L>>casos;
    //Convertir metros a centimetros
    L = L*100;

    //Pedir los casos y meterlos a la cola de prioridad
    for(int i = 0; i < casos; i++){
      cin>>dist;
      cin.ignore();
      cin>>dir;

      if(dir == "left")left.push(dist);
      if(dir == "right")right.push(dist);
    }

    /*suponiendo que empiezan solo coches en el lado derecho, mandamos al ferry a ese lado
    y aumentamos el contador de viajes*/
    if(left.size() == 0){ban = 2; cont++;}


    //Simulacion del transporte del ferry
    for(;;){
      //ban = 1, quiere decir que esta del lado izquierdo
      if(ban == 1){
        //Vemos cuantos carros no podemos llevar de acuerdo al espacio en el bote
        sum = sumL(left);
        /*si la suma es mayor a cero existe al menos un carro que podemos llevar
        o si ya no hay carros, ir al otro lado a comprobar si existe al menos un carro
        aumenta el contador de recorrido y la bandera cambia indicando el siguiente recorrido
        a la derecha*/
        if(sum > 0 || left.size() == 0){
          cont++;
          ban = 2;
        }
      }else if(ban == 2){
        /*Lo mismo que arriba xD pero con el lado derecho*/
        sum = sumR(right);
        if(sum > 0 || right.size() == 0){
          cont++;
          ban = 1;
        }
      }
      //Nos detenemos cunado ya no exista carros para llevar
      if(left.size() == 0 && right.size() == 0)break;
    }

    cout<<cont<<endl;


  }

  /*Con este problema ya son 41, por lo que nos vemos en intermedios xD
  y gracias por el tiempo en basicos*/

  return 0;
}
