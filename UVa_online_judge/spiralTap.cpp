#include <iostream>
using namespace std;
int main (){
    
    long long int SZ, P;
    while (cin>>SZ && cin>>P && SZ != 0 && P != 0) {
        long long int line = SZ, column = SZ, /*linea y columna*/pos = SZ, /*Determina el anillo*/ lc_aux = 1; /*auxiliar para las posiciones cuando el anillo que encontramos no es el mas exterior*/;
        
        long long int max = SZ*SZ;
        long long int min = (SZ-2)*(SZ-2)+1;/* +1 -> Para que no tome el valor max del anillo menor*/
        
    //EL caso en que el numero sea uno no cumple del todo con los anillo, entonces hubo que improvisar
    //Ademas, el numero de en medio simpre va a ser el uno pongo una condicion para eso
     if(P == 1)
     {
            line = SZ/2+1;
            column = line;
     } else
       {
        //De lo contrario hacer el proceso para cualquier otro numero
        //Mientras que no se cumpla la condicion para que el numero este en el anillo, seguimos ciclando, buscando el anillo
        while (!(P >= min && P <= max)) {
            
            pos-=2;
            max = pos*pos;
            min = (pos-2)*(pos-2)+1/*Por lo mismo explicado con anterioridad*/;
            line--;
            column--;
            lc_aux++;
            //Determinar el anillo donde se encuentra el numero a buscar
        }
        
        //Al minimo le sumamos 1 ya que queremos trabajar solo con los numeros en el anillo
        //y el minimo da el max del siguiente anillo, entonces le sumamos 1 y con eso nos da el minimo elemento del anillo con el que se va a trabajar
        min = min + 1;
        
        
        //En pos tenemos guaradada la posicion del anillo en el que esta nuestrao numero
        //En max, se encunetra la posicion mas grande del anillo (el anillo con el que trabajamos), y en min su numero mas pequeño de dicho anillo
        
        //cout<<"El max = "<<max<<" y el minimo = "<<min<<endl;
        //cout<<"La line act = "<<line<<" y la columna = "<<column<<endl;
        int x = 0;
        
        
        for(x = 1; x<=4/*Son cuatro cuadrantes del anillo*/; x++)
        {
            if(P <= max && P>=max-pos+2/*Le realizamos esa operacion a max por que con esa operacion se encuentra el valor minimo del cuadrante */)
            {
                /*Si lo encunetra en ese cuadrante que se salga de la estructura y que "x" sirva para saber el cuadrante*/
                break;
            } else {
                /*De lo contrario nos pasamos al siguiente cuadrante realizando la operacionde aqui abajo*/
                max=max-pos+1;
            }
        }
        
        //cout<<"Cuadrante donde se encuntra = "<<x<<" y su max = "<<max<<endl;
           //cout<<"Posicion = "<<pos<<endl;
        /*Dependiendo la x (cuadrante) asignamos los valores a line y column*/
        if(x==1){
            //line = SZ; //No pasa nada aqui, se conserva el valor de la linea y columna
            //column = SZ;
            
        }else
            if(x==2){
                
                if(pos == SZ)/*Anillo mas exterior*/{
                    line = 1;
                }else{
                    line = lc_aux;
                }
                
                //column = SZ;
            }else
                if(x==3){
                    
                    if(pos == SZ)/*Anillo mas exterior*/{
                        line = 1;
                        column = 1;
                    }else{
                        line = lc_aux;
                        column = lc_aux;
                    }

                }else
                    if(x==4){
                        
                        if(pos == SZ)/*Anillo mas exterior*/{
                            column = 1;
                        }else{
                            column = lc_aux;
                        }
                        //line = SZ;
                    }
                        
        
        //While que recorre las filas o culumnas hasta encontrar el numero usando de referencia el max
        // y encontre el patron -/+ entre los cuadrantes del anillo, dependiendo el cuadrante se incrementa o decrementa ya sea la linea o la columna
            while (P != max) {
                if(x==1)line--;else
                    if(x==2)column--;else
                        if(x==3)line++;else
                            if(x==4)column++;
                max--;
                
            }


       }//Fin del else P == 1
        
        cout<<"Line = "<<line<<", column = "<<column<<".\n";
        
        
        /* Como ya vi que se pueden ver los codigos, a cualquiera que vea esto, Hola (^-^)/ */
        
    }

return 0;
}
