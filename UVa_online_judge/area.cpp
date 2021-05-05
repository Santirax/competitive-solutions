#include <iostream>
using namespace std;

typedef long long int lli;
const lli MAX = 1000;
lli area[MAX][MAX];

lli query(int iniI, int finI, int iniJ, int finJ)
{
    return area[finI][finJ] - area[iniI-1][finJ] - area[finI][iniJ-1] + area[iniI-1][iniJ-1];
}


int main ()
{
    int T, M, N, D, caso = 1;
    cin>>T;
    //Por el numero de casos
    for(int x = 0; x < T; x++){
        //Escaneamos las dimensiones de la matriz y el cash que tenemos
        cin>>N>>M>>D;
        //Ingresamos la matriz
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cin>>area[i][j];
            }
        }

        //A esta tecnica se le llama suma de acumulados
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                area[i][j] += area[i][j-1];
            }
            for(int j = 1; j <= M; j++){
                area[i][j] += area[i-1][j];
            }
        }


        //Aqui fijamos todas la posibles areas horizontales, para hacer el barrido
        lli areas = 0, minCost = 1e9;
        for(int i = 1; i <= N; i++){
            for(int j = i; j <= N; j++){
              lli areaTemp = 0, coste = 0;
                for(int k = 1, l = 1; l <= M; l++){
                    coste += query(i, j, l, l);
                    while(k <= l && coste > D)
                      coste-=query(i, j, k, k), k++;

                    areaTemp = (j-i+1)*(l-k+1);
                    if(areaTemp > areas  || (areaTemp == areas && coste < minCost))
                      areas = areaTemp, minCost = coste;

                }
            }
        }

        cout<<"Case #"<<caso++<<": "<<areas<<" "<<minCost<<"\n";
        //Impresion
        /*cout<<endl;
        cout<<"Impresion de la matriz:\n";
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cout<<area[i][j]<<" ";
            }
            cout<<"\n";
        }*/

    }

    return 0;
}
