#include <bits/stdc++.h>
#define m_inf -1e9;
using namespace std;
int a, b, c;

vector<int>DP(4010, -1);

//Casos de la DP

//Si el listo es de tamaño 0 ya no existe liston que cortar entonces el liston mas largo es de cero
//Si el liston es negativo es un absurdo, quiere decir que no es un corte valido y se regresa menos infinito
//Tenemos un arreglo donde guardamos resultados previos de N
//Si no lo tenemos calculado hay que calcularlo, con el maximo de hacer los cortes con (a, b, c) + 1
//El mas uno es del corte que hicimos y guardamos el resultado de esa n en el arreglo de la DP
//El analisis completo esta en las fotos del iPhone
int maxCut (int n){
 if(n == 0)return 0;
 if(n < 0)return m_inf;
 if(DP[n] != -1)return DP[n];
 return DP[n] = max( maxCut(n-a), max( maxCut(n-b), maxCut(n-c) ) )+1;
}

int main (){
 int n;
 cin>>n>>a>>b>>c;
 int res = maxCut(n);
 cout<<res<<"\n";

 return 0;
}
