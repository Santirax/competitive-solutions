///MI SEGMENT TREE

#include <bits/stdc++.h> //Importa todas las bibliotecas estandar
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
const int INF = INT_MAX; //Definimos nuestro infinito

int N;	// Numero de elementos
int Q;  // Numero de querys
int L,R;// Para el incio y fin de querys, respectivamente

int A[1100000]; //Arreglo de numeros iniciales
int ST[5000000];//Se lleva el segment Tree

/*
	IMPORTANTE :
	Por la forma del árbol, el tamaño del arreglo ST debe ser 4 veces del tamaño arreglo
	original, es decir, 4*N.
	De igual forma, funciona con valores de N que no sean potencias de 2. Por ejemplo,
	para 7, se partiría en 2 pedazos, uno de 4 y uno de 3. Después el de 4 en dos de tamaño 2.
	Y el de 3, en dos pedazos, uno de tamaño 2 y otro de tamaño 1.
*/

//Va calculando los rangos y sus respuestas
//ini es el inicio del rango a guardar, y fin el final.
//pos es el índice del nodo en el que nos encontramos.

//int maxPos;

int ans = 0; //Para contar cuantos nodos
//no cumplen con la condicion de que sean multiplos de la x

int maxPos; //Numero de nodos en el arbol

//Creamos el Segment Tree
//Cuya f(x) es el gcd de sus dos hijos
void Crea(int ini, int fin, int pos){

  maxPos = max(pos, maxPos);
	//Si ini == fin, entonces es porque ya es una hoja del árbol.
	if(ini == fin){
		//A la hoja le asignamos el valor de A[ini]
		ST[pos] = A[ini];
		return;
	}

	//Si no es hoja, debemos calcular sus hijos.
	int mitad = (ini+fin)/2;
	Crea(ini,mitad,pos*2+1);
	Crea(mitad+1,fin,pos*2+2);

	//Ya que tenemos la respuesta de nuestros hijos
	//Podemos calcular la respuesta para el nodo actual de la siguiente forma
	//Se puede cambiar por la función que queramos adaptar
	ST[pos] = __gcd(ST[pos*2+1],ST[pos*2+2]);

}

/*
IMPORTANTE:
No es necesario, para cada nodo, a que rango corresponde,
ya que, cada vez que hagamos un recorrido, necesitamos empezar en la raiz.
En la raiz sabemos que el rango es [0,N-1]. Por lo tanto, el inicio y fin los podemos
llevar siempre en los parámetros y nos ahorramos espacio en memoria.
*/

//pos indica el índice del nodo en el que estamos
//ini es el inicio del rango correspondiente al nodo con índice 'pos'
//fin es el final del rango correspondiente al nodo con índice 'pos'


