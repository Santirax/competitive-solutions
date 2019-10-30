#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

//vvi adjList;
const int MAX = 1000;
int n;

inline int bfs(int ini, vvi &adjList){

  queue<int> cola; //Cola para la bfs
  bitset<MAX>vis; //Saber si el nodo ya esta visitado
  //vi prev(MAX, -1); //Saber cual es el anterior nodo visitado de un nodo u

  cola.push(ini); //Metemos el primer elemento en la cola
  vis[ini] = true; //Y ya esta visitado

  int res;

  while(!cola.empty()){ //Mientras que la cola tenga elementos
    int nodo_actual = cola.front(); //Obtenemos el nodo al frente de la cola
    cola.pop(); //Y lo sacamos de la cola
    for(int i = 0; i < adjList[nodo_actual].size(); i++){ //Iteramos sobre toda la lista de adyacencia de ese nodo
      int u = adjList[nodo_actual][i]; //Nodo perteneciante a la lista de adyaciente del nodo actual
      if(!vis[u]){ //Si no esta visitado
        cola.push(u); //Metemos a la cola ese nodo
        vis[u] = true; //Actualizamos de que ya fue visitado
        //prev[u] = nodo_actual; //Y decimos que el anterior de u es el nodo_actual
      }else{
        res = u;
        return u;
      }
    }
  }

  return res;
}

int main() {

  int q;
  cin>>n; //Numero de niños
  vvi adjList(n);
  for(int i = 0; i < n; i++){
    cin>>q;
    adjList[i].push_back(q-1);
  }
  //Creamos la lista de adyacencia, cabe mencionar que es un grafo dirigido

  vector<int>res; //Vector de resultado
  //Iteramos sobre si empezamos por cada uno de los niños
  //Y tiramos la bfs, la bfs se rompe cuando encuentra el
  //primer nodo repetido y es parte de la respuesta
  for(int i = 0; i < n; i++){
    res.push_back(bfs(i, adjList));
  }

  //Imprmimos el resultado
  for(int x: res){
    cout<<x+1<<" ";
  }
  cout<<"\n";

  return 0;
}
