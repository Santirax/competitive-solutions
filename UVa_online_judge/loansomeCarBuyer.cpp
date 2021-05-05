#include <iostream>
//#include <iomanip>
#include <vector>
using namespace std;
int main ()
{

    long double meses, inicial, prestamo, depreciaciones, /*mes[100], depre[100],*/ deuda, valor_car;
    int mes_cont;
    int anterior;
    
 

 while(cin>>meses && cin>>inicial && cin>>prestamo && cin>>depreciaciones && meses > 0)
 {
     //out<<fixed;
     //cout<<setprecision(7);
     vector<long double>mes(200);
     vector<long double>depre(200);
     
     valor_car = prestamo+inicial;

   for(int x = 0; x<depreciaciones; x++)
   {
     cin>>mes[x]; //0-0,  1-1,  2-3
     cin>>depre[x]; //0 - .10,  1-.03, 2 - .002
       //cout<<mes[x]<<" y "<<depre[x]<<endl;
   }
     
     
     
     /*MES 0*/
      long double conDepre =valor_car*depre[0];
     
     valor_car = valor_car-conDepre;
     
     deuda = prestamo;
     
     mes_cont = 0;
     
      double mensualidad = prestamo/meses;
     
     //cout<<"Valor carro mes 0 = "<<valor_car<<endl;
     
     mes_cont = 0;
     
     int cont_aux = 1;
     anterior = 0;
     /*Empezando en mes 1*/
     while(deuda > valor_car)
     {
         
         mes_cont++;
         if(mes_cont == mes[cont_aux])
         {
             conDepre = valor_car*depre[cont_aux];
             //cout<<"POrcetnaje de depre (==) = "<<depre[cont_aux]<<endl;
             anterior = cont_aux;
             cont_aux++;
         } else {
             conDepre = valor_car*depre[anterior];
             //cout<<"POrcetnaje de depre (!=) = "<<depre[anterior]<<endl;
         }
         //cout<<"Depreciacion: "<<conDepre<<"x mes: "<<mes_cont<<endl;
         valor_car = valor_car-conDepre;
         deuda = deuda-mensualidad;
         //cout<<"Valor carro = "<<valor_car<<endl;
         //cout<<"Deuda = "<<deuda<<endl;
         //conDepre=0;
     }//fin del while
    
     if(mes_cont == 1)
     {
         cout<<mes_cont<<" month\n";
     } else
       {
           cout<<mes_cont<<" months\n";
       }
 }



return 0;
}
