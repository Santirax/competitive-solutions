#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main ()
{
//const int T = 15000;
const long long int K = 110;

int N;
long double tot = 0;
 
//char cadena[T];
vector<float> pago(K);
vector<char> caracter(K);
string cadena;

cin>>N;

for(int a = 0; a < N; a++)
{
tot=0;//Variable contadora inicializada en 0 por cada iteración completa
int K;
cin>>K;

 for (int x = 0; x<K; x++)
 {
   cin>>caracter[x];
   cin>>pago[x];
 } 


long long int M;
//cout<<"Lineas de la cadena: ";
cin>>M;


for(int x = 0; x<=M; x++)
{
 
 //cin>>cadena;
 getline(cin, cadena);
 //cout<<"Tam = "<<cadena.length();
 for(int y = 0; y<cadena.length(); y++)
 {
   for(int z = 0; z<K; z++)
   {
      if(cadena[y] == caracter[z])
      {
         tot+=pago[z];
      }

   }

 }

}

//cout.setprecision(2);
//cout<<cadena<<endl;

//cout<<"\nPago = "<<tot<<endl;
tot = tot/100;
cout<<fixed;
cout<<setprecision(2)<<tot<<"$\n";


}//FIN del for


 return 0;
}