//query entre [inir, finr] cuyo gcd sea igual a x
void Query(int ini, int fin, int pos, int inir, int finr, int x){

	//Pregunta si el rango actual y la query están separados
	//Es decir, si es un rango que no usaremos
	if(fin < inir || finr < ini) return;
  //De lo contrario, si estamos en el rango, vamos a procesarlo
  else if(ini >= inir && fin <= finr){

    //Vamos por casos en cada nodo.

    //Si, el arbol en esa posicion es multiplo del gcd
    //por la misma definicion del gcd, todos los numeros
    //tienen de factores primos comunes a x, por lo tanto,
    //se puede colocar el valor de x en un valor
    //del arreglo para que quede como el gcd
    if(ST[pos] % x == 0){
      return;
    } else{
      //De lo contrario
      int aux = pos; //Vamos a recorrer el arbol
      //por lo que necesitamos un indice auxiliar para no cmabiar
      //la posicion.

      //En caso de que no sea multiplo el nodo, vamos a explorar
      //sus hijos en busca del nodo que podamos cambiar, para cumplir
      //con la condicion del problema.
      while(aux < maxPos){

        //Preguntamos por el hijo izquierdo.
        //Si no es multiplo, vamos a preguntar por el derecho
        if(ST[2*aux+1] % x != 0){

          //Preguntamos por el hijo derecho
          //Si no es multiplo, ninguno de los hijos es multiplo del gcd
          //Por lo tanto, existen al menos dos numeros
          //que no contienen todos los factores primos
          //que x, en otras palabras
          //hay que cambiar al menos dos numeros para que el gcd sea x
          if(ST[2*aux+2] % x != 0){
            ans += 2; //Aux sirve para saber cuantos
            //nodos no cumplen la condicion
            return;
          }else{
            //Exploramos el hijo izquierdo
            aux = 2*aux+1;
          }

        }else{
          //exploramos el hijo derecho
          aux = 2*aux+2;
        }
        //cout<<aux<<endl;
      }
    }

    //cuando entramos al nodo, finalmente hay que marcar que lo visitamos
    //porque podriamos marcar mas de un nodo
    ans++;
    return;
  }

  //Y continuamos con la query normal

	//Pregunta si el rango actual está completamente contenido en la Query
	//Es decir, si es un segmento fundamental
	//if(ini >= inir && fin <= finr) return ST[pos];

	//Esto es para el tercer caso
	int mitad = (ini+fin)/2;
	//Se matienen inir y finr, pues no cambia la query
	Query(ini,mitad,pos*2+1, inir, finr, x);
  /*if (ans > 1) {
    return;
  }*/
	Query(mitad+1,fin,pos*2+2, inir, finr, x);

	//Se puede cambiar por la función que
	//queramos adaptar
	//return min(izq,der);

}

//Actualiza el ST, cambiando el valor del elemento en la posición 'posu', por el valor 'val'
//Y posteriormente actualizamos el gcd
//pos indica el índice del nodo en el que estamos
//ini es el inicio del rango correspondiente al nodo con índice 'pos'
//fin es el final del rango correspondiente al nodo con índice 'pos'

void Update(int ini,int fin,int pos,int posu, int val){

	//Si el rango correspondiente a 'pos' no contiene a 'posu'
	if(fin < posu || posu < ini) return;

	//Si el rango correspondiente al nodo pos va de 'posu' a 'posu'
	if(ini == posu && fin == posu){
		//Si esto sucede, es porque estamos en la hoja correspondiente
		//a la posicion 'posu' del arreglo original

    //Actualizamos el valor
		ST[pos] = val;
		do{
			//Una vez modificado, nos iremos al padre del nodo actual
			//y después actualizamos su valor comparando a sus hijos
			pos = (pos-1)/2;
			//Se puede cambiar por la función que
			//queramos adaptar
			ST[pos] = __gcd(ST[pos*2+1],ST[pos*2+2]); //Y obtenemos el gcd
      //de sus dos hijos
		}while(pos != 0); //Repetir hasta no llegar a la raiz

		return;
	}

	//Si aun no llegamos a la hoja, buscar entre sus 2 hijos.
	int mitad = (ini+fin)/2;
	Update(ini,mitad,pos*2+1,posu,val);
	Update(mitad+1,fin,pos*2+2,posu,val);

}

int main(){

	optimizar_io(0);

	cin >> N;

	for(int i = 0; i < N; i ++)
		cin >> A[i];

  //Creamos el ST de los gcds
	Crea(0,N-1,0);
  int q;
  cin>>q;
  int t, l, r, x;
  int pos, val;
  for(int i = 0; i < q; i++){
    cin>>t;
    if(t == 1){
      cin>>l>>r>>x;
      ans = 0; //Reseteamos la respuesta
      Query(0, N-1, 0, l-1, r-1, x); //Hacemos la query
      /* Si ans es 0, el gcd en ese rango es x
      //Si ans es 1, existe solo un numero tal que si lo cambias
      //el gcd es x

      //Si ans es dos o mayor quiere decir que hay que cambiar mas de un numero
      //tal que si se cambian el gcd sea x. */
      cout<< ((ans < 2) ? "YES\n" : "NO\n");
    }else{
      cin>>pos>>val;
      Update(0, N-1, 0, pos-1, val);
    }
  }

	return 0;
}
