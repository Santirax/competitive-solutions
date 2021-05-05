#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 int main ()
{
const int T = 3000;
int N, band=0;
vector<int>n(T);
vector<int>a(T);

while(cin>>N)
{
 for (int x = 0; x<N; x++)
 {
   cin>>n[x];
 }


for (int x = 0; x<N-1; x++)
{
  a[x] = abs(n[x]-n[x+1]);
}


//cout<<"Impresión de abs, pos 0: "<<a[0]<<endl; 



int aux = 0;
for (int x = 0; x< N-2; x++)
{
  for (int y = 0; y < N-2; y++)
  {
     if (a[y]>a[y+1])
     {  
       aux = a[y];
       a[y] = a[y+1];
       a[y+1] = aux;
     }
  }
}



/*cout<<"Arreglo ordenado\n";
for (int x = 0; x < N-1; x++)
cout<<a[x]<<" ";*/



//cout<<"\nTamaño de a = "<<a.size()<<endl;

for (int x = 0, cont=1/*Contador de elementos 1 hasta n-1*/; x<N-1; x++, cont++)
{
   if (a[x]>=1 && a[x]<=N-1 && a[x] == cont)
   {
      band = 0;
   } else
     {
       //cout<<"Entro a 1, a[x] = "<<a[x]<<" y cont = "<<cont<<endl; 
       band = 1;
       break;
     }
}



if (band == 0 || N == 1)//En caso de que sea un solo elemento
{
cout<<"Jolly\n";

} else if (band == 1)
  {
     cout<<"Not jolly\n";
  }

}//Fin del while

return 0;
}