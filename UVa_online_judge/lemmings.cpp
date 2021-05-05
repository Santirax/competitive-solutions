#include <iostream>
#include <queue>
using namespace std;
int main ()
{
    
    int N = 0;
    cin>>N; //Los casos de prueba
    
    for(int i = 0; i<N; i++)
    {

        priority_queue <int> soldB;
        priority_queue <int> soldG;
        queue <int> auxB;
        queue <int> auxG;
        
        int B, SG, SB; //B -> campos disponibles SG -> Numero de soldados verdes SB -> Numero de soldados azules
        cin>>B>>SG>>SB;
        
        int sg, sb;
        for(int x = 0; x < SG; x++) //Escaneamos soldados verdes y los metemos al set
        {
            cin>>sg;
            soldG.push(sg);
        }
        
        for(int x = 0; x < SB; x++) //Escaneamos soldados azules y los metemos al set
        {
            cin>>sb;
            soldB.push(sb);
        }
        
        if(i != 0) //Esto solo es para coregir el error de presentation que tuve como 3 veces, me lleva la...
        cout<<endl;
        
        while(soldB.size() > 0 && soldG.size() > 0) //Mientras que existan soldados, que siga la masacre xD
        {
            for(int b = 0; b < B; b++) //Campos de batalla validos
            {
                
                if(soldB.top() > soldG.top())
                {
                    auxB.push(soldB.top() - soldG.top()); //El auxiliar para guardar los soldados sobrevivientes
                }
                else if(soldB.top() < soldG.top())
                {
                    auxG.push(soldG.top() - soldB.top()); //El auxiliar para guardar los soldados sobrevivientes
                }
                
                soldB.pop(); //Eliminamos lo que acabamos de usar blue y green, (soldados que combatieron)
                soldG.pop();
                
                //Si ya alguno es cero que se salga
                if(soldB.size() == 0 || soldG.size() == 0) break;
                
            }
            
            //Este el paso mas importante ya que como te dan los campos de batalla una vez que ya terminaron los combates por cada campo de batalla, hay que actualizar los soldados sobrevivientes dentro de todo el grupo ya que puede que existe un sobreviviente con un poder mas alto que los demas
            while(auxB.size() > 0)
            {
                soldB.push(auxB.front());
                auxB.pop();
            }
            
            while(auxG.size() > 0)
            {
                soldG.push(auxG.front());
                auxG.pop();
            }

            
        }//Fin del while

        //Si no quedaron soldados, nadie gano :/
        if(soldB.size() == 0 && soldG.size() == 0)
        {
            cout<<"green and blue died\n";

            //Ganaron los Blue
        } else if(soldB.size() > 0 && soldG.size() == 0)
        {
            cout<<"blue wins\n";
            while(soldB.size() > 0)
            {
                cout<<soldB.top()<<endl;
                soldB.pop();
            }
            //Ganaron los Green
        }else if (soldG.size() > 0 && soldB.size() == 0){
            
            cout<<"green wins\n";
            while(soldG.size() > 0)
            {
                cout<<soldG.top()<<endl;
                soldG.pop();
            }
        }
        
        
    } //Acaba el for principal

    /*Que onda. Una pregunta, Cómo haces esto con un set?? No se me ocurrio como hacerlo con un set, bueno si, pero no funciono porque cuando haces erase se borran todos los elementos con el mismo valor numerico y hasta ahi quedo mi idea :/*/

 return 0;
}

