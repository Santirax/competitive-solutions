#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main ()
{
    int N;

    //cin>>N;
    
    while(cin>>N && N != 0)
    {
        stack <int> station;
        queue <int> train;
        for(int i = 0; i<N; i++)
        {
            train.push(i+1);
            //cout<<"Tamaño = "<<train.size()<<endl;
            //cout<<"Vagon enfrente = "<<train.front()<<endl;
            //cout<<"Ultimo vagon = "<<train.back()<<endl;
        }
        
        int cont = 0;
        int vagon;
        while(cin>>vagon && vagon != 0)
        {

            if(station.size() != 0 && vagon == station.top())
            {
                station.pop();
            } else {
                
                int sizeTrain = train.size(); //Tamaño del tren para saber, cuantas posiciones hay que evaluar en el for
                for(int i = 0; i<sizeTrain; i++)
                {
                    if(train.front() != vagon) //EL tren original es distinto al que me piden, lo meto en la pila
                    {
                        station.push(train.front()); //Ponemos el vagon del tren ya creado en la pila
                        train.pop(); //Borramos los elementos de la cola que ya estan en la pila
                    } else {
                        train.pop();
                        break;
                    }
                }

            }
            
            //cout<<"train enfrente = "<<train.front()<<endl;
            //cout<<"station = "<<station.size()<<endl;
            //cout<<"train = "<<train.size()<<endl;
            cont++;
            if(cont == N)
            {
                if(station.size() == 0)
                {
                    cout<<"Yes\n";
                }else {
                    cout<<"No\n";
                    while(station.size())station.pop(); //Limpiar la ststation para la proxima iteracion
                }
                
                while(train.size())train.pop(); //Limpiar el train para la siguinete iteracion
                cont = 0;
                
                
                for(int i = 0; i<N; i++)
                {
                    train.push(i+1);
                    //cout<<"Tamaño = "<<train.size()<<endl;
                    //cout<<"Vagon enfrente = "<<train.front()<<endl;
                    //cout<<"Ultimo vagon = "<<train.back()<<endl;
                }
                
            }
            
        }
        
        cout<<endl;
        
    }
    
    
    //cout<<"Hola mundo"<<endl;



 return 0;
}
