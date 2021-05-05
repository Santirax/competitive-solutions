#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int main ()
{
    
    cout<<fixed;
    cout.precision(4);//Ajustamos el cout para las especificaciones del problema
    int N;
    cin>>N; //Casos de prueba
    cin.ignore();
    cin.ignore(); //Ignoramos los dos saltos de linea
    for(int i = 0; i<N; i++) //Empezamos con los casos
    {
        string especie; //Una string para guardar las especies
        map <string, float> especies; //Un map que por cada especie tenga su numero de repeticiones
        set <string> auxEspecies; //UN set con el unico proopsito que este ordenada la salida xD
        set <string>::iterator itINI, itFIN; //Unos confiables iterators para la impresion
        int con = 0; //Un contador del numero total de especies
        while (getline(cin, especie) && especie != "\0") {//Lectura de cadena hasta que exista la cadena vacia, nuevo caso
            con++; //Por cada arbol aumentamos la cantidad de arboles xD
            auxEspecies.insert(especie); //E insertamos el arbol en el set, que nos garantiza dos cosas, que los arboles van a estar ordenados y no se van a repetir
            especies[especie] += 1; //Aqui lo unico que hacemos es un acumulado por especie de arbol;
            //especies[especie] = especies[especie] + 1; acumuladoPorKey, que es el nombre del arbol(int) = int + 1
            //cout<<especies[especie]<<endl;
        }
        
        //Aqui lo unico que se hace es la impresion
        for(itINI = auxEspecies.begin(), itFIN = auxEspecies.end(); itINI != itFIN; itINI++)
        {
            //Se imprime la especie en el set (*itINI) depues se accede al valor numerico (numero de arboles por especies que existen) del map mediante la llave (string especie que esta en el set) y solo se hace una regla de tres, sencillo
            cout<<*itINI<<" "<<(especies[(*itINI)]*100.0)/con<<"\n";
        }
        
        //Esto solo es para corregir la odiosa salida xD
        if(i != N-1)
            cout<<"\n";
    }
    
    return 0;
}
