#include <iostream>
#include <set>
using namespace std;
int main ()
{

    long long int S, B;
    long long izq, der;
    while (cin>>S && cin>>B && S != 0 && B != 0) {
        
        set<int>conjunto; //declaracion del set, donde estan los soldados

        for(int i=1; i<=S; i++){
            conjunto.insert(i);
            //cout<<i<<" ";
        }
        //it_i -> atacar izquierda
        //it_d -> atacar derecha

        for(int x = 1; x<=B; x++)
        {
            cin>>izq>>der;
            set<int>::iterator it_i=conjunto.find(izq), it_d = conjunto.find(der);
            set<int>::iterator aux_it_i = it_i, aux_it_d = it_d;
            

            //cout<<"IT I = "<<*it_i<<endl;
            //cout<<"IT D = "<<*it_d<<endl;
            
            if(it_i == conjunto.begin())
                cout<<"* ";
                  else
                  {
                      int impIzq = *(--it_i);
                      cout<<impIzq<<" ";
                  }
            if(++it_d == conjunto.end())
                cout<<"*\n";
                  else
                  {
                      //int impDer = *it_d;
                      cout<<*it_d<<"\n";
                  }
            
            //cout<<"aux izq = "<<*aux_it_i<<endl;
            //cout<<"aux der = "<<*aux_it_d<<endl;
            
            
            int it_for = 0;
            for(it_for = *aux_it_i; it_for != *aux_it_d; ++it_for){
                conjunto.erase(it_for);
            }
            conjunto.erase(it_for);
            
            /*cout<<"Tamaño del set = "<<conjunto.size()<<endl;
            
            cout<<"Elementos del set: \n";
            set <int>:: iterator it = conjunto.begin();
            while (it != conjunto.end()) {
                cout<<*it<<" ";
                it++;
            }
            cout<<endl;*/
            //for(int i = 1; i<S; i++)
                //cout<<++(*conjunto)<<" ";
            
        }
        
        cout<<"-\n";
        
    }//Fin del while


 return 0;
}
