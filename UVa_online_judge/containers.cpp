#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main ()
{
    //A -> 65
    //Z -> 90
    string contains;
    vector< stack<char> > num(100000);
    int caso = 1;
    while (getline(cin, contains) && contains != "end")
    {
        
        //cout<<"Entra";
        num[0].push(contains[0]); //num[0] es como si pusieramos en la pila 1 (pos 0) el elemento 1 (pos 0) de la string, pero no en el vector, sino en la pila, soy el puto amo B);
        
        //cout<<"Caracter, 1era pila = "<<num[0].top()<<endl;
        //cout<<"Tamaño de la string = "<<contains.size()<<endl;
        int pila = 0;
        for(int i = 0; i<contains.size()-1; i++)
        {
            int ban = 0;
            for(int pila_temp = 0; pila_temp <= pila; pila_temp++)
            {
             
                if(contains[i+1] <= num[pila_temp].top())
                {
                    num[pila_temp].push(contains[i+1]);
                    ban = 1;
                    
                    //cout<<"Entro\n";
                    break;
                }
                
                //cout<<"letra = "<<contains[i+1]<<endl;
                //cout<<"EL top de num["<<pila_temp<<"] = "<<num[pila_temp].top()<<endl;
            
            }
            
            if(ban == 0)
            {
                pila++;
                num[pila].push(contains[i+1]);
                //cout<<"Entro al 0 y pila = "<<pila<<endl;
            }
            
            
            /*int pila_temp;//Para recorrer entre las pilas sinn modificar ya la cantidad que hay
            int ban = 0;
           
            for(pila_temp = 0; pila_temp<pila; pila_temp++)
            {
                if(num[pila_temp].top() < contains[i+1])
                {
                    num[pila_temp].push(contains[i+1]);
                    //cout<<"Entra y elemnto: "<<num[pila_temp].top()<<endl;
                    ban = 1;//break;
                }
            }
            
            if(ban == 0)
            {
                if(contains[i] < contains[i+1])
                {
                    num[pila].push(contains[i+1]);
                    //cout<<"Elemento top cuando cumple = "<<num[pila].top()<<endl;
                } else {
                    //cout<<"Entra\n";
                    pila++;
                    num[pila].push(contains[i+1]);
                    //cout<<"Elemento top = "<<num[pila].top()<<endl;
                    //cout<<"Valor de la pila = "<<pila<<endl;
                }
                
            }

            */
            //cout<<"Elemento top por iteracion = "<<num[pila].top()<<endl;
            //cout<<"Valor de la pila = "<<pila<<endl;

        }
        //cout<<pila<<endl;
        cout<<"Case "<<caso<<": "<<pila+1<<endl; //pila+1 compensando que inicia desde 0
        caso++;
    }



 return 0;
}
