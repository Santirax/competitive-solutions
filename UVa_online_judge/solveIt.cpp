#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
typedef long double doble;

doble f (doble x, doble p, doble q, doble r, doble s, doble t, doble u){
  doble res = p*exp(-x) + q*sin(x) + r * cos(x) + s*tan(x) + t * (x*x) + u;
  return res;
}

int main (){
  //Leemos todas las variables
  doble p, q, r, s, t, u, x;
  while (cin>>p>>q>>r>>s>>t>>u) {
    /*Empezamos con la binaria, dado que son funciones trigonometricas, el rango es de
    0 a 1, hacemos la binaria donde x = mid y nos sirve para empezar a hacer sustitucion
    en la f(), que esta arriba*/
    doble ini = 0, fin = 1, mid, res;
    for(int i = 0; i < 100; i++){
      mid = (ini + fin)/2.0;
      /*El resultado se guarda en res*/
      res = f (mid, p, q, r, s, t, u);
      /*Si el resultado es mayor a cero (estamos buscando el 0, la raiz de la funcion)
      entonces acortamos el rango de busqueda por lo que esta entre mid+.0001 y fin*/
      if(res > 0){
        ini = mid+0.0001;
      } else {
        /*De lo contrario, que sea menor a cero significa que la x (mid) debe de estar entre
        ini y mid-0.0001, se que esto funciona, pero no se porque :v*/
        fin = mid-0.0001;
      }
      //cout<<1e-5<<endl;
      //cout<<mid<<" y "<<res<<endl;
    }
    //Y tiene que tener que el mid (x) tenga estas condiciones para que no tenga solucion
    if(mid < -0.00001 || mid > 1.0)
     cout<<"No solution\n";
      //else if(mid == -0.0000)
        //cout<<fixed<<setprecision(4)<<mid*-1<<"\n";
         else
         //El valor absoluto es por algo extraño que hace que aparesca -0 
          cout<<fixed<<setprecision(4)<<abs(mid)<<"\n";


  }

  return 0;
}
