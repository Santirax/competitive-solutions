#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main (){
    int N;
    
    while (cin>>N) {
        
        stack <int> pila;
        queue <int> cola;
        priority_queue <int> prioridad;
        
        int n; //1 o 2 (push o pop)
        int x; //Numero que se tiene que quitar o poner
        int ban_P = 1, ban_Q = 1, ban_PQ = 1; //Valores bandera para saber con que estructura se cumple y con cual no
       
        for(int i = 0; i<N; i++)
        {
            cin>>n;
            if(n == 1)
            {
                cin>>x;
                pila.push(x);
                cola.push(x);
                prioridad.push(x);
                //Entra
                
            } else if (n == 2){
                //Sale
                cin>>x;
                if (pila.size() == 0) //Se evalua que la estructura no este vacia, si lo esta, ya no puede ser
                {
                    ban_P = 0;
                }else{
                    if(pila.top() != x) //De lo contrario, en el sig if el valor debe coincidir con el que dan
                            ban_P = 0; //Si no coincide no es esa estructura
                        else{
                            pila.pop(); //Eliminamos el elemento de la estructura en caso de que si sea
                            
                        }
                    }
                
                if (cola.size() == 0)
                {
                    ban_Q = 0;
                }else{
                    if(cola.front() != x)
                        ban_Q = 0;
                    else{
                        cola.pop(); //Eliminamos el elemento de la estructura
                        
                    }
                }
                
                
                if (prioridad.size() == 0)
                {
                    ban_PQ = 0;
                }else{
                    if(prioridad.top() != x)
                        ban_PQ = 0;
                    else{
                        prioridad.pop(); //Eliminamos el elemento de la estructura
                        
                    }
                }
                
            }
            
        }
        
        //Posibles conbinaciones para los resultados
        if((ban_P == 1 && ban_Q == 1) || (ban_P == 1 && ban_PQ == 1) || (ban_Q == 1 && ban_PQ == 1))
            cout<<"not sure\n";
        else
        if(ban_P == 0 && ban_Q == 0 && ban_PQ == 0)
            cout<<"impossible\n";
        else
        if(ban_P == 1 && ban_Q == 0 && ban_PQ == 0)
            cout<<"stack\n";
        else
        if(ban_Q == 1 && ban_P == 0 && ban_PQ == 0)
            cout<<"queue\n";
        else
        if(ban_PQ == 1 && ban_P == 0 && ban_Q == 0)
            cout<<"priority queue\n";
        
        
    }
    
 return 0;
}
