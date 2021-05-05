#include <iostream>
using namespace std;
int main ()
{
 long long int N;
 string pos, posAct="+x";
 while(cin>>N && N != 0)
 {


   /*Punto de incio*/

   long long int ini = N-1;
 
      for(int x = 1; x<=ini; x++)
      {
        cin.ignore();
        //getline(cin, pos);
        cin>>pos;
        //cout<<"posición Act = "<<posAct<<" y la pos = "<<pos<<endl;
         //posAct = pos;
      if (x==1) 
      {
        if(pos == "No")
        {
          posAct = "+x";
        }else 
        if(pos == "+y")
        {
           posAct = "+y";
        }else
        if(pos == "-y")
        {
           posAct = "-y";
        }else
        if(pos == "+z")
        {
           posAct = "+z";
        }else
        if(pos == "-z")
        {
           posAct = "-z";
        }
      }else {
         
          if(posAct == "+x")
          {
             if(pos == "No")
             {
               posAct = "+x";
             }else 
             if(pos == "+y")
             {
               posAct = "+y";
             }else
             if(pos == "-y")
             {
               posAct = "-y";
             }else
             if(pos == "+z")
             {
                posAct = "+z";
             }else
             if(pos == "-z")
             {
              posAct = "-z";
             }
          }else
          if(posAct == "-x")
          {
             if(pos == "No")
             {
               posAct = "-x";
             }else              
             if(pos == "+y")
             {
               posAct = "-y";
             }else
             if(pos == "-y")
             {
               posAct = "+y";
             }else
             if(pos == "+z")
             {
                posAct = "-z";
             }else
             if(pos == "-z")
             {
              posAct = "+z";
             }

          }else
          if(posAct == "+y")
          {
             if(pos == "No")
             {
               posAct = "+y";
             }else 
             if(pos == "+y")
             {
               posAct = "-x";
             }else
             if(pos == "-y")
             {
               posAct = "+x";
             }else
             if(pos == "+z")
             {
                posAct = "+y";
             }else
             if(pos == "-z")
             {
              posAct = "+y";
             }

          }else
          if(posAct == "-y")
          {
             if(pos == "No")
             {
               posAct = "-y";
             }else 
             if(pos == "+y")
             {
               posAct = "+x";
             }else
             if(pos == "-y")
             {
               posAct = "-x";
             }else
             if(pos == "+z")
             {
                posAct = "-y";
             }else
             if(pos == "-z")
             {
              posAct = "-y";
             }

          }else
          if(posAct == "+z")
          {
             if(pos == "No")
             {
               posAct = "+z";
             }else 
             if(pos == "+y")
             {
               posAct = "+z";
             }else
             if(pos == "-y")
             {
               posAct = "+z";
             }else
             if(pos == "+z")
             {
                posAct = "-x";
             }else
             if(pos == "-z")
             {
              posAct = "+x";
             }
          }else 
          if(posAct == "-z")
          {
             if(pos == "No")
             {
               posAct = "-z";
             }else 
             if(pos == "+y")
             {
               posAct = "-z";
             }else
             if(pos == "-y")
             {
               posAct = "-z";
             }else
             if(pos == "+z")
             {
                posAct = "+x";
             }else
             if(pos == "-z")
             {
              posAct = "-x";
             }
          }


       }//fin del else


     }//fin for
       
cout<<posAct<<"\n";

 }//fin while


return 0;
}
