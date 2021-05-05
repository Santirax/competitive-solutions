#include <iostream>
using namespace std;
int main ()
{
 long double H, U, D, F;
 while(cin>>H && H != 0 && cin>> U && cin>> D && cin>> F && U != 0 && D != 0 && F != 0)
 {
   //cout<<""<<"H = "<<H<<", U = "<<U<<", D = "<<D<<", F = "<<F;
   //cin>>U>>D>>F; 
   long long int day=1;
   long double alt_tot = U;
   long double alt = U;
   F = F/100; 
   long double ftg = U*F;
   int ban = 0;
/*Evaluacion para el dia*/
   //cout<<"alt = "<<alt<<" port ftg = "<<F<<" ftg = "<<ftg<<endl;
   //cout<<"altura total después de un día = "<<alt_tot<<" alt = "<<alt<<endl; 
   
  if(alt_tot > H)
   { 
    cout<<"success on day "<<day<<endl; ban = 1;
   } else
   if(alt_tot<0)
    {
    cout<<"failure on day "<<day<<endl; ban = 1;
    }   else{

           alt_tot = alt_tot-D; //LO que cae en la noche
            /*Evaluacion para la noche*/
               if(alt_tot > H)
                { 
                 cout<<"success on day "<<day<<endl; ban = 1;
                }
               if(alt_tot < 0)
               {  cout<<"failure on day "<<day<<endl; ban = 1;}
 
       }

   //cout<<"alt_tot después de un día-noche = "<<alt_tot<<endl;

  if(ban == 0)
  while(alt_tot < H || alt_tot > 0)
  {
   day++;
   alt -= ftg;
   if(alt <= 0)
    alt = 0;
   alt_tot += alt;

   //cout<<"altura total después de un día = "<<alt_tot<<" alt = "<<alt<<endl;
   if(alt_tot > H) 
   {
     cout<<"success on day "<<day<<endl;
     break;   
   }
   
   if(alt_tot<0)
   {
      cout<<"failure on day "<<day<<endl;
      break;
   }   

   alt_tot = alt_tot-D; //LO que cae


   /*Evaluacion para la noche*/
   if(alt_tot > H) 
   { cout<<"success on day "<<day<<endl; break;
   }

   if(alt_tot<0)
   {    
    cout<<"failure on day "<<day<<endl; break;
   }

   //cout<<"alt_tot después de un día-noche = "<<alt_tot<<endl;
  }

   alt_tot = 0;
   alt = 0;
   ftg = 0;
   H = 0, U = 0, D= 0, F =0;
 }
//cout<<"\n"; 
return 0;
}
