#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
    
    vector < pair<int, int> > query; //Vector que va a simular la cola de prioridad
    pair <int, int> par; //Par de numeros, que representa el ID de la query y su periodo de tiempo
    int ID; //ID del registro
    int period; //Periodo del registro
    string inutil; //Una string que solo sirve para joder xD
    while (cin>>inutil && inutil != "#") //Leo los registros hasta que sea el caracter #
    {
        cin>>ID;
        cin>>period; //Leer el ID y el periodo del registro
        par = make_pair(ID, period); //Hacer el par de por registro
        query.push_back(par); //Meterlos al vector
    }
    sort(query.begin(), query.end()); //Hago un sort simulando una priority_queue inversa, y lo chido del asusnto es que solo organiza el primer valor del pair, que es lo que quiero
    //cout<<"Arreglo ordenado\n";
    int K = 0;
    cin>>K;
    //Leo las consultas que me piden
    
    
    int cont = 0; //Llevo un contador por consultas
    
    for (int i = 1; cont < K; i++) //Esto simula el tiempo que trancurre
    {
        for(int j = 0; j < query.size() && cont < K; j++) //Por cad segundo de tiempo evaluo todo mi arreglo
        {
            if(i % query[j].second == 0){ //Si i (tiempo) % periodo (query[j].second) == 0 es una consulta valida e imprimo su ID (query[j].first).
                cout<<query[j].first<<endl;
                cont++; //Aumento el contador de consultas
            }
        }
        
    }
    return 0;
}
