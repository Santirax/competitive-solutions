#include <iostream>
#include <set>
using namespace std;
int main ()
{
    long long int M, N, contDisc = 0;
    while (cin>>N>>M && N != 0 && M != 0)
    {
        set <int> discos; //Declaramos un set de discos por cada caso
        for(int i = 0; i<N; i++)
        {
            int x;
            cin>>x;
            discos.insert(x);
        } //Pedimos los primeros discos y los guardamos en el set
        
        for(int i = 0; i<M; i++)
        {
            int y;
            cin>>y; //Pedimos segundos discos
            set <int> :: iterator f; //Declaramos un iterator para ser el find de abajo
            f = discos.find(y); //Buscamos el valor de y (disco) en el set
            if((*f) == y) //Como no se me ocurrio una forma de compararlo, puse que si el valor al que apunta el puntero es igual al valor original, si lo encontro.
            {
                contDisc++; //Como esta ese dico, se aumenta el contador
            }
            
        }
        cout<<contDisc<<endl; //Impresion
        contDisc = 0; //Reiniciar el contador
    }

 return 0;
}
