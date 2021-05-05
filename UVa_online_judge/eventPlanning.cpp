#include <iostream>
using namespace std;
int main ()
{

 long long int N, B, H, W, p/*costo hotel avitacion*/, ban = 0/*bandera*/, pres/*presupuesto*/, b/*beds disponibles*/, pres_imp, aux;
 while(cin>>N>>B>>H>>W)
 {
   pres = 0;
   pres_imp = 0;
   ban = 0;
   p = 0;
   b = 0;
   pres_imp = 500001;
   for(int x = 0; x< H; x++)//H 10
   {
     cin>>p; //7794
     for(int y = 0; y < W; y++)
     {
        cin>>b; 
        pres = p*N;
        if (b >= N)
          if(pres<=B)
             {
              ban = 1;  
              if(pres < pres_imp)
              pres_imp = pres;
             }
         //cout<<"x = "<<x<<" pres = "<<pres<<" y B = "<<B<<endl;


        /*if (b < N)
        {
           //ban = 0;
        } else {
           pres = p*N;
           //cout<<"pres = "<<pres<<endl; 
           if(pres<=B)
           {
             ban = 1;
             //break;
           } else
              {
                 //ban = 0;
              }
           
        }*/
 
     }//fin del for y
   }//fin del for x
 
  if(ban == 1)
    cout<<pres_imp<<endl;
      else if(ban == 0)
        cout<<"stay home"<<endl;

 }

return 0; 
}
