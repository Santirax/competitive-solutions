#include <iostream>

using namespace std;

int main()
{
    int T, aux;
    int sal1, sal2, sal3;
    cin>>T;
    for (int x=1; x<=T; x++)
    {
        cin>>sal1>>sal2>>sal3;
        if(sal1 > sal2 && sal1 > sal3)
        {
         if(sal2 > sal3)
            aux = sal2;
             else 
              aux = sal3;
       
        }else 
           if(sal2 > sal1 && sal2 > sal3)
           {
       
            if(sal1 > sal3)
             aux = sal1;
              else 
               aux = sal3;
       
           } else
               if(sal3 > sal1 && sal3 > sal2)
               {
                 if(sal1 > sal2)
                   aux = sal1;
                     else 
                        aux = sal2;
               } 
         
       cout<<"Case "<<x<<": "<<aux<<"\n"; 
    }

    return 0;
}
