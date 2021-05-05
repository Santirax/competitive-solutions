#include <iostream>
#include <vector>
#define T 3
using namespace std;

//Funcion que me transforma la matriz con la funcion f(g) que viene en el problema,
//todas las posibles combinaciones a patita
void f(int f[][3]){
    
    //Declaramos un arreglo auxiliar para usar esos valores, sin alterar los valores originales, de f[][].
    int g_aux[T][T];
    for(int i = 0; i<T; i++)
    {
        for (int j = 0; j<T; j++)
        {
            g_aux[i][j] = f[i][j];
        }
    }
    //Copiamos los de f en g para poder ocuparlos en las siguientes operaciones
    
    f[0][0] = (g_aux[0][1] + g_aux[1][0]) % 2;
    f[0][1] = (g_aux[0][0] + g_aux[1][1] + g_aux[0][2]) % 2;
    f[0][2] = (g_aux[0][1] + g_aux[1][2]) %2;
    f[1][0] = (g_aux[0][0] + g_aux[1][1] + g_aux[2][0]) %2;
    f[1][1] = (g_aux[0][1] + g_aux[1][2] + g_aux[2][1] + g_aux[1][0]) %2;
    f[1][2] = (g_aux[0][2] + g_aux[1][1] + g_aux[2][2]) %2;
    f[2][0] = (g_aux[1][0] + g_aux[2][1]) %2;
    f[2][1] = (g_aux[2][0] + g_aux[1][1] + g_aux[2][2]) %2;
    f[2][2] = (g_aux[2][1] + g_aux[1][2]) %2;
    
    /*cout<<"\nImpresion de la nueva matriz\n";
    for(int i = 0; i<T; i++)
    {
        for (int j = 0; j<T; j++)
        {
            cout<<f[i][j];
        }
        cout<<endl;
    }
    cout<<endl;*/ // Esto se puede omitir era solo para ver que todo estuviera en orden con la funcion
    
}


//Funcion que me regresa si una matriz es de puros ceros o no.
bool cero(int g[][3]) {
    
    bool band = false;
    for(int i = 0; i<T; i++)
    {
        for (int j = 0; j<T; j++)
        {
            if(g[i][j] == 1){
                band = true;
                //cout<<"Entro\n";
                break;
            }
        }
        
    }
    
    return band;
    //Si es falso es que es una matriz de puro cero
    //Si es verdadero quiere decir que al menos tiene un uno y se puede seguir con la funcion
    
}



int main ()
{
    //const int T = 3;
    int N;
    char ch_grid[T][T];
    int grid[T][T];
    cin>>N;
    for(int x = 0; x<N; x++)
    {
        //Escaneo de entrada en tipo char
        cin.ignore();
        for(int i = 0; i<T; i++)
        {
            for (int j = 0; j<T; j++)
            {
                cin>>ch_grid[i][j];
            }
        }
        
        //Como no se me ocurre otra forma pues trabajare con enteros en vez de caracteres
        //La cosa va asi, como solo son 0 y 1 comparo el caracter y si es 1 guardo 1 pero entero, igual con el cero
        for(int i = 0; i<T; i++)
        {
            for (int j = 0; j<T; j++)
            {
                if(ch_grid[i][j] == '0')
                    grid[i][j] = 0;
                      else if(ch_grid[i][j] == '1')
                          grid[i][j] = 1;
            }
        }
        
        //Trabajo con grid, que es un arreglo de enteros, para poder hacer la funcion que el probelma pide
        
        
        int cont_i = 0; // contador del indice
        //bool band = false; //bandera para saber cuando dejar de llamar a la funcion
        if (cero(grid) == false){
           cout<<cont_i-1<<"\n";
        }
        else
            {
                  while(cero(grid) != false)
                  {
                      f(grid);
                      cont_i++;
                      
                  }//Fin del while
                  
                  cout<<cont_i-1<<"\n";
                  
            }

        
    }




return 0;
}
